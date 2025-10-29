#include "Visitor.h"

Visitor::Visitor()
{
	numOfBooks = 0;
}

Visitor::Visitor(string l, string i)
{
	lastName = l;
	id = i;
	numOfBooks = 0;
}

string Visitor::GetLastName()
{
	return lastName;
}

string Visitor::GeID()
{
	return id;
}

int Visitor::GetNumOfBooks()
{
	return numOfBooks;
}

void Visitor::SetLastName(string a)
{
	lastName = a;
}

void Visitor::SetID(string a)
{
	id = a;
}

void Visitor::SetNumOfBooks(int a)
{
	numOfBooks = a;
}

void Visitor::Print()
{
	cout << "\nLast name: " << lastName;
	cout << "\nID: " << id;
	cout << "\nNumber of books: " << numOfBooks;
}
