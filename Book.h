#pragma once
#include <iostream>
using namespace std;

class Book
{
	string title;
	string author;
	string genre;
	bool inCirculation;
	int visitorIndex;
public:
	Book();
	Book(string t, string a, string g);

	string GetTitle();
	void SetTitle(string t);

	string GetAuthor();
	void SetAuthor(string a);

	string GetGenre();
	void SetGenre(string g);

	bool GetCirculation();
	void SetCirculation(bool c);

	int GetVisitorIndex();
	void SetVisitorIndex(int i);

	void Print();

};