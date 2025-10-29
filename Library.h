#pragma once
#include <iostream>
#include "Book.h"
#include "Visitor.h"
using namespace std;

class Library
{
	Book* bookArr;
	int bookSize;
	int bookPos;

	Visitor* visitorArr;
	int visitorSize;
	int visitorPos;
public:
	Library();
	Library(int s);
	~Library();

	void SearchByTitle(string a);
	void SearchByGenre(string a);
	void SearchByAuthor(string a);
	void MostFrequentVisitor();
	void DisplayAllBooks();
	void DisplayByTitle(string a);
	void DisplayByGenre(string a);
	void DisplayByAuthor(string a);
	void AddBook(Book b);
	void AddVisitor(Visitor v);
	void bookCheckin(int i, int j);
	void bookCheckout(int i);

	int GetIndexByTitle(string a);
	int GetIndexByID(string a);

	void Interface();
};