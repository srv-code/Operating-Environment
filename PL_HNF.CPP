//Header Files, Macros, Datatypes Declarations, Functions Declarations

/*******HEADER FILES DECLARATIONS*******/
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "U_DIC.CPP"
#include "U_WP.CPP"
#include "U_CALC.CPP"
#include "U_ENCDEC.CPP"
#include "MACROS.CPP"

/*******DATATYPE DECLARATIONS*******/
int flag=1;



/********FORWARD DECLARATIONS OF FUNCTIONS********/
void maintain_logfile(int status, int acc);
int check(char);
void menu_view_date_time();
void menu_utilities();
void menu_about();
void log_out(int);


					
void log_out(int acc)			//Logging out function | Provided details: User Type, System date and time
{
	fstream file(FILE_LOG, ios::app);
		file << "\n\nLogging out details:\n"
			<< "User Type:\t";
			if (acc==1)
			{
				file << "Administrator\n";
			}
			else
			{
				file << "Guest\n";
			}
			
			struct time t;
			struct date d;
			gettime(&t); getdate(&d);
			file << "Date:\t" << int(d.da_day) 
			<< "/" << int(d.da_mon)
			<< "/" << int(d.da_year)
			<< "\nTime:\t" << (int)t.ti_hour
			<< " : " << (int)t.ti_min << " : "
			<< (int)t.ti_sec;  		
		
			cout << "\n\n";
	file.close();
	return;
}
					
void menu_utilities()		//Menu Utilities options
{
TRY_AGAIN:;

	clrscr();
	cout << "\n\t\t::::::::::::::::: UTILITIES MENU :::::::::::::::::::::\n"
		<<  "\n\t[a] Word Processor"
			"\n\t[b] Calculator"
			"\n\t[c] Dictionary"
			"\n\t[d] Encrypter-Decrypter"
			"\n\t[e] Exit Utilities"
			<< "\n\nEnter your choice:\t";
	switch(getche())
	{
		case 'a': { word_processor(); break; }
		case 'b': { calculator(); break; }
		case 'c': { dictionary(); break; }
		case 'd': { encrypter_decrypter(); break; }
		case 'e': { return; }
		default: { cout << "\nError: Wrong choice! Please try again..."; sleep(1); goto TRY_AGAIN; }
	}
	
	goto TRY_AGAIN;

}

void menu_view_date_time()     //Showing Current System Date and Time 
{
	clrscr();
	struct time t;
	struct date d;
	gettime(&t); getdate(&d);
	cout << "\n\n\nCurrent System Date:\t" << int(d.da_day) 
			<< "/" << int(d.da_mon)
			<< "/" << int(d.da_year)
			<< "\n\nCurrent System Time:\t" << (int)t.ti_hour
			<< " : " << (int)t.ti_min << " : "
			<< (int)t.ti_sec;  				  
	GETCH_MSG;
	getch();

}

void menu_about()       //About OE
{
	clrscr();
	LABEL;
	cout << "\t\t*********** ABOUT OSCORP OPERATING ENVIRONMENT **********\n\n"
		<< "\tOSCORP OPERATING ENVVIRONMENT is a product of the\n"
		<< "\tOSCorp Corporation. Any attempt to copy the copyrighted products\n"
		<< "\t eg. the functional algorithms, or techniques is liable to \t"
		<< "\n\tpunishable offence.\n\tAll rights reserved."
		<< "\n\n\tThis product is licensed under the OSCorp Software License Terms"
		<< "\n\tto the product owner.";
		GETCH_MSG;
		getch();
}


class fun							//Main function class definition
{
	char username[40], pwd[40];
public:
	fun();
	void start_screen();
	void admin_acc();
	void guest_acc();
	void menu(int);
	int login_screen();
	void menu_privileged_options();
};

void fun::menu_privileged_options()
{
	DISPLAY_AGAIN:;
	clrscr();
	
	cout << "\t\t********WELCOME TO YOUR PRIVILEGED OPTIONS********\n"
	<< "\n\t[a] View credentials"
	<< "\n\t[b] Change credentials"
	<< "\n\t[c] Remove credentials"
	<< "\n\t[d] View log"
	<< "\n\t[e] Clear log"
	<< "\n\t[f] Exit"
	<< "\n\nEnter Choice:\t";
	switch(getche())
	{
		case 'a': 		//View credentials
			{
				ifstream file(FILE_CREDENTIALS);
				file.seekg(0, ios::end);
				if (file.tellg()<2)
				{
					cout << "\n\tError: No credentials have been set yet!";
					file.close();
					sleep(2);
					goto DISPLAY_AGAIN; 
				}
				file.seekg(0, ios::beg);
				char line[40];
				file.getline(line,40);
				cout << "\n\n\tCurrent credentials for Admin Account:\n\t\tUsername:\t" << line;
				file.getline(line, 80);
				cout << "\n\t\tPassword:\t" << line << "\n\n";
				file.close();
				GETCH_MSG;
				getch();
				goto DISPLAY_AGAIN;
				break;
			}
			
		case 'b':		//Change credentials
			{
				char u[40], p[2][40], ch;
				START_AGAIN:
				cout << "\n\nChanging Credentials:";
				fstream file(FILE_CREDENTIALS, ios::app);
				file.seekg(0, ios::end);
				if(file.tellg()<2)
				{
					cout << "\n\nNo credentials were set previously!\n";
					file.close();
				}
				else
				{
					file.close();
					TRY_AGAIN_FOR_USERNAME2:;
					cout << "\n\tNote : Username and Password should be within 6 to 40 characters\n\twide and should only contain characters between 0-9, a-z, A-Z and\n\tunderscores. No other symbols are allowed including space also.\n\n";
					cout << "\n\nEnter old Username:\t"; cin >> u;
					if (strlen(u)<6 || strlen(u)>40)      //Checking for valid username length
					{
						cout << "\n\n\t Error: Username should be within 6 to 40 characters.\n\tPlease try again...\n";
						//sleep(2);
						goto TRY_AGAIN_FOR_USERNAME2;
					}
		
					TRY_AGAIN_FOR_PASSWORD2:;
					cout << "Enter old Password:\t";

					for(int i=0; i<40; i++)
					{
						ch=getch();

						if(check(ch)==1)             //Checking for each valid keystrokes
						break; //ENTER entered!
						
						p[0][i]=ch;
						
						cout << '*';
					}
					p[0][i]=0;
			
					if (strlen(p[0])<6 || strlen(p[0])>40)      //Checking for valid password length
					{
						cout << "\n\n\tError: Password should be within 6 to 40 characters.\n\tPlease try again...\n\n";
						sleep(2);
						goto TRY_AGAIN_FOR_PASSWORD2;
					}
					//cout << "\nUsername: " << username << "\nPassword: " << pwd;

					if (strcmp(u, username)!=0 && strcmp(p[0], pwd)!=0)
					{
						cout << "\n\nError: Wrong username and password combination! Please try again...";
						sleep(2);
						goto START_AGAIN;
					}
				}
				
				
				TRY_AGAIN_FOR_USERNAME3:;
					cout << "\n\tNote : Username and Password should be within 6 to 40 characters\n\twide and should only contain characters between 0-9, a-z, A-Z and\n\tunderscores. No other symbols are allowed including space also.\n\n";
					cout << "\n\nEnter new Username:\t"; cin >> u;
					if (strlen(u)<6)      //Checking for valid username length
					{
						cout << "\n\n\t Error: Username should be within 6 to 40 characters.\n\tPlease try again...\n";
						sleep(2);
						goto TRY_AGAIN_FOR_USERNAME3;
					}
					
					
					ENTER_PWD_TWICE:;
					for(int cp=0; cp<2; cp++)
					{
						TRY_AGAIN_FOR_PASSWORD3:;
						if (cp==0)
							cout << "\nEnter new Password:\t\t";
						else
							cout << "\nEnter new Password again:\t";

						for(int i=0; i<40; i++)
						{
							ch=getch();

							if(check(ch)==1)             //Checking for each valid keystrokes
							break; //ENTER entered!
					
							p[cp][i]=ch;
							cout << '*';
						}
						p[cp][i]=0;

						if (strlen(p[cp])<6 || strlen(p[cp])>40)      //Checking for valid password length
						{
							cout << "\n\n\t Error: Password should be within 6 to 40 characters.\n\tPlease try again...\n\n";
							sleep(2);
							goto TRY_AGAIN_FOR_PASSWORD3;
						}
					}


					if (strcmp(p[0], p[1])!=0)
					{
						cout << "\n\nError: Passwords did not matched! Please try again!\n";
						sleep(2);
						goto ENTER_PWD_TWICE;
					}

					ofstream file_cred(FILE_CREDENTIALS);
						file_cred << u << endl << p[0];
					file_cred.close();
					cout << "\n\nSuccess: Credentials saved successfully!";
					strcpy(username, u); strcpy(pwd, p[0]);
					sleep(3);
				break;
			}

		case 'c':		//Remove credentials
			{
				fstream file(FILE_CREDENTIALS, ios::app);
					file.seekg(0, ios::end);
					if (file.tellg()<2)
					{
						file.close(); cout << "\n\nError: Credentials are already empty!\n"; sleep(3); goto DISPLAY_AGAIN; 
					}
				file.close();
				
				TRY_AGAIN_TO_REMOVE_CREDENTIALS:;
				cout << "\n\nRemove credentials Confirmation:\n\tAre you sure to remove your credentials? [ 'y'=Yes and 'n'=No ]\nEnter your choice:\t";
				switch(getche())
				{
					case 'y': 
					{ 
						ofstream file(FILE_CREDENTIALS);
						file.close();
						cout << "\n\nCredentials removed successfully!";
						sleep(3);
						goto DISPLAY_AGAIN;
					}
					case 'n': goto DISPLAY_AGAIN;
					default: { cout << "\n\nWrong Choice entered! Please try again...\n\n"; sleep(2); goto TRY_AGAIN_TO_REMOVE_CREDENTIALS; }
				}
				break;
			}
		case 'd':		//View log
			{
				
				char ch; int count=1;
				ifstream file(FILE_LOG);
				file.seekg(0, ios::end);
				if(file.tellg()<2)
				{
					cout << "\n\n\tError: Log is empty!\n\tIt needs to be created first before you\n\tcould see the contents in it! Please exit for now and\n\tread it afterwards.\n\n";
					goto DISPLAY_AGAIN;
				}
				
				cout << "\n\n";
				textcolor(YELLOW);
				cprintf("\t----------Contents of log file---------------\t");
				textcolor(WHITE);
				cout << "\n\n";
				
				file.seekg(0, ios::beg);
				int x_pos, y_pos;
					while(!file.eof())
					{
						file.get(ch);
						cout.put(ch);
						if(ch=='\n')
							count++;
						if (count%10==0)
						{
							textcolor(BLUE);  
							cout << "\n\n";
							//x_pos=wherex(); y_pos=wherey();
							gotoxy(5,25);
							cprintf("\t----------Press any key to continue reading---------------\t");
							textcolor(WHITE);
							cout << "\n\n";
							//gotoxy(x_pos,y_pos);
							count++;
							getch();
						}
					}
				file.close();
				cout << "\n\n";
				textcolor(YELLOW);
				cprintf("\t----------End of file | Press any key to continue---------------\t");
				textcolor(WHITE);
				
				
				/*fstream file(FILE_LOG, ios::app, ios::in);
					char ch; int count = 1;
					file.seekg(0, ios::beg);
					while(!file.eof())
					{
						file.get(ch); cout << ch; count++;
						if(count%90==0)
						getch();
					}
				file.close(); cout << "\n\nEnd!";
				*/
				getch();
				goto DISPLAY_AGAIN;
				break;
			}
			
		case 'e':  //Clear log file
			{
				TRY_AGAIN_TO_REMOVE_LOG:;
				cout << "\n\nRemove Log File Confirmation:\n\tAre you sure to remove the log created so far by the system?\n\t[ 'y'=Yes and 'n'=No ]\nEnter your choice:\t";
				switch(getche())
				{
					case 'y': 
					{ 
						ofstream file(FILE_LOG);
						file.close();
						cout << "\n\nLog file cleared successfully!";
						sleep(3);
						goto DISPLAY_AGAIN;
					}
					case 'n': goto DISPLAY_AGAIN;
					default: { cout << "\n\nWrong Choice entered! Please try again...\n\n"; sleep(2); goto TRY_AGAIN_TO_REMOVE_LOG; }
				}
				break;
			}
		case 'f': return;
		default: { CHOICE_ERROR; sleep(2); goto DISPLAY_AGAIN; }
	}
}

fun::fun()				//Constructor used to ensure FILE_CREDENTIALS and FILE_LOG and initialise the username and password class data members 
{

	//clrscr();	cout << "EXECUTING CONSTRUCTOR"; getch();
	fstream log_file(FILE_LOG, ios::app | ios::in);
	fstream cred_file(FILE_CREDENTIALS, ios::app | ios::in);
	
		cred_file.seekg(0, ios::end);
		if(cred_file.tellg()>2)    //FILE_CREDENTIALS is not empty!
		{
			cred_file.seekg(0, ios::beg);
			cred_file.getline(username, 40);
			cred_file.getline(pwd, 40);
			//cout << "\nUsername: " << username << "\nPassword: " << pwd; getch();
		}
	cred_file.close();
	log_file.close();
}



void fun::menu(int acc)     //MENU for both Admin and Guest accounts | acc: 1 = Admin, 0 = Guest 
{
while(1)
{
	clrscr();
	if (acc)
		cout << "\t\t*************** WELCOME TO ADMIN ACCOUNT *****************";
	else
		cout << "\t\t*************** WELCOME TO GUEST ACCOUNT *****************";
	
	
	cout << "\n\n\t[a] View system date and time"
			<< "\n\t[b] Utilities"
			<< "\n\t[c] About OSCorp Operating Environment"
			<< "\n\t[d] Log out";
	if(acc==1)    // 1 = ADMIN ACCOUNT, 2 = GUEST ACCOUNT | Access allowed for prividged options
	{
		cout << "\n\n-----------------------------------------------------";
		cout << "\n\t[e] Privileged options";                  
	}

	cout << "\n\nEnter your choice:\t";
	switch(getche())
	{
		case 'a': { menu_view_date_time(); break; }
		case 'b': { menu_utilities(); break; }
		case 'c': { menu_about(); break; }
		case 'd': { log_out(acc); return; }
		case 'e':
			{
				if(acc==1)
					{ menu_privileged_options(); break; }  	//Access allowed for prividged options
				else
					{ cout << "\nError: Wrong choice! Please try again..."; sleep(1); break; }
			}
		default: { cout << "\nError: Wrong choice! Please try again..."; sleep(1); }
	}
}

}
							//Login Screen
int fun::login_screen()    // 0 = Unsuccessful loggin, 1 = Successfull logging
{
	for(int iii=5; iii>=0; iii--)
	{
		TRY_AGAIN_FOR_USERNAME:;
		clrscr();
		
		char u[40], p[40];
		cout << "\t\tLOGIN SCREEN:\n";
		cout << "\n\n\tNote : Username and Password should be within 6 to 40 characters\n\twide and should only contain characters between 0-9, a-z, A-Z and\n\tunderscores. No other symbols are allowed including space also.\n\n";
		cout << "\n\nEnter Username:\t"; cin >> u;
		if (strlen(u)<6)      //Checking for valid username length
		{
			cout << "\n\n\t Error: Username should be within 6 to 40 characters.\n\tPlease try again...\n";
			sleep(2);
			goto TRY_AGAIN_FOR_USERNAME;
		}

		TRY_AGAIN_FOR_PASSWORD:;
		cout << "Enter Password:\t";

		char ch;
		for(int i=0; i<40; i++)
		{
			ch=getch();

			if(check(ch)==1)             //Checking for each valid keystrokes
				break; //ENTER entered!

			p[i]=ch;
			cout << '*';
		}
		p[i]=0;

		if (strlen(p)<6)      //Checking for valid password length
		{
			cout << "\n\n\t Error: Password should be within 6 to 40 characters.\n\tPlease try again...\n\n";
			sleep(2);
			goto TRY_AGAIN_FOR_PASSWORD;
		}

		//cout << "\nUsername: " << username << "\nPassword: " << pwd;  getch();
		if (strcmp(u, username)==0 && strcmp(p, pwd)==0)   //Successful Logging
		{
				cout << "\n\n\t\tLogging successful!\n\n"; sleep(3);
				maintain_logfile(1, 1);   // Status: 1 = Successful, 0 = Unsuccessful  | Account: 1 = Admin, 0 = Guest
				return 1;
		}
		else											//Unsuccessful Logging
		{
			cout << "\n\nError: Wrong Username and Password combination!\n\n";
			if (iii<2)
					cout << "\nOnly " << iii << " try left.\n";
				else
					cout << "\nOnly " << iii << " tries left.\n";
			sleep(2); 
		}

	}

	return 0;
}

void maintain_logfile(int status, int acc)     //Maintains logfile, Data provided: Login Status, User Type, System Date and Time
												// Status: 1 = Successful, 0 = Unsuccessful  | Account: 1 = Admin, 0 = Guest
{
	fstream logfile(FILE_LOG, ios::app);
		struct time t;
		struct date d;
		gettime(&t); getdate(&d);
		logfile << "\n\n\nLogging in Details:\n"
				<< "Status:\t";
				if (status==1)          //Successful Logging
				{
					logfile << "Successful\n";
				}
				else
				{
					logfile << "Unsuccessful\n";
				}
				
				logfile << "User Type:\t";
				if (acc==1)
				{
					logfile << "Administrator";
				}
				else
				{
					logfile << "Guest";
				}
				logfile << "\nDate:\t" << int(d.da_day) 
				<< "/" << int(d.da_mon)
				<< "/" << int(d.da_year)
				<< "\nTime:\t" << (int)t.ti_hour
				<< " : " << (int)t.ti_min << " : "
				<< (int)t.ti_sec << "\n\n";  				  
	logfile.close();
}

//Checks for valid character inputs
//Return information: 0 = space, character numbers, lowercase characters, uppercase characters & 1 = Enter key or for other characters
int check(char w1)
{
	if((int)w1==32) //CHECKING FOR SPACE
		return 0;
	
	if ((int)w1>=48 && (int)w1<=57)   //CHECKING FOR CHARACTER NUMBERS
		return 0;
	
	if ((int)w1>=97 && (int)w1<=122)  //CHECKING FOR LOWERCASE CHARACTERS
		return 0;
	
	if ((int)w1>=65 && (int)w1<=90)   //CHECKING FOR UPPERCASE CHARACTERS
		return 0;
	
	if ((int)w1==95)    //UNDERSCORE ENTERED!
		return 0;
	
	return 1; //'ENTER' ENTERED!
}

void fun::guest_acc()						//Enter Guest Account
{
	clrscr();
	
	maintain_logfile(1, 0);			// Status: 1 = Successful, 0 = Unsuccessful  | Account: 1 = Admin, 0 = Guest
	
	menu(0);
	
}


void fun::admin_acc()					//Enter Administrator Account
{
	clrscr();

	
	fstream file(FILE_CREDENTIALS, ios::app);
		file.seekg(0, ios::end);
		if(file.tellg()>2)   //FILE_CREDENTIALS is not empty!
		{
			flag=login_screen();         //Refer to logging screen from here    AND    flag variable is containing value 1 previously
		}
			
	file.close();
	switch(flag) // 0 = Unsuccessful logging, 1 = Successfull logging AND flag variable is containing value 1 previously
	{
		case 0: { cout << "\n\nMaximum logging tries exceeded! \nPlease login into another account or check your credentials!"; maintain_logfile(0, 1); sleep(3); return; }
		case 1: break;
	}                 
	clrscr();
	
	maintain_logfile(1, 1);
	menu(1);
	
	return;

}

void fun::start_screen()        //Starting execution from here
{
	START:;
	clrscr();
	LABEL;
	gotoxy(7,3);	 
	textcolor(YELLOW);
	cprintf("\t::::::::::::::WELCOME TO OSCorp Operating Environment::::::::::::::\t");  	//Start Label
	gotoxy(10, 8);
	textcolor(WHITE);
	cout << "\nPlease select an account to enter:\n";
	cout << "\t[1] ADMIN\n\t[2] GUEST\n\t[3] Exit Program";
	cout << "\nEnter your choice:\t";
	
		switch(getche())
		{
			case '1': { admin_acc(); goto START; break; }               //Refer to admin account from here
			case '2': { guest_acc(); goto START; break; }               //Refer to guest account from here 
			case '3': { cout << "\n\nConfirm Exit:\n\tAre you sure you want to exit the program? [Y/N]\n\tEnter your choice:\t";  //Exit from here 
						switch(getche())
						{
							case 'y': return;
							case 'n': goto START;
							default: { cout << "\nError: Please enter a valid input!"; sleep(1); goto START;}

						}
						}
			default:  { cout << "\nError: Please enter a valid input!"; sleep(1); goto START;}      //Invalid input checking
		}
	
}