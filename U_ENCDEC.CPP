/*
ENCRYPTION ALGORITHM FOR USER CREDENTIALS
ALGORITHM:
	Provides a unique keyword of 7 characters for every characters in the sets of alphabet (lowercase only), numbers and special symbol (underscores, white spaces, comma, fullstop)
*/

char username[40], pwd[40];

//#define FILE_NAME_ENCRYPTER_ENCRYPTER "enc.bin"

		//Code for lowercase alphabets
#define CODE_a "r2&6+Af"
#define CODE_b "45sa)9*"
#define CODE_c "{:-qoy1"
#define CODE_d "Ppt:O0H"
#define CODE_e "g3}+hdc"
#define CODE_f "o$$O122"
#define CODE_g "Y#@n-1d"
#define CODE_h "^&0x:u0"
#define CODE_i "5*s<O:L"
#define CODE_j "l&*^g4f"
#define CODE_k "sOO9!s2"
#define CODE_l "T6%4#@1"
#define CODE_m "oP{=_4+"
#define CODE_n "jsp+_8&"
#define CODE_o "s$2#4f_"
#define CODE_p "j%$4_8h"
#define CODE_q "%$#ggf4"
#define CODE_r "s*jN552"
#define CODE_s "@c%d783"
#define CODE_t "|#53_)9"
#define CODE_u "+,>,K46"
#define CODE_v "&4$3{)s"
#define CODE_w ")oPOu@5"
#define CODE_x "^jxh$5%"
#define CODE_y "}])sd1f"
#define CODE_z "s+u9*)r"

/*
		//Code for uppercase alphabets
#define CODE_A "CB15{[r"
#define CODE_B "129cVbP"
#define CODE_C "M1qqlMo"
#define CODE_D "0xPPkjl"
#define CODE_E "pKl*@Kl"
#define CODE_F "%(jK,<O"
#define CODE_G "L-JJpo0"
#define CODE_H "K$lo#cy"
#define CODE_I "BBui-(+"
#define CODE_J "{L)*L4L"
#define CODE_K "12/PPh*"
#define CODE_L "JJkl0+-"
#define CODE_M "L:/***l"
#define CODE_N ")-nNmkk"
#define CODE_O "kL{{{8*"
#define CODE_P "P=_=44$"
#define CODE_Q "_k0xcVc"
#define CODE_R "*7HHmy$"
#define CODE_S "PP-0*!g"
#define CODE_T "KK45+12"
#define CODE_U "Hg))8&*"
#define CODE_V "l:P-0#4"
#define CODE_W "II9**@h"
#define CODE_X "@ddFgf!"
#define CODE_Y "{p[21|h"
#define CODE_Z "^l+LhjP"
*/

		//Code for numbers
#define CODE_0 "PLo25/$"
#define CODE_1 "HHj3#2c"
#define CODE_2 "KP-+Ko0"
#define CODE_3 "P-129T^"
#define CODE_4 "%$gtRRc"
#define CODE_5 "JJR^7Bm"
#define CODE_6 "HJL/OpL"
#define CODE_7 "I(4@1np"
#define CODE_8 "YT%TUJN"
#define CODE_9 "IUYR)(&"

		//Code for special symbols
#define CODE_underscore 		  "GBHfyJ*"
#define CODE_space				  "+5Y&^#@"
#define CODE_comma			  	  "KL4)&#@"
#define CODE_fullstop			  "HHM<..>"
/*
#define CODE_hyphen				  "KKL}}n#"
#define CODE_(					  "HJ&&^*]"
#define CODE_)					  "HJ&%%$a"
#define CODE_&					  "@##B66J"
#define CODE_*					  "K*&&6gR"
#define CODE_semicolon			  "#$FFt5:"
#define CODE_doubleinvertedcomma  "*JJI&78"
#define CODE_singleinvertedcomma  "&*kkL-+"
#define CODE_?					  ">>iyhgr"
#define CODE_@					  "H5HJ7**"
#define CODE_!
#define CODE_#
#define CODE_$
#define CODE_%
#define CODE_[
#define CODE_]
#define CODE_{
#define CODE_}
*/


class encrypter_decrypter_system
{
public:
	//encrypter_decrypter_system();
	void encode();
	void decode();
	void about();
};

void encrypter_decrypter_system::about()
{
	clrscr();
	cout << "  ************************* ABOUT ENCRYPTER-DECRYPTER **********************\n\n"
		<< "\tENCRYPTER-DECRYPTER is a product of the OSCorp Corporation.\n"
		<< "\tAny attempt to copy the copyrighted products eg. the functional\n"
		<< "\talgorithms, or the functional technique is liable to punishable offence.\t"
		<< "\n\tAll rights reserved."
		<< "\n\n\tThis product is licensed under the OSCorp Software License Terms"
		<< "\n\tto the product owner.";
	GETCH_MSG;
		getch();
}


void encrypter_decrypter_system::decode()
{
	clrscr();
	cout << "\t\tDECODE TEXT:\n";
	char file_name[13]; //cin.get();
	ENTER_AGAIN:;
	cout << "\nEnter the name of the file where the text code is written [Maximum 8 characters]:\t";
	cin >> file_name; strcat(file_name, ".bin");
	
	ifstream file_read(file_name); 
	if(file_read.bad())
		{ cout << "\n\n\tError: No such file exists!\n\tPlease enter a valid file name.\n\n"; file_read.close(); GETCH_MSG; getch(); return; }
	char string[2100], segment[9];
	file_read.getline(string, 2100);
	file_read.close();
	
		char decoded_string[300]; int start=0, end=0;
		int length=(strlen(string)/7);
		for(int n=0; n<length; n++)
		{
			start=(n*7);  //cout << "\nstart: " << start;
			end=((n+1)*7)-1; //cout << "\tend: " << end;
			int u=0;
			for(int y=start; y<=end; y++)
			{
				segment[u]=string[y];
				u++;
			}
			segment[u]=0;
			//cout << "\nSegment is: " << segment;  getch();

					 if(!strcmp(CODE_a, segment))
					{ decoded_string[n]='a'; }

				else if(!strcmp(CODE_b, segment))
					{ decoded_string[n]='b'; }

				else if(!strcmp(CODE_c, segment))
					{ decoded_string[n]='c'; }

				else if(!strcmp(CODE_d, segment))
					{ decoded_string[n]='d'; }

				else if(!strcmp(CODE_e, segment))
					{ decoded_string[n]='e'; }

				else if(!strcmp(CODE_f, segment))
					{ decoded_string[n]='f'; }

				else if(!strcmp(CODE_g, segment))
					{ decoded_string[n]='g'; }

				else if(!strcmp(CODE_h, segment))
					{ decoded_string[n]='h'; }

				else if(!strcmp(CODE_i, segment))
					{ decoded_string[n]='i'; }

				else if(!strcmp(CODE_j, segment))
					{ decoded_string[n]='j'; }

				else if(!strcmp(CODE_k, segment))
					{ decoded_string[n]='k'; }

				else if(!strcmp(CODE_l, segment))
					{ decoded_string[n]='l'; }

				else if(!strcmp(CODE_m, segment))
					{ decoded_string[n]='m'; }

				else if(!strcmp(CODE_n, segment))
					{ decoded_string[n]='n'; }

				else if(!strcmp(CODE_o, segment))
					{ decoded_string[n]='o'; }

				else if(!strcmp(CODE_p, segment))
					{ decoded_string[n]='p'; }

				else if(!strcmp(CODE_q, segment))
					{ decoded_string[n]='q'; }

				else if(!strcmp(CODE_r, segment))
					{ decoded_string[n]='r'; }

				else if(!strcmp(CODE_s, segment))
					{ decoded_string[n]='s'; }

				else if(!strcmp(CODE_t, segment))
					{ decoded_string[n]='t'; }

				else if(!strcmp(CODE_u, segment))
					{ decoded_string[n]='u'; }

				else if(!strcmp(CODE_v, segment))
					{ decoded_string[n]='v'; }

				else if(!strcmp(CODE_w, segment))
					{ decoded_string[n]='w'; }
					
				else if(!strcmp(CODE_x, segment))
					{ decoded_string[n]='x'; }
				
				else if(!strcmp(CODE_y, segment))
					{ decoded_string[n]='y'; }

				else if(!strcmp(CODE_z, segment))
					{ decoded_string[n]='z'; }
				
				/*
				else if(!strcmp(CODE_A, segment))
					{ decoded_string[n]='A'; }

				else if(!strcmp(CODE_B, segment))
					{ decoded_string[n]='B'; }

				else if(!strcmp(CODE_C, segment))
					{ decoded_string[n]='C'; }

				else if(!strcmp(CODE_D, segment))
					{ decoded_string[n]='D'; }

				else if(!strcmp(CODE_E, segment))
					{ decoded_string[n]='E'; }

				else if(!strcmp(CODE_F, segment))
					{ decoded_string[n]='F'; }

				else if(!strcmp(CODE_G, segment))
					{ decoded_string[n]='G'; }

				else if(!strcmp(CODE_H, segment))
					{ decoded_string[n]='H'; }

				else if(!strcmp(CODE_I, segment))
					{ decoded_string[n]='I'; }

				else if(!strcmp(CODE_J, segment))
					{ decoded_string[n]='J'; }

				else if(!strcmp(CODE_K, segment))
					{ decoded_string[n]='K'; }

				else if(!strcmp(CODE_L, segment))
					{ decoded_string[n]='L'; }

				else if(!strcmp(CODE_M, segment))
					{ decoded_string[n]='M'; }

				else if(!strcmp(CODE_N, segment))
					{ decoded_string[n]='N'; }

				else if(!strcmp(CODE_O, segment))
					{ decoded_string[n]='O'; }

				else if(!strcmp(CODE_P, segment))
					{ decoded_string[n]='P'; }

				else if(!strcmp(CODE_Q, segment))
					{ decoded_string[n]='Q'; }

				else if(!strcmp(CODE_R, segment))
					{ decoded_string[n]='R'; }

				else if(!strcmp(CODE_S, segment))
					{ decoded_string[n]='S'; }

				else if(!strcmp(CODE_T, segment))
					{ decoded_string[n]='T'; }

				else if(!strcmp(CODE_U, segment))
					{ decoded_string[n]='U'; }

				else if(!strcmp(CODE_V, segment))
					{ decoded_string[n]='V'; }

				else if(!strcmp(CODE_W, segment))
					{ decoded_string[n]='W'; }

				else if(!strcmp(CODE_X, segment))
					{ decoded_string[n]='X'; }

				else if(!strcmp(CODE_Y, segment))
					{ decoded_string[n]='Y'; }

				else if(!strcmp(CODE_Z, segment))
					{ decoded_string[n]='Z'; }
				*/

				else if(!strcmp(CODE_0, segment))
					{ decoded_string[n]='0'; }

				else if(!strcmp(CODE_1, segment))
					{ decoded_string[n]='1'; }

				else if(!strcmp(CODE_2, segment))
					{ decoded_string[n]='2'; }

				else if(!strcmp(CODE_3, segment))
					{ decoded_string[n]='3'; }

				else if(!strcmp(CODE_4, segment))
					{ decoded_string[n]='4'; }

				else if(!strcmp(CODE_5, segment))
					{ decoded_string[n]='5'; }

				else if(!strcmp(CODE_6, segment))
					{ decoded_string[n]='6'; }

				else if(!strcmp(CODE_7, segment))
					{ decoded_string[n]='7'; }

				else if(!strcmp(CODE_8, segment))
					{ decoded_string[n]='8'; }

				else if(!strcmp(CODE_9, segment))
					{ decoded_string[n]='9'; }

				else if(!strcmp(CODE_underscore, segment))
					{ decoded_string[n]='_'; }
					
				else if(!strcmp(CODE_space, segment))
					{ decoded_string[n]=' '; }
				
				else if(!strcmp(CODE_comma, segment))
					{ decoded_string[n]=','; }
				
				else if(!strcmp(CODE_fullstop, segment))
					{ decoded_string[n]='.'; }
					
				
				else
					{ cout << "\n\n\tError: Unknown code encountered!\tCode: " << segment << endl; }
		}
		decoded_string[n]=0;
		cout << "\n\nDecoded string is:\n" << decoded_string;
		GETCH_MSG;
		getch();
}

void encrypter_decrypter_system::encode()
{
	clrscr();
	cout << "\t\tENCODE TEXT:\n";
	char string[126], name[13];
	
	cout << "\nEnter the name of the file where you want to keep the encrypted codes\n[Maximum 8 characters wide]:\t"; cin >> name; strcat(name, ".bin");
	ifstream file_test(name);
		if(!file_test.bad())
			{ file_test.seekg(0, ios::end); cout << "\n\n\tError: A file of the same name already exists!\n\tSize of the file: " << file_test.tellg() << " Bytes.\n\nPlease enter another file name!\n\n"; file_test.close(); GETCH_MSG; getch(); return; }
		else
		{ file_test.close(); }
	cout << "\n\n\tN.B.: Please enter the text within this sets:\n\tAlphabets (lowercase only), Numbers (0-9) and special symbols\n\t(underscores, white spaces, comma, fullstop).\n\tThe text have to be within maximum 125 characters.\n\n";
	cout << "\nEnter a line of text:\n";
		
	cin.get();
	cin.getline(string, 125);
	if(strlen(string)==125)
		{ cout << "\n\n\tMaximum limit reached: Maximum number of\n\tcharacters reached! [125 characters]\n"; getch(); }
	int len=strlen(string);
	
	
	ofstream file(name);

	for(int i=0; i<len; i++)
	{
		switch(string[i])
		{
			case 'a': { file << CODE_a; break; }
			case 'b': { file << CODE_b; break; }
			case 'c': { file << CODE_c; break; }
			case 'd': { file << CODE_d; break; }
			case 'e': { file << CODE_e; break; }
			case 'f': { file << CODE_f; break; }
			case 'g': { file << CODE_g; break; }
			case 'h': { file << CODE_h; break; }
			case 'i': { file << CODE_i; break; }
			case 'j': { file << CODE_j; break; }
			case 'k': { file << CODE_k; break; }
			case 'l': { file << CODE_l; break; }
			case 'm': { file << CODE_m; break; }
			case 'n': { file << CODE_n; break; }
			case 'o': { file << CODE_o; break; }
			case 'p': { file << CODE_p; break; }
			case 'q': { file << CODE_q; break; }
			case 'r': { file << CODE_r; break; }
			case 's': { file << CODE_s; break; }
			case 't': { file << CODE_t; break; }
			case 'u': { file << CODE_u; break; }
			case 'v': { file << CODE_v; break; }
			case 'w': { file << CODE_w; break; }
			case 'x': { file << CODE_x; break; }
			case 'y': { file << CODE_y; break; }
			case 'z': { file << CODE_z; break; }
			/*
			case 'A': { file << CODE_A; break; }
			case 'B': { file << CODE_B; break; }
			case 'C': { file << CODE_C; break; }
			case 'D': { file << CODE_D; break; }
			case 'E': { file << CODE_E; break; }
			case 'F': { file << CODE_F; break; }
			case 'G': { file << CODE_G; break; }
			case 'H': { file << CODE_H; break; }
			case 'I': { file << CODE_I; break; }
			case 'J': { file << CODE_J; break; }
			case 'K': { file << CODE_K; break; }
			case 'L': { file << CODE_L; break; }
			case 'M': { file << CODE_M; break; }
			case 'N': { file << CODE_N; break; }
			case 'O': { file << CODE_O; break; }
			case 'P': { file << CODE_P; break; }
			case 'Q': { file << CODE_Q; break; }
			case 'R': { file << CODE_R; break; }
			case 'S': { file << CODE_S; break; }
			case 'T': { file << CODE_T; break; }
			case 'U': { file << CODE_U; break; }
			case 'V': { file << CODE_V; break; }
			case 'W': { file << CODE_W; break; }
			case 'X': { file << CODE_X; break; }
			case 'Y': { file << CODE_Y; break; }
			case 'Z': { file << CODE_Z; break; }
			*/
			case '0': { file << CODE_0; break; }
			case '1': { file << CODE_1; break; }
			case '2': { file << CODE_2; break; }
			case '3': { file << CODE_3; break; }
			case '4': { file << CODE_4; break; }
			case '5': { file << CODE_5; break; }
			case '6': { file << CODE_6; break; }
			case '7': { file << CODE_7; break; }
			case '8': { file << CODE_8; break; }
			case '9': { file << CODE_9; break; }
			case '_': { file << CODE_underscore; break; }
			case ' ': { file << CODE_space; break; }
			case ',': { file << CODE_comma; break; }
			case '.': { file << CODE_fullstop; break; }
			

			default: { cout << "\n\n\nError: Text cannot be accepted since character is not within the valid range!\n\t\tInvalid character: " << string[i]; GETCH_MSG; getch(); return; }
		}

	}
	file << endl;
	//cout << "\nFILE WRITTEN!\n";

	file.close();

	//cout << "\n\n\tEncoder called!";

	char a;
	ifstream file2(name);
	cout << "\n\tText is encoded successfully and written in file '" << name << "'!\n\tText code:\n";
	while(file2)
	{
		file2.get(a);
		cout.put(a);
	}
	cout << "\n\n";
	file2.close();
	GETCH_MSG;
	getch();
}



void encrypter_decrypter()
{
	
	encrypter_decrypter_system c;
	SHOW_MENU_AGAIN:;
	clrscr();
	cout << "*********************** WELCOME TO ENCRYPTER-DECRYPTER ************************\n\n"
		<< "\tMENU Options:\n"
		<< "\t\t[a] Encrypt a line of text"
		<< "\t\t[b] Decrypt a coded text"
		<< "\t\t[c] About ENCRYPTER-DECRYPTER"
		<< "\t\t[d] Exit program"
		<< "\tEnter your choice:\t";
		switch(getche())
		{
			case 'a': { c.encode(); goto SHOW_MENU_AGAIN; break; }
			case 'b': { c.decode(); goto SHOW_MENU_AGAIN; break; }
			case 'c': { c.about(); goto SHOW_MENU_AGAIN; break; }
			case 'd': { return; }
			default: { CHOICE_ERROR; sleep(2); goto SHOW_MENU_AGAIN; }
		}
		
	
	GETCH_MSG;
	getch();

}