#include "Book.h"

Book::Book()
{
	inCirculation = false;
	visitorIndex = -1;
}

Book::Book(string t, string a, string g)
{
	title = t;
	author = a;
	genre = g;
	inCirculation = false;
	visitorIndex = -1;
}

string Book::GetTitle()
{
	return title;
}

void Book::SetTitle(string t)
{
	title = t;
}

string Book::GetAuthor()
{
	return author;
}

void Book::SetAuthor(string a)
{
	author = a;
}

string Book::GetGenre()
{
	return genre;
}

void Book::SetGenre(string g)
{
	genre = g;
}

bool Book::GetCirculation()
{
	return inCirculation;
}

void Book::SetCirculation(bool c)
{
	inCirculation = c;
}

int Book::GetVisitorIndex()
{
	return visitorIndex;
}

void Book::SetVisitorIndex(int i)
{
	visitorIndex = i;
}

void Book::Print()
{
	cout << "\nTitle: " << title;
	cout << "\nAuthor: " << author;
	cout << "\nGenre: " << genre;
	if (inCirculation)
	{
		cout << "\nThis book is in circulation\n";
	}
	else
	{
		cout << "\nThis book is not in circulation\n";
	}
}
