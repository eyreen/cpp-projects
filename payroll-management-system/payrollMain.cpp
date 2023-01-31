#include "payrollDefinition.h"
#include <iostream>
using namespace std;
void addWorker(worker* work[], int& existing)
{
	string id, name;
	double amt, bonus;
	int days;
	int option;
	cout << "\n";
	cout << " =========================";
	cout << "\n Payroll Management System";
	cout << "\n =========================";
	cout << "\n Below shown is two different types of employment status: ";
	cout << "\n 1 - Part Time Worker";
	cout << "\n 2 - Full Time Worker";
	cout << "\n Please select one option: ";
	cin >> option;
	if (option == 1 || option == 2)
	{
		cout << "\n Insert worker id: ";
		cin >> id;
		cout << "\n Insert worker name: ";
		cin >> name;
		if (option == 1)
		{
			cout << "\n Insert hourly pay rate (Digits only): ";
			cin >> amt;
			cout << "\n Insert the number of working days: ";
			cin >> days;
			work[existing++] = new partTime(id, name, amt, days);
		}
		else if (option == 2)
		{
			cout << "\n Insert monthly pay rate (Digits only): ";
			cin >> amt;
			cout << "\n Insert bonus (Digits only): ";
			cin >> bonus;
			work[existing++] = new fullTime(id, name, amt, bonus);
		}
	}
	else
		cout << "\n Error! Invalid option!";
}
void displayWorker(worker* work[], int total)
{
	cout << "\n\n ----- Payroll Record Summary -----";
	for (int c = 0; c < total; c++)
		work[c]->print();
}
int main()
{
	worker* work[100];
	int existing = 0;
	char ans;
	do
	{
		if (existing < 100)
		{
			addWorker(work, existing);
			cout << "\n Would you like to add another worker (Y/N): ";
			cin >> ans;
			if (ans == 'N' || ans == 'n')
				break;
		}
		else
		{
			cout << "\n Error! Full capacity!";
			break;
		}
	} while (true);
	displayWorker(work, existing);
}

