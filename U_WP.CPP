#include "MACROS.CPP"

void about_wp()
{
	clrscr();
	cout << "   -------------------------- WORD PROCESSOR -----------------------------------\n\n"
		<< "\tWORD PROCESSOR is a product of the OSCorp Corporation.\n"
		<< "\tAny attempt to copy the copyrighted products eg. the functional\n"
		<< "\talgorithms, or the functional technique is liable to punishable offence.\t"
		<< "\n\tAll rights reserved."
		<< "\n\n\tThis product is licensed under the OSCorp Software License Terms"
		<< "\n\tto the product owner.";
	GETCH_MSG;
		getch();
}

void read()
{
	char name[20];
	CHECK:;
	cout << "\nEnter the name of the file:\t"; cin >> name;
	ifstream file(name);
		if(file.bad())
		{
			file.close();
			cout << "\nError: No such file was found!\nPlease check the name of the file you entered!\n";
			ASK:;
			cout << "\n\nDo you want to enter a new name to the file? [y/n]\nPlease enter a choice:\t";
				switch(getche())
				{
					case 'y': { goto CHECK; }
					case 'n': { return; }
					default: { cout << "\nError: Wrong choice entered! Please enter a valid input!"; sleep(1); goto ASK; }
				}
		}
		else
		{
			file.seekg(0, ios::beg);
			char ch; int spaces=0, lines=0, characters=0, check_lines=1;
			cout << "\n\n--------------------The contents of the file are:---------------------------\n";
			while(file)
			{
				file.get(ch);
				cout.put(ch);
				characters++;
				if(ch==' ')
					spaces++;
				if(ch=='\n')
					{ lines++; check_lines++; }
				if(check_lines%20==0)
					{
					check_lines++;
					cout << "\n\n";
					gotoxy(1, 25);
					textcolor(BLUE);
					//textbackground(WHITE);
					cprintf("\n\t----------Press any key to continue---------------\t");
					textcolor(WHITE);
					cout << "\n\n";
					getch();
					}
			}
			cout << "\n";
			textcolor(YELLOW);
			cprintf("\t------------------------- END OF FILE ---------------------------------\t");
			textcolor(WHITE);
			file.seekg(0, ios::end);
			cout << "\n\n[DETAILS: Total number of characters entered: "<< characters
				<< "\nTotal number of spaces entered: "<< spaces
				<< "\nTotal number of lines entered: " << lines
				<< "\n\nTotal size of the current document: "<< file.tellg() << " Byte(s)";
			getch();
		}
	file.close();
}

void write_new()
{
	char name[9];
	cout << "\nEnter the name of the file with extension [maximum 8 characters]:\t"; cin >> name;

	CHECK:;
	ifstream ifile(name);
		if(ifile.bad()==0)
		{
			ifile.close();
			cout << "\nError: A file of the same name already exists!\nPlease either enter an another name for the file or goto menu and select the\noption [4] Overwrite an existing file.\n";
			ASK:;
			cout << "\n\nDo you want to enter a new name to the file? [y/n]\nPlease enter a choice:\t";
				switch(getche())
				{
					case 'y': { cout << "\n\nEnter another name for the file:\t"; cin >> name; goto CHECK; }
					case 'n': { return; }
					default: { cout << "\nError: Wrong choice entered! Please enter a valid input!"; sleep(1); goto ASK; }
				}
		}
	ifile.close();

	cout << "\n\nInstruction: Enter the desired contents of the file. Terminate the writing\nprocess to the file by entereing a \"`\" [tilde] symbol.\n\n"
		<< "Please enter the contents of the file:\n\n---------------------------------------------------------------------------\n";
	char ch; int spaces=0, lines=0, characters=0;
	ofstream file(name);
		do
		{
			cin.get(ch);
			if(ch!='`')
				file << ch;
			 
			if(ch!='`')
				characters++;
			if(ch==' ')
				spaces++;
			if(ch=='\n')
				lines++;
		}
		while(ch!='`');
		cout << "\n---------------------File writing terminated!-------------------------------"
			<< "\n\n[DETAILS: Total number of characters entered: "<< characters
				<< "\nTotal number of spaces entered: "<< spaces
				<< "\nTotal number of lines entered: " << lines
				<< "\n\nTotal size of the current document: "<< file.tellp() << " Byte(s)";
		getch();
	file.close();
	return;
}

void append()
{
	char name[20];
	cout << "\nEnter the name of the file:\t"; cin >> name;
	CHECK:;
	ifstream ifile(name);
		if(ifile.bad()!=0)
		{
			ifile.close();
			cout << "\n\nError: No such file exists!\nPlease either enter the name of the file correctly or goto menu and select\na proper option.";
			ASK:;
			cout << "\n\nDo you want to enter the name of the file again? [y/n]\nPlease enter a choice:\t";
				switch(getche())
				{
					case 'y': { cout << "\n\nEnter the name of the file:\t"; cin >> name; goto CHECK; break; }
					case 'n': { return; }
					default: { cout << "\nError: Wrong choice entered! Please enter a valid input!"; sleep(1); goto ASK; }
				}
		}
	ifile.close();

	cout << "\n\nInstruction: Enter the desired contents of the file. Terminate the writing process to the file by entereing a \"`\" [tilde] symbol.\n\n"
		<< "Please enter the contents of the file:\n\n---------------------------------------------------------------------------\n";
	char ch; int spaces=0, lines=0, characters=0;
	fstream file(name, ios::app);
		do
		{
			cin.get(ch);
			if(ch!='`')
				file << ch;
			
			if(ch!='`')
				characters++;
			if(ch==' ')
				spaces++;
			if(ch=='\n')
				lines++;
		}
		while(ch!='`');
		cout << "\n---------------------File writing terminated!-------------------------------"
			<< "\n\n[DETAILS: Total number of characters entered: "<< characters
				<< "\nTotal number of spaces entered: "<< spaces
				<< "\nTotal number of lines entered: " << lines
				<< "\nTotal size of the current document: "<< file.tellp() << " Byte(s)";
			getch();
	file.close();
	return;
}

void overwrite()
{
	char name[9];
	cout << "\nEnter the name of the file with extension [maximum 8 characters]:  "; cin >> name;

	CHECK:;
	ifstream ifile(name);
		if(ifile.bad()!=0)
		{
			ifile.close();
			cout << "\n\nError: No such file found!\nPlease either enter the correct name of the file or goto menu and select\na proper option.";
			ASK:;
			cout << "\n\nDo you want to enter the name of the file? [y/n]\nPlease enter a choice:\t";
				switch(getche())
				{
					case 'y': { cout << "\nEnter the name of the file:\t"; cin >> name; goto CHECK; break; }
					case 'n': { return; }
					default: { cout << "\n\nError: Wrong choice entered! Please enter a valid input!"; sleep(1); goto ASK; }
				}
		}
	ifile.close();

	cout << "\n\nInstruction: Enter the desired contents of the file. Terminate the writing process to the file by entereing a \"`\" [tilde] symbol.\n\n"
		<< "Please enter the contents of the file:\n\n---------------------------------------------------------------------------\n";
	char ch; int spaces=0, lines=0, characters=0;
	ofstream file(name);
		do
		{
			cin.get(ch);
			if(ch!='`')
				file << ch;
			 
			if(ch!='`')
				characters++;
			if(ch==' ')
				spaces++;
			if(ch=='\n')
				lines++;
		}
		while(ch!='`');
		cout << "\n---------------------File writing terminated!-------------------------------"
			<< "\n\n[DETAILS: Total number of characters entered: "<< characters
				<< "\nTotal number of spaces entered: "<< spaces
				<< "\nTotal number of lines entered: " << lines
				<< "\nTotal size of the current document: "<< file.tellp() << " Byte(s)";
			getch();
	file.close();
	return;

}

void copy()
{
	char filename[80];
		CHECK:;
		cout << "\n\nEnter source file name:\t";
		cin >> filename;
	ifstream ifile(filename);
		if(ifile.bad()!=0)
		{
			ifile.close();
			cout << "\n\nError: No such file found!\nPlease either enter the correct name of the file or goto menu and select\na proper option.";
			ASK:;
			cout << "\n\nDo you want to enter the name of the file? [y/n]\nPlease enter a choice:\t";
				switch(getche())
				{
					case 'y': { goto CHECK; break; }
					case 'n': { return; }
					default: { cout << "\n\nError: Wrong choice entered! Please enter a valid input!"; sleep(1); goto ASK; }
				}
		}
	ifile.close();
		cout << "\nEnter destination file name:\t";
		char fdest[80];
		cin >> fdest;
		ifstream f(filename);
		ofstream of(fdest);

		cout << "Do you want to view the contents of the file " << filename << "?"
		<< "  [y = Yes, n = No]\nEnter your choice:\t";

		int flag=0;
		switch(getche())
		{
		case 'y': {
			cout << "\n\n------------- Contents of file: " << filename << " : ----------------\n";
			flag=1; break; }
		case 'n': { flag = 0; break;}
		default: { cout << "\nWrong choice entered! Taking response as negative!\n"; break; }
		}


			f.seekg(0, ios::beg);
			of.seekp(0, ios::beg);
			char ch;
			int count=0, space=0, lines=0, count_lines=1;
			while(f)
			{
				f.get(ch);
				if(flag==1)
					cout << ch;
				of << ch;
				count++;
				if(ch==' ')
					space++;
				if(ch=='\n')
					{ count_lines++; lines++; }
				
				if(flag==1)
				{
					if(count_lines%20==0)
					{
					count_lines++;
					gotoxy(1, 25);
					textcolor(BLUE);
					cout << "\n\n";
					//textbackground(WHITE);
					cprintf("\t----------Press any key to continue---------------\t");
					textcolor(WHITE);
					cout << "\n\n";
					getch();
					}
				}
			}
			of.seekp(0, ios::end);
			if(flag==1)
			cout << "\n";
			textcolor(YELLOW);
			cprintf("\t------------------------- END OF FILE ---------------------------------\t");
			textcolor(WHITE);
			
			cout << "\n\n[FILE DETAILS:\n\nNumber of characters:\t" << count
				<< "\nNumber of spaces in the file:\t" << space
				<< "Number of lines in the file:\t" << lines
				<< "\nTotal size of the fle:\t" << of.tellp() <<" Byte(s)]\n\n";
		of.close();
		f.close();
		getch();
		return;
}

void word_processor()
{
	clrscr();

		while(1)
		{
			clrscr();
			cout << "\n\n\t\t-------------- WORD PROCESSOR --------------";
			cout << "\n\n\t[1] Read from an existing file";
			cout << "\n\t[2] Write to a new file";
			cout << "\n\t[3] Append to an existing file";
			cout << "\n\t[4] Overwrite an existing file";
			cout << "\n\t[5] Copy from one file to another";
			cout << "\n\t[6] About WORD PROCESSOR";
			cout << "\n\t[7] Exit the program";
			cout << "\n\nEnter your choice:\t";

			switch(getche())
			{
				case '1': read(); break;
				case '2': write_new(); break;
				case '3': append(); break;
				case '4': overwrite(); break;
				case '5': copy(); break;
				case '6': about_wp(); break;
				case '7': return;
				default: cerr << "\nWrong entry! Please try again...\n";
			}
		}
}