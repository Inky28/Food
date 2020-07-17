#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "User.h"
#include "Product.h"

using namespace std;

class Database
{
public:
	void Enter();
	void Login();
	void AdminPanel();
	bool checkAdmin(string name, string password);
	void addProduct();
	void delProduct(const Product& product);
private:
	list<User> users;
	list<Product> products;
};