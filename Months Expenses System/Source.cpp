#include<iostream>
#include<string>
#include<math.h>
#include<map>
#include<unordered_map>
#include<vector>
#include<windows.h>
#include "expenses.h"
using namespace std;

expenses item;
map<int, map<string, vector<expenses>>> Pmap;
//vector<expenses> v[];
//map<string, vector<expenses>> Smap;
int itemsNum = 0;

void AddItems();
void Search(int);
void EditExpenses();
void DeleteExpenses();
void Display();
void DisplayAll_Items();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int choice;

	while (true) //main outer loop
	{
		cout << "\n\t\t\t----------------------------- MAIN MENU ----------------------------\n\n";
		cout << ">>>Enter your choice: \n\n";
		cout << "1-Add new expenses\n2-Delete expenses\n3-Edit expenses\n4-Search\n5-Display (Spendings)\n6-Display all items\n7-Exit\n";  //level 1 display
		cout << "\nChoice >>> "; cin >> choice;
		system("cls");
		if (choice == 7)  //to exit the program
		{
			cout << "Goodbye :)\n";
			system("PAUSE");
			exit(0);
		}
		else if (choice == 1)  //to add new expenses
		{
			AddItems();
			system("cls");

			continue;  //to back to main menu
		}
		else if (choice == 2)  //to delete expenses
		{
			DeleteExpenses();
			system("cls");

			continue;  //to back to main menu
		}
		else if (choice == 3)  //to edit expenses
		{
			EditExpenses();
			system("cls");

			continue;  //to back to main menu
		}
		else if (choice == 4)  //to search
		{
			while (true)  //inner loop (search menu)
			{
				cout << "\n\t\t\t----------------------------- SEARCH MENU ----------------------------\n\n";
				cout << ">>>Enter your choice: \n\n";
				cout << "1-Search by Month\n2-Search by category per month\n3-Back to main menu\n";  //level 2 display (search menu)
				cout << "\nChoice >>> "; cin >> choice;
				system("cls");

				if (choice == 3)  //to back to main menu
				{
					break;
				}
				else if (choice == 1) //to Search by Month
				{
					Search(1);
					system("cls");

					continue;  //to back to search menu
				}
				else if (choice == 2) //Search by category per month
				{
					Search(2);
					system("cls");

					continue;  //to back to search menu
				}
				else
				{
					cout << "\t\t\t\t-----Invalid choice!! Please try again-----\n";
					continue;
				}
				break;  //inner loop (search) end
			}
			continue;  //to back to main menu
		}
		else if (choice == 5)  //to display
		{
			Display();
			continue;  //to back to main menu
		}
		else if (choice == 6)  //to display all items
		{
			DisplayAll_Items();
			system("Pause");
			system("cls");
			continue;  //to back to main menu
		}
		else
		{
			cout << "\t\t\t\t-----Invalid choice!! Please try again-----\n";
			continue;
		}

		break;
	}  //main outer loop end


	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AddItems()
{
	int num;
	char ch;
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t----->>Add Items<<------\n\n";
		cout << "->>Enter number of items: ";
		cin >> num;

		if (num <= 0)
		{
			cout << "->>Do you want do add any items? (y/n): ";  cin >> ch;
			if (ch == 'n' || ch == 'N')
			{
				cout << "\n\n\n\t\t\t\t\t---No items were added---\n\n";
				break;
			}
			else
			{
				continue;
			}
		}
		cout << "->>Enter items information:\n";
		for (int i = 0; i < num; i++)
		{
			cout << "#" << i + 1 << " Item\n";
			cout << "Name: ";  cin >> item.name;
			cout << "Category: ";  cin >> item.category;
			cout << "Date of buying(Day/Month/Year):  ";  cin >> item.buying_date.day >> item.buying_date.month >> item.buying_date.year;
			cout << "Total Price: ";  cin >> item.price;
			cout << "Amount of money spent: ";  cin >> item.money_spent;
			item.money_remaining = item.price - item.money_spent;
			//cout << "Amount of money remaining: ";  cin >> item.money_remaining;
			Pmap[item.buying_date.month][item.category].push_back(item);
			itemsNum++;
			cout << "\n\n\t\t\t/////////////////////////////////////////////////////////////////\n\n";
		}
		cout << "\t\t\t\t\t---Items were added successfully---\n\n";
		cout << "->>Do you want do add more items? (y/n) ";  cin >> ch;
		if (ch == 'n' || ch == 'N')
		{
			break;
		}
	}
	system("PAUSE");

}
//////////////////////////////////////////////////////////////
void Search(int ch)
{
	char chr;
	int month;
	string category;
	vector<expenses>::iterator it3;
	map<string, vector<expenses>>::iterator it2;
	map<int, map<string, vector<expenses>>>::iterator it;


	if (ch == 1)  //search by month
	{
		cout << "\t\t\t\t\t----->>Search by Month<<------\n\n";

		cout << "->>Enter Month: "; cin >> month;
		//cout << "------------------";
		it = Pmap.find(month);

		if (it != Pmap.end())
		{
			cout << "\n->>Items in month: " << it->first;

			for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
			{
				cout << "\n->Category[" << it2->first << "]";
				for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
				{
					cout << "\nName: " << it3->name << "\nPrice: " << it3->price <<
						"\nBought on: " << it3->buying_date.day << "/" << it3->buying_date.month << "/" << it3->buying_date.year
						<< "\nAmount of money spent: " << it3->money_spent
						<< "\nMoney Remaining: " << it3->money_remaining;
					cout << "\n\t\t\t-----------------------------------------------------------\n";
				}

			}
		}
		else
		{
			cout << "\n\t\t\t\t\t---Month wasn't found!!---\n\n";
			cout << "->>Do you want do try again? (y/n) ";  cin >> chr;
			//system("cls");
			if (chr == 'y' || chr == 'Y')
			{
				Search(1);
			}
		}

	}
	else if (ch == 2)  //search by category per month 
	{
		cout << "\t\t\t\t----->>Search by Category per Month<<-----\n\n";

		cout << "->>Enter Month: "; cin >> month;
		cout << "\n->>Enter Category: "; cin >> category;
		it = Pmap.find(month);
		it2 = Pmap[month].find(category);
		if (it != Pmap.end() && it2 != Pmap[month].end())
		{
			cout << "\n->>Items in Month: " << it->first << " in Category: " << it2->first;
			for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
			{
				cout << "\nName: " << it3->name << "\nPrice: " << it3->price <<
					"\nBought on: " << it3->buying_date.day << "/" << it3->buying_date.month << "/" << it3->buying_date.year
					<< "\nAmount of money spent: " << it3->money_spent
					<< "\nMoney Remaining: " << it3->money_remaining;
				cout << "\n\t\t\t-----------------------------------------------------------\n";
			}
		}
		else
		{
			cout << "\n\t\t\t---Month or Category wasn't found!!---\n\n";
			cout << "->>Do you want do try again? (y/n) ";  cin >> chr;
			//system("cls");
			if (chr == 'y' || chr == 'Y')
			{
				Search(2);
			}
		}

	}
	system("PAUSE");
}
/////////////////////////////////////////////////////////////
void EditExpenses()
{
	vector<expenses>::iterator it3;
	map<string, vector<expenses>>::iterator it2;
	map<int, map<string, vector<expenses>>>::iterator it;
	int month;
	char chr;
	string category, item_name;
	bool found = false;
	cout << "\t\t\t\t\t----->>Edit Items<<------\n\n";


	DisplayAll_Items();
	cout << "->>Enter Data About Item You Want To Edit \n";
	cout << "->>Month: "; cin >> month;
	cout << "->>Category: "; cin >> category;


	it = Pmap.find(month);
	it2 = Pmap[month].find(category);
	if (it != Pmap.end() && it2 != Pmap[month].end()) {
		cout << "Item Name: "; cin >> item_name;
		for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++) {
			if (it3->name == item_name) {
				Pmap[month][category].erase(it3);

				cout << "->>Enter New Data\n";
				cout << "Name: ";  cin >> item.name;
				cout << "Category: ";  cin >> item.category;
				cout << "Date of buying(Day/Month/Year):  ";  cin >> item.buying_date.day >> item.buying_date.month >> item.buying_date.year;
				cout << "Total Price: ";  cin >> item.price;
				cout << "Amount of money spent: ";  cin >> item.money_spent;
				item.money_remaining = item.price - item.money_spent;
				//cout << "Amount of money remaining: ";  cin >> item.money_remaining;
				Pmap[item.buying_date.month][item.category].push_back(item);

				cout << "\n\t\t\t-----Item is Edited Successfully-----\n\n";
				//system("PAUSE");
				found = true;
				cout << "->>Do you want to edit another item? (y/n) "; cin >> chr;
				system("cls");
				if (chr == 'y' || chr == 'Y')
				{
					EditExpenses();
				}
				else
				{
					break;
				}
			}

		}
		if (found == false) {
			cout << "\n\t\t\t-----Invalid Item Name-----\n";
			cout << "->>Do you want do try again? (y/n) ";  cin >> chr;

			if (chr == 'y' || chr == 'Y')
			{
				EditExpenses();
			}
		}

	}
	else {
		cout << "\n\t\t\t---Month or Category wasn't found!!---\n\n";
		cout << "->>Do you want do try again? (y/n) ";  cin >> chr;
		system("cls");
		if (chr == 'y' || chr == 'Y')
		{
			EditExpenses();
		}
	}
}
/////////////////////////////////////////////////////////////
void DeleteExpenses() {
	vector<expenses>::iterator it3;
	map<string, vector<expenses>>::iterator it2;
	map<int, map<string, vector<expenses>>>::iterator it;
	int month;
	char chr;
	string category, item_name;
	bool found = false;

	cout << "\t\t\t\t\t----->>Delete Items<<------\n\n";

	DisplayAll_Items();
	cout << "Enter Data About Item You Want To Delete \n";
	cout << "->>Month: "; cin >> month;
	cout << "->>Category: "; cin >> category;


	it = Pmap.find(month);
	it2 = Pmap[month].find(category);
	if (it != Pmap.end() && it2 != Pmap[month].end()) {
		cout << "Item Name: "; cin >> item_name;

		for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++) {
			if (it3->name == item_name) {

				Pmap[month][category].erase(it3);
				itemsNum--;
				found = true;
				cout << "\n\t\t-----Item was deleted succesfully-----\n\n";
				cout << "->>Do you want to delete another item? (y/n) "; cin >> chr;
				system("cls");
				if (chr == 'y' || chr == 'Y')
				{
					EditExpenses();
				}
				else
				{
					break;
				}

			}
		}
		if (found == false) {
			cout << "\n\t\t\t-----Invalid Item Name-----\n";

			cout << "->>Do you want do try again? (y/n) ";  cin >> chr;

			if (chr == 'y' || chr == 'Y')
			{
				DeleteExpenses();
			}

		}

	}
	else {
		cout << "\n\t\t\t---Month or Category wasn't found!!---\n\n";
		cout << "->>Do you want do try again? (y/n) ";  cin >> chr;
		system("cls");
		if (chr == 'y' || chr == 'Y')
		{
			DeleteExpenses();

		}
	}

}
/////////////////////////////////////////////////////////////
void Display() {
	map<int, map<string, vector<expenses>>> ::iterator itr;
	map<string, vector<expenses>> ::iterator itr2;
	vector<expenses> ::iterator itr3;
	int month;
	string cat;
	int choice2;
	double sum = 0;
	int counter = 0;
	char choice3;
	int validation = 0;
	cout << "1-Display Expenses per category \n2-Display Expenses per month \n3-Display Total Amount Of Money Remaining\n4-Display Total Amount(Spent+Remaining)\n5-Back to main menu\n";
	cout << "\n>>> Enter your choice: ";
	cin >> choice2;
	if (choice2 == 1) {
		cout << "\nEnter month number: ";
		cin >> month;
		cout << "\nEnter category name: ";
		cin >> cat;
		for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
		{
			if (month == itr->first) {

				for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
				{
					if (cat == itr2->first) {
						validation = 1;
						cout << "\nTotal amount of money spent per month : " << itr->first << " per " << itr2->first;
						for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
						{
							sum += itr3->money_spent;
							counter++;
						}
						cout << " = " << sum << "\n" << endl;
						cout << "Number of Expenses is >> " << counter << " <<\n";

						break;
					}

				}
			}
		}

	}
	else if (choice2 == 2) {
		cout << "\nEnter month number: ";
		cin >> month;
		for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
		{
			if (month == itr->first) {
				validation = 2;
				for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
				{
					cout << "\nTotal amount of money spent per month : " << itr->first << " = ";
					for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
					{
						sum += itr3->money_spent;
						counter++;
					}
					cout << sum << "\n";
					cout << "Number of Expenses is >> " << counter << " <<\n";
					break;
				}


			}

		}


	}

	else if (choice2 == 3)
	{
		double total_rem = 0;
		for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
		{

			for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
			{
				for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
				{
					total_rem += itr3->money_remaining;
				}
			}

		}
		cout << "\n->>Total amount of money remaining = " << total_rem << endl;
	}
	else if (choice2 == 4)
	{
		double total = 0;
		for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
		{
			for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
			{
				for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
				{
					total += itr3->price;
				}
			}

		}
		cout << "\n->>Total amount of money (spent+remaining) = " << total << endl;
	}
	else if (choice2 == 5)
	{
		system("cls");
		return;
	}
	else
	{
		cout << "\nYou Entered A Wrong Choice \n";

	}

	//validation

	if (choice2 <= 2 && validation == 0)
		cout << "\nThis data does not exist \n";


	//Repeating

	while (choice2 > 0) {
		cout << "->> Do you wanna display again ? (Y/N)\n";
		cin >> choice3;
		system("cls");
		//cout << "\n------------------------------------\n";
		if (choice3 == 'Y' || choice3 == 'y') {
			//system("cls");
			Display();
		}
		else
			break;

	}
}
/////////////////////////////////////////////////////////////
void DisplayAll_Items()
{
	map<int, map<string, vector<expenses>>> ::iterator itr;
	map<string, vector<expenses>> ::iterator itr2;
	vector<expenses> ::iterator itr3;
	cout << "->>All stored items\n->>Number of items stored: " << itemsNum << endl;
	//if (itemsNum == 0)
	//{
	//	cout << "\t\t\t-----No items was found-----\n";
	//}

	for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
	{
		for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
		{
			for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
			{
				cout << "\nItem Name: " << itr3->name << " -- Category: " << itr3->category <<
					" -- Bought on: " << itr3->buying_date.day << "/" << itr3->buying_date.month << "/" << itr3->buying_date.year <<
					" -- Price: " << itr3->price << " -- Money spent: " << itr3->money_spent << endl;
			}
		}
	}
	cout << "\n--------------------------------------------------------------\n";

}

