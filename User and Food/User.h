#pragma once

#include <list>
#include <string>
#include "Product.h"

using namespace std;

class User
{
public:
	User();
	string getName() const;
	string getEmail() const;
	string getNumber() const;
	string getPassword() const;
	float getCash() const;
	void setName(string name);
	void setEmail(string email);
	void setNumber(string number);
	void setPassword(string password);
	void setCash(float cash);
	void Registration();
	bool Login(string name, string password);
	void putCash();
	bool buy(Product& p);
	void print() const;
	void printInventory() const;
	void menu(list<Product>& products);
private:
	string name;
	string email;
	string number;
	string password;
	float cash;
	list<Product> inventory;
};

