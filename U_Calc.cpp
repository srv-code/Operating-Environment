//Calculator Application Module

#include "MACROS.CPP"
class st_calc
{
protected:
	float ANS;
public:
	void add();
	void sub();
	void mul();
	void div();
	void expo();
	void root();
	void invert();
	void div_rem();
	void div_quo();
	void percentage();
};


class sc_calc : public st_calc 
{
public:
	void find_cos();
	void find_sin();
	void find_tan();
	void find_sec();
	void find_cosec();
	void find_cot();
};

void sc_calc::find_cos()
{
	float op;
	TRY_AGAIN:;
	cout << "\nDo you want to take the last answer as operand? [y/n]\nEnter your choice:\t";
	switch(getche())
	{
		case 'y': { op=ANS; break; }
		case 'n': { cout << "\nEnter operand:\t"; cin >> op; break; }
		default: { CHOICE_ERROR; sleep(1); goto TRY_AGAIN;}
	}

	ANS=cos(op);
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
}

void sc_calc::find_sin()
{
	float op;
	TRY_AGAIN:;
	cout << "\nDo you want to take the last answer as operand? [y/n]\nEnter your choice:\t";
	switch(getche())
	{
		case 'y': { op=ANS; break; }
		case 'n': { cout << "\nEnter operand:\t"; cin >> op; break; }
		default: { CHOICE_ERROR; sleep(1); goto TRY_AGAIN;}
	}

	ANS=sin(op);
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
}

void sc_calc::find_tan()
{
	float op;
	TRY_AGAIN:;
	cout << "\nDo you want to take the last answer as operand? [y/n]\nEnter your choice:\t";
	switch(getche())
	{
		case 'y': { op=ANS; break; }
		case 'n': { cout << "\nEnter operand:\t"; cin >> op; break; }
		default: { CHOICE_ERROR; sleep(1); goto TRY_AGAIN;}
	}

	ANS=(sin(op)/cos(op));
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
}

void sc_calc::find_sec()
{
	float op;
	TRY_AGAIN:;
	cout << "\nDo you want to take the last answer as operand? [y/n]\nEnter your choice:\t";
	switch(getche())
	{
		case 'y': { op=ANS; break; }
		case 'n': { cout << "\nEnter operand:\t"; cin >> op; break; }
		default: { CHOICE_ERROR; sleep(1); goto TRY_AGAIN;}
	}

	ANS=(1/(cos(op)));
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
}

void sc_calc::find_cosec()
{
	float op;
	TRY_AGAIN:;
	cout << "\nDo you want to take the last answer as operand? [y/n]\nEnter your choice:\t";
	switch(getche())
	{
		case 'y': { op=ANS; break; }
		case 'n': { cout << "\nEnter operand:\t"; cin >> op; break; }
		default: { CHOICE_ERROR; sleep(1); goto TRY_AGAIN;}
	}

	ANS=(1/sin(op));
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
}

void sc_calc::find_cot()
{
	float op;
	TRY_AGAIN:;
	cout << "\nDo you want to take the last answer as operand? [y/n]\nEnter your choice:\t";
	switch(getche())
	{
		case 'y': { op=ANS; break; }
		case 'n': { cout << "\nEnter operand:\t"; cin >> op; break; }
		default: { CHOICE_ERROR; sleep(1); goto TRY_AGAIN;}
	}

	ANS=(cos(op)/sin(op));
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
}


void st_calc::percentage()
{
	float numerator, denominator;
	cout << "\nEnter numerator:\t"; cin >> numerator;
	cout << "Enter denominator:\t"; cin >> denominator;
	ANS=(numerator/denominator)*100;
	cout << "\nAnswer:\t" << ANS << "%";
	GETCH_MSG;
	getch();
	getch();
	
}


void st_calc::div_rem()
{
	float numerator, denominator;
	cout << "\nEnter numerator:\t"; cin >> numerator;
	cout << "Enter denominator:\t"; cin >> denominator;
	ANS=((int)numerator%(int)denominator);
	cout << "\nAnswer:\t" << ANS << "%";
	GETCH_MSG;
	getch();
}

void st_calc::div_quo()
{
	float op1, op2;
	cout << "\nEnter numerator:\t"; cin >> op2;
	cout << "Enter denominator:\t"; cin >> op1;
	ANS=((int)op2/(int)op1);
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
	
}

void st_calc::root()
{
	float op, n;
	cout << "\nEnter number:\t"; cin >> op;
	cout << "\nEnter root power:\t"; cin >> n;
	ANS=pow(op, (1/n));
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
	
}


void st_calc::invert()
{
	float op;
	cout << "\nEnter number:\t"; cin >> op;
	ANS=(1/op);
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
	
}


void st_calc::expo()
{
	float op, n;
	cout << "\nEnter number:\t"; cin >> op;
	cout << "\nEnter power to be raised:\t"; cin >> n;
	ANS=pow(op, n);
	cout << "\nAnswer:\t" << ANS;
	GETCH_MSG;
	getch();
	
}

void st_calc::div()
{
	float op1, op2;
	cout << "\nInclude last answer?"
		<< "\t\n1. As operand 1"
		<< "\t\n2. As operand 2"
		<< "\nEnter choice:\t";
	switch(getche())
	{
	case '1': { op1=ANS; cout << "\nOperand 2:\t"; cin >> op2; break; }
	case '2': { op2=ANS; cout << "\nOperand 1:\t"; cin >> op1; break; }
	default: { cout << CHOICE_ERROR; return; }
	}
	
	
	ANS=op1/op2;
	cout << "\nAnswer:\t" << ANS;
	
	GETCH_MSG;
	getch();
	
}


void st_calc::mul()
{
	float op1, op2;
	cout << "\nInclude last answer? [y/n]"
		<< "\nEnter choice:\t";
	switch(getche())
	{
	case 'y': { op1=ANS; break; }
	case 'n': { cout << "\nOperand 1:\t"; cin >> op1; break; }
	default: { cout << CHOICE_ERROR; return; }
	}
	
	cout << "\nOperand 2:\t"; cin >> op2;
	ANS=op1*op2;
	cout << "\nAnswer:\t" << ANS;
	
	GETCH_MSG;
	getch();
	
}


void st_calc::sub()
{
	float op1, op2;
	cout << "\nInclude last answer?"
		<< "\t\n1. As operand 1"
		<< "\t\n2. As operand 2"
		<< "\nEnter choice:\t";
	switch(getche())
	{
	case '1': { op1=ANS; cout << "\nOperand 2:\t"; cin >> op2; break; }
	case '2': { op2=ANS; cout << "\nOperand 1:\t"; cin >> op1; break; }
	default: { cout << CHOICE_ERROR; return; }
	}
	
	
	ANS=op1-op2;
	cout << "\nAnswer:\t" << ANS;
	
	GETCH_MSG;
	getch();
	
}

void st_calc::add()
{
	float op1, op2;
	cout << "\nInclude last answer? [y/n]"
		<< "\nEnter choice:\t";
	switch(getche())
	{
	case 'y': { op1=ANS; break; }
	case 'n': { cout << "\nOperand 1:\t"; cin >> op1; break; }
	default: { cout << CHOICE_ERROR; return; }
	}
	
	cout << "\nOperand 2:\t"; cin >> op2;
	ANS=op1+op2;
	cout << "\nAnswer:\t" << ANS;
	
	GETCH_MSG;
	getch();
	
}

void st_calc_menu()
{
	clrscr();
	st_calc c;
	cout << "Standard Calculator:\n"
		<< "\n\t[a]  Add"
		<< "\n\t[b]  Substract"
		<< "\n\t[c]  Multiply"
		<< "\n\t[d]  Divide"
		<< "\n\t[e]  Exponent"
		<< "\n\t[f]  Root"
		<< "\n\t[g]  Invert"
		<< "\n\t[h]  Division reminder"
		<< "\n\t[i]  Division quotient"
		<< "\n\t[j]  Calculate percentage"
		<< "\n\t[k]  Exit program"
		<< "\n\nEnter choice:\t";
		switch(getche())
		{
		case 'a': { cout << "\n\n"; c.add(); cout << "\n\n"; break; }
		case 'b': { cout << "\n\n"; c.sub(); cout << "\n\n"; break; }
		case 'c': { cout << "\n\n"; c.mul(); cout << "\n\n"; break; }
		case 'd': { cout << "\n\n"; c.div(); cout << "\n\n"; break; }
		case 'e': { cout << "\n\n"; c.expo(); cout << "\n\n"; break; }
		case 'f': { cout << "\n\n"; c.root(); cout << "\n\n"; break; }
		case 'g': { cout << "\n\n"; c.invert(); cout << "\n\n"; break; }
		case 'h': { cout << "\n\n"; c.div_rem(); cout << "\n\n"; break; }
		case 'i': { cout << "\n\n"; c.div_quo(); cout << "\n\n"; break; }
		case 'j': { cout << "\n\n"; c.percentage(); cout << "\n\n"; break; }
		case 'k': return;
		default: { CHOICE_ERROR; }
		}
}

void sc_calc_menu()
{
	clrscr();
	sc_calc c;
	cout << "Scientific Calculator:\n"
		<< "\n\t[a]  Add"
		<< "\n\t[b]  Substract"
		<< "\n\t[c]  Multiply"
		<< "\n\t[d]  Divide"
		<< "\n\t[e]  Exponent"
		<< "\n\t[f]  Root"
		<< "\n\t[g]  Invert"
		<< "\n\t[h]  Division reminder"
		<< "\n\t[i]  Division quotient"
		<< "\n\t[j]  Calculate percentage"
		<< "\n\t[k]  Find cos of x"
		<< "\n\t[l]  Find sin of x"
		<< "\n\t[m]  Find tan of x"
		<< "\n\t[n]  Find sec of x"
		<< "\n\t[o]  Find cosec of x"
		<< "\n\t[p]  Find cot of x"
		<< "\n\t[q]  Exit program"
		<< "\n\nEnter choice:\t";
		switch(getche())
		{
		case 'a': { cout << "\n\n"; c.add(); cout << "\n\n"; break; }
		case 'b': { cout << "\n\n"; c.sub(); cout << "\n\n"; break; }
		case 'c': { cout << "\n\n"; c.mul(); cout << "\n\n"; break; }
		case 'd': { cout << "\n\n"; c.div(); cout << "\n\n"; break; }
		case 'e': { cout << "\n\n"; c.expo(); cout << "\n\n"; break; }
		case 'f': { cout << "\n\n"; c.root(); cout << "\n\n"; break; }
		case 'g': { cout << "\n\n"; c.invert(); cout << "\n\n"; break; }
		case 'h': { cout << "\n\n"; c.div_rem(); cout << "\n\n"; break; }
		case 'i': { cout << "\n\n"; c.div_quo(); cout << "\n\n"; break; }
		case 'j': { cout << "\n\n"; c.percentage(); cout << "\n\n"; break; }
		case 'k': { cout << "\n\n"; c.find_cos(); cout << "\n\n"; break; }
		case 'l': { cout << "\n\n"; c.find_sin(); cout << "\n\n"; break; }
		case 'm': { cout << "\n\n"; c.find_tan(); cout << "\n\n"; break; }
		case 'n': { cout << "\n\n"; c.find_sec(); cout << "\n\n"; break; }
		case 'o': { cout << "\n\n"; c.find_cosec(); cout << "\n\n"; break; }
		case 'p': { cout << "\n\n"; c.find_cot(); cout << "\n\n"; break; }
		case 'q': return;
		default: { CHOICE_ERROR; }
		}
}

void about_calc()
{
	clrscr();
	cout << "      -------------------------- CALCULATOR -----------------------------------\n\n"
		<< "\tCALCULATOR is a product of the OSCorp Corporation.\n"
		<< "\tAny attempt to copy the copyrighted products eg. the functional\n"
		<< "\talgorithms, or the functional technique is liable to punishable offence.\t"
		<< "\n\tAll rights reserved."
		<< "\n\n\tThis product is licensed under the OSCorp Software License Terms"
		<< "\n\tto the product owner.";
	GETCH_MSG;
		getch();
}

void calculator()
{

	while(1)
	{
		clrscr();
		cout << "\n\t\t******************** Calculator *****************\n"
			<< "\n\t1. Standard Calculator"
			<< "\n\t2. Scientific Calculator"
			<< "\n\t3. About Calculator"
			<< "\n\t4. Exit Calculator"
			<< "\nEnter your choice:\t";
		switch(getche())
		{
		case '1': { st_calc_menu(); break; }
		case '2': { sc_calc_menu(); break; }
		case '3': { about_calc(); break; }
		case '4': return;
		default: { CHOICE_ERROR; }
		}
	}
}