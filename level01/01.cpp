/*
//Program 6 - 1
#include <iostream>
using namespace std;

void displayMessage()
{
	cout << "Hello from the function displayMessage.\n";
}

int main()
{
	cout << "Hello from main.\n";
	displayMessage();
	cout << "Back in function main again.\n";
	return 0;
}
//Program 6-2
#include <iostream>
using namespace std;
void displayMessage()
{
	cout << "Hello from the function displayMessage.\n";
}

int main()
{
	cout << "Hello from main.\n";
	for (int count = 0; count < 5; count++)
		displayMessage(); // Call displayMessage
	cout << "Back in function main again.\n";
	return 0;
}
//Program 6-3
// This program has three functions: main, first, and second.
#include <iostream>
using namespace std;

void first()
{
	cout << "I am now inside the function first.\n";
}

void second()
{
	cout << "I am now inside the function second.\n";
}

int main()
{
	cout << "I am starting in function main.\n";
	first(); // Call function first
	second(); // Call function second
	cout << "Back in function main again. \n";
	return 0;
}

// Program 6-4
#include <iostream>
using namespace std;

void deeper()
{
	cout << "I am now inside the function deeper.\n";
}

void deep()
{
	cout << "I am now inside the function deep.\n";
	deeper(); // Call function deeper
	cout << "Now I am back in deep.\n";
}

int main()
{
	cout << "I am starting in function main.\n";
	deep(); // Call function deep
	cout << "Back in function main again.\n";
	return 0;
}

// Program 6-5
#include <iostream>
using namespace std;

void first();
void second();

int main()
{
	cout << "I am starting in function main.\n";
	first(); // Call function first
	second(); // Call function second
	cout << "Back in function main again.\n";
	return 0;
}

void first()
{
	cout << "I am now inside the function first.\n";
}

void second()
{
	cout << "I am now inside the function second.\n";
}

// Program 6-6
#include <iostream>
using namespace std;

void displayValue(int);

int main()
{
	cout << "I am passing 5 to displayValue.\n";
	displayValue(5); // Call displayValue with argument 5
	cout << "Now I am back in main.\n";
	return 0;
}
void displayValue(int num)
{
	cout << "The value is " << num << endl;
}

// Program 6-7
#include <iostream>
using namespace std;

void displayValue(int);

int main()
{
	cout << "I am passing several values to displayValue.\n";
	displayValue(5); // Call displayValue with argument 5
	displayValue(10); // Call displayValue with argument 10
	displayValue(2); // Call displayValue with argument 2
	displayValue(16); // Call displayValue with argument 16
	cout << "Now I am back in main.\n";
	return 0;
}

void displayValue(int num)
{
	cout << "The value is " << num << endl;
}

// Program 6-8
#include <iostream>
using namespace std;

void showSum(int, int, int);

int main()
{
	int value1, value2, value3;

	// Get three integers.
	cout << "Enter three integers and I will display ";
	cout << "their sum: ";
	cin >> value1 >> value2 >> value3;

	// Call showSum passing three arguments.
	showSum(value1, value2, value3);
	return 0;
}

void showSum(int num1, int num2, int num3)
{
	cout << (num1 + num2 + num3) << endl;
}

// Program 6-9
#include <iostream>
using namespace std;

// Function Prototype
void changeMe(int);

int main()
{
	int number = 12;

	// Display the value in number.
	cout << "number is " << number << endl;

	// Call changeMe, passing the value in number
	// as an argument.
	changeMe(number);

	// Display the value in number again.
	cout << "Now back in main again, the value of ";
	cout << "number is " << number << endl;
	return 0;
}
void changeMe(int myValue)
{
	// Change the value of myValue to 0.
	myValue = 0;

	// Display the value in myValue.
	cout << "Now the value is " << myValue << endl;
}

// Program 6-10
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void showMenu();
void showFees(double, int);

int main()
{
	int choice; // To hold a menu choice
	int months; // To hold a number of months

	// Constants for the menu choices
	const int ADULT_CHOICE = 1,
		CHILD_CHOICE = 2,
		SENIOR_CHOICE = 3,
		QUIT_CHOICE = 4;

	// Constants for membership rates
	const double ADULT = 40.0,
		CHILD = 20.0;
	SENIOR = 30.0,

		// Set up numeric output formatting.
		cout << fixed << showpoint << setprecision(2);

	do
	{
		// Display the menu and get the user's choice.
		showMenu();
		cin >> choice;

		// Validate the menu selection.
		while (choice < ADULT_CHOICE || choice > QUIT_CHOICE)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}

		// If the user does not want to quit, proceed.
		if (choice != QUIT_CHOICE)
		{
			// Get the number of months.
			cout << "For how many months? ";
			cin >> months;

			// Display the membership fees.
			switch (choice)
			{
			case ADULT_CHOICE:
				showFees(ADULT, months);
				break;
			case CHILD_CHOICE:
				showFees(CHILD, months);
				break;
			case SENIOR_CHOICE:
				showFees(SENIOR, months);
			}
		}
	} while (choice != QUIT_CHOICE);
	return 0;
}
void showMenu()
{
	cout << "\n\t\tHealth Club Membership Menu\n\n"
		<< "1. Standard Adult Membership\n"
		<< "2. Child Membership\n"
		<< "3. Senior Citizen Membership\n"
		<< "4. Quit the Program\n\n"
		<< "Enter your choice: ";
}

void showFees(double memberRate, int months)
{
	cout << "The total charges are $"
		<< (memberRate * months) << endl;
}

*/