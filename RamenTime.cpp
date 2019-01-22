// Ramen Time
// RT Logo

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

//global variables
int date = 1;
int customers;
int yelp_bonus = 0;
int diff;
int diffchoice;
int workers;
int dayworkers;
int sales;
int truework;
int loss;
int warning;
int praise = 0;
string dayname;
string owner;

//displays the logo of ramen time
void ramentimelogo() 
{

	cout << string( 100, '\n' );
	cout << " ____    __    __  __  ____  _  _    ____  ____  __  __  ____ \n";
	cout << "(  _ \\  /__\\  (  \\/  )( ___)( \\( )  (_  _)(_  _)(  \\/  )( ___) \n";
	cout << " )   / /(__)\\  )    (  )__)  )  (     )(   _)(_  )    (  )__)  \n";
	cout << "(_)\\_)(__)(__)(_/\\/\\_)(____)(_)\\_)   (__) (____)(_/\\/\\_)(____) \n";
	cout << "\nPress [SPACE] to continue!";
	getch();
}

//sets difficulty
void difficulty() 
{
	cout << string( 100, '\n' );
	cout << "Choose your difficulty.\n";
	cout << "(1) Easy, (2) Hard \n";
	cin >> diffchoice;
	switch (diffchoice)
	{
		//easy
	case 1:
		diff = 0;
		workers = 5;
		break;

		//hard
	case 2:
		diff = 10;
		workers = 3;
		break;
	}
}

//sets owner name
void nameowner()
{
	cout << string(100, '\n');
	cout << "You have just inherited a ramen restaurant named 'Ramen Time'.\n";
	cout << "Sign the contract to start! \n \n \n";
	cout << "I hearby agree to run 'Ramen Time' and take all responsibilty in its success.\n";
	cout << "Sign with first name: ";
	cin >> owner;
	cout << string(100, '\n');
	cout << "Hello Chief " << owner << "! Welcome to Ramen Time! It is your first day! \n \n";
	cout << "You currently have " << workers << " workers.";
	cout << "\n\nPress [SPACE] to continue!";
	getch();
}

//results and back to workchoose
void gamealg2()
{
	if (date == 7)
	{
		date = date - 6;
	}
	else
	{
		date = date + 1;
	}
}

//main game algorithm
void gamealg()
{
	sales = customers - truework;
	sales = -sales;
	loss = abs(sales);

	if (loss < 10)
		{
		yelp_bonus = yelp_bonus + (customers / truework);
		praise = praise + yelp_bonus;
		cout << "Good job! Got " << (customers / truework) << " good Yelp review(s).";
		}
	else if (loss > 10)
	{
		//not enough workers
		if (sales < 0)
		{
			warning = warning + (loss / truework);
			cout << "Bad! Not enough workers! " << (loss / 10) << " bad yelp reviews were written about today!";

		}

		//too many workers
		else if (sales > 0)
		{
			warning = warning + (loss / truework);
			cout << "Bad! Too many workers! Got " << (loss / 10) << " complaint(s)!";
		}
	
		getch();
		gamealg2();
	}
}

//meat and potatoes
void workchoose() 
{
	cout << string(100, '\n');
	cout << "Today is " << dayname << ". You currently have " << workers << " workers.\n\n";
	cout << "How many workers would you like to send out?\n\nWorkers to send out: ";
	cin >> dayworkers;
	cout << string(100, '\n');
	truework = dayworkers * 10;
	cout << customers << " customers visted the store today.\n";
	cout << "You had " << dayworkers << " on staff.\n\n";
	gamealg();
}

//set amount of customers in a day
void customersoftheday()
{
	switch (date)
	{
		//monday
	case 1:
		customers = rand() % 15 + (25 + yelp_bonus + diff);
		dayname = "Monday";
		break;

		//tuesday
	case 2:
		customers = rand() % 15 + (20 + yelp_bonus + diff);
		dayname = "Tuesday";
		break;

		//wednesday
	case 3:
		customers = rand() % 10 + (15 + yelp_bonus + diff);
		dayname = "Wednesday";
		break;

		//thursday
	case 4:
		customers = rand() % 15 + (20 + yelp_bonus + diff);
		dayname = "Thursday";
		break;

		//friday
	case 5:
		customers = rand() % 20 + (30 + yelp_bonus + diff);
		dayname = "Friday";
		break;

		//saturday
	case 6:
		customers = rand() % 30 + (50 + yelp_bonus + diff);
		dayname = "Saturday";
		break;

		//sunday
	case 7:
		customers = rand() % 15 + (30 + yelp_bonus + diff);
		dayname = "Sunday";
		break;
	}
	workchoose();
}

void ramentime()
{
	ramentimelogo();
	difficulty();
	nameowner();
	do{
		customersoftheday();
	} while ((workers > 0) && (workers <= 100));
}

int main()
{
	ramentime();
}