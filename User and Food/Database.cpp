#include "Database.h"
#define SIZE 256
//Database::Database()
//{
//	// empty
//}
//
//Database::~Database()
//{
//	// empty
//}
//const size_t SIZE = 256;

void Database::Enter()
{
	bool exit = false;
	int choice;

	User temp;

	do
	{
		cout << "\tLogin\n\n";
		cout << "1. Login\n";
		cout << "2. Registrationister\n";
		cout << "0. Exit\n";
		cout << "Enter: ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 1:
			Login();
			break;

		case 2:
			temp.Registration();
			users.push_back(temp);
			break;

		case 0:
			exit = true;
		}
	} while (!exit);
}

void Database::Login()
{
	char charName[SIZE];
	char charPass[SIZE];
	string stringName;
	string stringPass;

	cout << "Enter name: ";
	cin >> charName;

	cin.get();
	cout << "Enter password: ";
	cin >> charPass;

	system("cls");

	stringName = charName;
	stringPass = charPass;

	if (checkAdmin(stringName, stringPass))
		AdminPanel();

	for (User item : users)
		if (item.Login(stringName, stringPass))
			item.menu(products);
}

void Database::AdminPanel()
{
	bool exit = false;
	int choice;
	char charTemp;

	bool deleted = false;

	do
	{
		system("cls");

		cout << "\tADMIN PANEL\n\n";
		cout << "1. Edit products\n";
		cout << "2. Add product\n";
		cout << "3. Del product\n";
		cout << "4. Show all\n";
		cout << "0. Exit\n";
		cout << "Enter: ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 0:
			exit = true;
			return;

		case 1:
			for (Product item : products)
			{
				cout << "NAME: " << item.getName() << endl;
				cout << "Edit this product? [Y/N]: ";
				cin >> charTemp;

				switch (charTemp)
				{
				case'Y': case 'y':
					item.menu();
				}
			}
			break;

		case 2:
			addProduct();
			break;

		case 3:
			deleted = false;
			for (Product item : products)
			{
				cout << "NAME: " << item.getName() << endl;
				cout << "Delete this product? [Y/N]: ";
				cin >> charTemp;
				switch (charTemp)
				{
				case'Y':case 'y':
					delProduct(item);
					system("cls");
					deleted = true;
				}
				if (deleted)
					break;
			}
			break;

		case 4:
			for (Product item : products)
				item.print();

			system("pause");
			break;
		}
	} while (!exit);
}

bool Database::checkAdmin(string name, string password)
{
	fstream fin("config.txt");
	string temp;

	fin >> temp;
	if (temp != name)
		return false;

	fin >> temp;
	if (temp != password)
		return false;

	fin.close();
	return true;
}

void Database::addProduct()
{
	Product temp;

	char charTemp[SIZE];
	float price;
	size_t count;
	string str;

	system("cls");

	cin.get();
	cout << "Enter name: ";
	cin.getline(charTemp, SIZE);
	str = charTemp;
	temp.setName(str);

	cout << "Enter info: ";
	cin.getline(charTemp, SIZE);
	str = charTemp;
	temp.setInfo(str);

	cout << "Enter price: ";
	cin >> price;
	temp.setPrice(price);

	cout << "Enter count: ";
	cin >> count;
	temp.setCount(count);

	products.push_back(temp);
}

void Database::delProduct(const Product& product)
{
	products.remove(product);
}
