#pragma once

#include <string>
using namespace std;

class Product
{
public:
	Product();

	string getName() const;
	string getInfo() const;
	size_t getCount() const;
	float getPrice() const;
	void setName(string name);
	void setInfo(string info);
	void setPrice(float price);
	void setCount(size_t count);
	void print() const;
	void menu();
	void operator ++ (int);
	void operator -- (int);
	void operator ++ ();
	void operator -- ();
	bool operator == (const Product& product) const;
private:
	string name;
	string info;
	float price;
	size_t count;
};

