//DICTIONARY APPLICATION

#include "MACROS.CPP"

#define WL "wlist.db"
#define ML "mlist.db"

void dic_about()
{
	clrscr();
	cout << "-------------------------------  DICTIONARY  -----------------------------------\n\n"
		<< "\tDICTIONARY is a product of the OSCorp Corporation.\n"
		<< "\tAny attempt to copy the copyrighted products eg. the functional\n"
		<< "\talgorithms, or the functional technique is liable to punishable offence.\t"
		<< "\n\tAll rights reserved."
		<< "\n\n\tThis product is licensed under the OSCorp Software License Terms"
		<< "\n\tto the product owner.";
	GETCH_MSG;
		getch();
}

class DB
{
	char *word;
	char *meaning;
public:
	DB();
	void write();
	void read();
	void read_full();
	void clear_db();

};

void DB::clear_db()
{
	ifstream file(ML);
	file.seekg(0, ios::end);
	int size=file.tellg();
	file.close();

	while(1)
	{
	clrscr();
	cout << "\nAre you sure to clean up the entire Dictionary database?\n"
		<< "\t[Size of Dictionary database:\t"<< size <<" Byte(s)]\n"
		<< "\n\n[Press 'y' for Yes and 'n' for No]\n"
		<< "Your choice:\t";

	switch(getche())
	{
	case 'y':
		{
		if(size==0)
		{
			cout << "\n\nError: Dictionary Database is already empty! [Size = 0 Byte]\n";
			GETCH_MSG;
			getch();
			return;
		}

		ofstream filew(WL);
		ofstream filem(ML);
		filew.close();
		filem.close();
		cout << "\n\nDatabase cleared! Current Database size: 0 Byte";
		GETCH_MSG;
		getch();
		return;
		}
	case 'n': {return;}
	default:
		{
			cout << "\nError: Wrong input entered! Please try again!\n\n";
			GETCH_MSG;
			getch();
		}
	}
	}
}

void DB::read_full()
{
	clrscr();
	ifstream file(ML);
	file.seekg(0, ios::end);
	if(file.tellg()==0)
	{
		cout << "\n\nError: Dictionary Database is empty!\n";
		GETCH_MSG;
			getch();
			return;

	}
	cout << "----------The contents of the dictionary are:-------------\n\n";
	file.seekg(0, ios::beg);
	char ch;
		while(file.eof()==0)
		{
			file.get(ch);
			cout.put(ch);
		}
	cout << "\n\n--------------End of the Dictionary Database!-------------";
	GETCH_MSG;
	getch();
	file.close();
	return;
}

DB::DB()
{
	fstream filew(WL, ios::app);
	fstream filem(ML, ios::app);
	filew.close();
	filem.close();
}

void DB::read()
{
	char query[80];
	while(1)
	{
	clrscr();
	cout << "\nEnter the word:\t";
	cin.getline(query, 80);
	if(strcmp(query, "")==0)
	{
	cout << "\nError: Please enter a non-null input.";
	GETCH_MSG;
	getch();
	}
	else
	break;
	}
	int len=(strlen(query)+1);   int pos=0;
	ifstream ifile(ML);
		ifile.seekg(0, ios::beg);
		char temp[200];
		while(ifile.eof()==0)
		{       pos=ifile.tellg();
			ifile.getline(temp, 200);
			if(strncmp(query, temp, len)==0)
			{
				ifile.seekg(pos, ios::beg);
				//ifile.getline(temp, 200);
				cout << "\n\n[ Word : Meaning ]\n";
				char ch;
				do
				{
				ifile.get(ch);
				cout.put(ch);
				}while(ch!='\n');
				GETCH_MSG;
				getch();
				return;
				}
		}

	cout << "\n\nWord is not present in the Database!"; GETCH_MSG;
	getch();
	return;
}

void DB::write()
{
	clrscr();
	cout << "\nEnter the word:\t";
	char *temp;
	cin.getline(temp, 80);
	word = new char[strlen(temp)+1];
	strcpy(word, temp);
	cout << "Enter the meaning:\t";
	cin.getline(temp, 200);
	meaning = new char[strlen(temp)+1];
	strcpy(meaning, temp);
	//Checking for duplicacy
	fstream filew(WL, ios::app);
	ifstream file(WL);
	file.seekg(0, ios::beg);
	file.getline(temp, 80);           //cout << "\nword: " << word << "  temp: " << temp << endl;  int i=0;
	while(file.eof()==0)
	{                   //cout << "\nRound: " << i++;
	if(strcmp(temp, word)==0)
	{
		cout << "\nError: Word is already present in the database!"; GETCH_MSG;
		file.close();
		filew.close();
		getch();
		return;
	}
	else
	{
		file.getline(temp, 80);
	}
	}
	fstream filem(ML, ios::app);
		filew.seekp(0, ios::end);
		filem.seekp(0, ios::end);
		filew.write(word, (strlen(word)+1)); filew << endl;
		filem.write(word, (strlen(word)+1)); filem << ":\t";
		filem.write(meaning, (strlen(meaning)+1)); filem << endl;
		cout << "\n\tSuccessfully entered into the database!\n";
		GETCH_MSG;
		getch();

	filew.close();
	filem.close();
	return;
}



void dictionary()
{
	DB dic;
	while(1)
	{       clrscr();
		cout << "\n----------------------- Welcome to DICTIONARY -------------------------------\n\n"
			<< "1. Enter in Dictionary database\n"
			<< "2. Search Dictionary for word meaning\n"
			<< "3. Read entire Dictionary database\n"
			<< "4. Clear Dictionary database\n"
			<< "5. About Dictionary.EXE\n"
			<< "6. Exit program\n\n"
			<< "Enter your choice:\t";

		switch(getche())
		{
			case '1': { dic.write(); break; }
			case '2': { dic.read(); break;}
			case '3': { dic.read_full(); break; }
			case '4': { dic.clear_db(); break; }
			case '5': { dic_about(); break; }
			case '6': return;
			default: {cout << "\nSorry! Wrong input entered! Please try again!"; sleep(2); }
		}
	}
}