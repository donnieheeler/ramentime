// Ramen Time
// RT Logo

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
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
int dayspassed;
int ramensold;
int dummy;

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
	cout << "\nPress [ENTER] to continue!";
	sleep(5);
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
	cout << "Hello Chief " << owner << "! Welcome to Ramen Time! Let's get to work!";
	cout << "\n\nPress [SPACE] to continue!";
	sleep(5);
}

void dayresults()
{

	if (warning >= 5)
	{
		workers -= 1;
		cout << "\n\nOh no you did so bad you had to let someone go!";
		warning = 0;
		sleep(5);
	}

	else if (praise >= 3)
	{
		workers += 1;
		cout << "\n\nWow nice! You managed to hire someone new!";
		praise = 0;
		sleep(5);
	}
}

//results and back to workchoose
void gamealg2()
{
	dayspassed += 1;

	if (date == 7)
	{
		date = date - 6;
	}
	else
	{
		date = date + 1;
	}

	dayresults();

}

//main game algorithm
void gamealg()
{
	sales = customers - truework;
	sales = -sales;
	loss = abs(sales);

	if (truework > customers)
	{
		ramensold += customers;
	}
	else
	{
		ramensold += (customers - sales);
	}

	if (loss < 10)
	{
	yelp_bonus = yelp_bonus + (customers / 10);
	praise = praise + (customers /10);
	cout << "Good job! You got " << (customers / 10) << " good Yelp review(s).";
	}

	else
	{
		
		//not enough workers
		if (sales < 0)
		{
			warning = warning + (loss / 10);
			cout << "Bad! Not enough workers! " << (loss / 10) << " bad yelp reviews were written about today!";

		}

		
		//too many workers
		else if (sales > 0)
		{
			warning = warning + (loss / 10);
			cout << "Bad! Too many workers! Got " << (loss / 10) << " complaint(s)!";
		}

	}

	sleep(5);
	gamealg2();
	}


//meat and potatoes
void workchoose() 
{
	cout << string(100, '\n');
	cout << "Today is " << dayname << ". You currently have " << workers << " worker(s).\n\n";
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

void endgame() {

	cout << string(100, '\n');
	if (workers <= 0)
	{

		cout << "Oh no you had to fire everyone and 'Ramen Time' went bankrupt!\n\n";
		cout << "You somehow managed to sell " << ramensold << " bowl(s) of ramen in the short time you were open!\n";
		cout << "\nThank you for playing!";
	}
	else
	{
		cout << "Congrats! You did very well and hired a ton of people! You managed to sell 'Ramen Time' and retire.\n\n";
		cout << "You impressively sold a total of " << ramensold << " bowl(s) of ramen! Wow!\n";
		cout << "\nThank you for playing!";
	}

	sleep(10);
}

void ramentime()
{
	ramentimelogo();
	difficulty();
	nameowner();
	do{
		customersoftheday();
	} while ((workers > 0) && (workers <= 100));
	endgame();
}

int main()
{
	ramentime();
	return 0;
}
