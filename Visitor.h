#pragma once
#include <iostream>
using namespace std;

class Visitor
{
	string lastName;
	string id;
	int numOfBooks;
public:
	Visitor();
	Visitor(string l, string i);

	string GetLastName();
	string GeID();
	int GetNumOfBooks();
	void SetLastName(string a);
	void SetID(string a);
	void SetNumOfBooks(int a);
	void Print();
};