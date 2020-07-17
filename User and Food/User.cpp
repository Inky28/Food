#include "User.h"
#include <iostream>
#define SIZE 256

void User::Registration()
{
	bool good = false;
	char temp[SIZE];
	string str;

	cin.get();
	system("cls");
	while (!good)
	{
		cout << "Enter name: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			setName(str);
			good = true;
		}
		system("cls");
	}
	good = false;

	while (!good)
	{
		cout << "Enter mail: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			setEmail(str);
			good = true;
		}
		system("cls");
	}

	good = false;
	while (!good)
	{
		cout << "Enter number: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			setNumber(str);
			good = true;
		}
		system("cls");
	}

	good = false;
	while (!good)
	{
		cout << "Enter password: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			system("cls");
			cout << "Enter password one more time: ";
			cin.getline(temp, SIZE);
			if (str == temp)
			{
				setPassword(str);
				good = true;
			}
			system("cls");
		}
	}
}

bool User::Login(string name, string password)
{
	if (this->name == name && this->password == password)
		return true;
	return false;
}

void User::putCash()
{
	float temp;
	bool ok = false;

	cin.get();
	system("cls");
	while (!ok)
	{
		cout << "Enter cash to put: ";
		cin >> temp;
		if (temp > 0)
		{
			setCash(temp + getCash());
			ok = true;
		}
		system("cls");
	}
}

bool User::buy(Product& myProduct)
{
	if (this->cash >= myProduct.getPrice() && myProduct.getCount() > 0)
	{
		myProduct--;
		inventory.push_back(myProduct);
		setCash(cash - myProduct.getPrice());
		return true;
	}
	return false;
}

void User::printInventory() const
{
	cout << "\tInventory\n\n";
	for (Product item : inventory)
		item.print();

	system("pause");
	system("cls");
}

void User::menu(list<Product>& products)
{
	bool exit = false;
	int choice;

	do
	{
		system("cls");

		cout << "\tUSER_MENU\n\n";
		cout << "1. Info\n";
		cout << "2. Put cash\n";
		cout << "3. Buy product\n";
		cout << "4. Show my inventory\n";
		cout << "0. Exit\n";
		cout << "Enter: ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 0:
			return;
		case 1:
			print();
			break;
		case 2:
			putCash();
			break;
		case 3:
			char otherChoice;
			for (Product item : products)
			{
				item.print();
				cout << "Buy this? [Y/N]: ";
				cin >> otherChoice;
				switch (otherChoice)
				{
				case 'Y': case 'y':
					buy(item);
					break;
				}
				system("cls");
			}
			break;

		case 4:
			printInventory();
			break;
		}
	} while (!exit);
}

void User::print() const
{
	system("cls");

	cout << "\tInformation\n\n";
	cout << "Name:   " << this->name << endl;
	cout << "Mail:  " << this->email << endl;
	cout << "Number: " << this->number << endl;
	cout << "Cash:   " << this->cash << endl;
	cout << "\n===========\n";

	system("pause");
	system("cls");
}

User::User()
{
	name = "";
	email = "";
	number = "";
	password = "";
	cash = 0;
}

string User::getName() const
{
	return this->name;
}

string User::getEmail() const
{
	return this->email;
}

string User::getNumber() const
{
	return this->number;
}

string User::getPassword() const
{
	return this->password;
}

float User::getCash() const
{
	return this->cash;
}

void User::setName(string name)
{
	if (!name.empty())
		this->name = name;
}

void User::setEmail(string email)
{
	if (!email.empty())
		this->email = email;
}

void User::setNumber(string number)
{
	if (!number.empty())
		this->number = number;
}

void User::setPassword(string password)
{
	if (!password.empty())
		this->password = password;
}

void User::setCash(float cash)
{
	if (cash > 0)
		this->cash = cash;
}
