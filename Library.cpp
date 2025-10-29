#include "Library.h"

Library::Library()
{
	bookArr = new Book[10];
	bookSize = 10;
	bookPos = 0;

	visitorArr = new Visitor[10];
	visitorSize = 10;
	visitorPos = 0;
}

Library::Library(int s)
{
	bookArr = new Book[s];
	bookSize = s;
	bookPos = 0;

	visitorArr = new Visitor[s];
	visitorSize = s;
	visitorPos = 0;
}

Library::~Library()
{
	delete[] bookArr;
	delete[] visitorArr;
}

void Library::SearchByTitle(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetTitle() == a)
		{
			bookArr[i].Print();
		}
	}
}

void Library::SearchByGenre(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetGenre() == a)
		{
			bookArr[i].Print();
		}
	}
}

void Library::SearchByAuthor(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetAuthor() == a)
		{
			bookArr[i].Print();
		}
	}
}

void Library::MostFrequentVisitor()
{
	Visitor max = visitorArr[0];
	for (int i = 0; i < visitorSize; i++)
	{
		if (visitorArr[i].GetNumOfBooks() > max.GetNumOfBooks())
		{
			max = visitorArr[i];
		}
	}
	max.Print();
}

void Library::DisplayAllBooks()
{
	for (int i = 0; i < bookSize; i++)
	{
		bookArr[i].Print();
	}
}

void Library::DisplayByTitle(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetTitle() == a)
		{
			bookArr[i].Print();
		}
	}
}

void Library::DisplayByGenre(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetGenre() == a)
		{
			bookArr[i].Print();
		}
	}
}

void Library::DisplayByAuthor(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetAuthor() == a)
		{
			bookArr[i].Print();
		}
	}
}

void Library::AddBook(Book b)
{
	if (bookPos == bookSize -1)
	{
		Book* temp = bookArr;
		bookArr = new Book[bookSize + 4];
		for (int i = 0; i < bookSize; i++)
		{
			bookArr[i] = temp[i];
		}
	}
	bookArr[bookPos] = b;
	bookPos++;
}

void Library::AddVisitor(Visitor v)
{
	if (visitorPos == visitorSize - 1)
	{
		Visitor* temp = visitorArr;
		visitorArr = new Visitor[visitorSize + 4];
		for (int i = 0; i < visitorSize; i++)
		{
			visitorArr[i] = temp[i];
		}
	}
	visitorArr[visitorPos] = v;
	visitorPos++;
}

void Library::bookCheckin(int i, int j)
{
	if (bookArr[i].GetCirculation() == true)
	{
		throw "This book is already in circulation.";
	}
	if (visitorArr[j].GetNumOfBooks() == 3)
	{
		throw "This visitor can not have more than three books on hand.";
	}
	bookArr[i].SetCirculation(true);
	visitorArr[j].SetNumOfBooks(visitorArr[j].GetNumOfBooks() + 1);
}

void Library::bookCheckout(int i)
{
	visitorArr[bookArr[i].GetVisitorIndex()].SetNumOfBooks(visitorArr[bookArr[i].GetVisitorIndex()].GetNumOfBooks() - 1);
	bookArr[i].SetCirculation(false);
	bookArr[i].SetVisitorIndex(-1);
}

int Library::GetIndexByTitle(string a)
{
	for (int i = 0; i < bookSize; i++)
	{
		if (bookArr[i].GetTitle() == a)
		{
			return i;
		}
	}
	throw "\nThis book is not in the library. You can add it by entering 9.\n";
}

int Library::GetIndexByID(string a)
{
	for (int i = 0; i < visitorSize; i++)
	{
		if (visitorArr[i].GeID() == a)
		{
			return i;
		}
	}
	throw "\nThis person is not a visitor of the library. You can add him/her by entering 10.\n";
}

void Library::Interface()
{
	int choice;
	cout << "\nEnter a command:\n\n1 - Search By Title\n2 - Search By Genre\n3 - Search By Author\n4 - Most Frequent Visitor\n5 - Display All Books\n6 - Display By Title\n7 - Display By Genre\n8 - Display By Author\n9 - Add A Book\n10 - Add A Visitor\n11 - book Checkin\n12 - book Checkout\n13 - exit\n\n";
	cin >> choice;
	string a;
	Book obj;
	Visitor obj2;
	int i, j;
	switch (choice)
	{
	case 1:
		cout << "\nenter the title\n";
		cin >> a;
		SearchByTitle(a);
		Interface();
		break;
	case 2:
		cout << "\nenter the genre\n";
		cin >> a;
		SearchByGenre(a);
		Interface();
		break;
	case 3:
		cout << "\nenter the name of the author\n";
		cin >> a;
		SearchByAuthor(a);
		Interface();
		break;
	case 4:
		MostFrequentVisitor();
		Interface();
		break;
	case 5:
		DisplayAllBooks();
		Interface();
		break;
	case 6:
		cout << "\nenter the title\n";
		cin >> a;
		DisplayByTitle(a);
		Interface();
		break;
	case 7:
		cout << "\nenter the genre\n";
		cin >> a;
		DisplayByGenre(a);
		Interface();
		break;
	case 8:
		cout << "\nenter the name of the author\n";
		cin >> a;
		DisplayByAuthor(a);
		Interface();
		break;
	case 9:
		cout << "\nenter the title\n";
		cin >> a;
		obj.SetTitle(a);
		cout << "\nenter the genre\n";
		cin >> a;
		obj.SetGenre(a);
		cout << "\nenter the name of the author\n";
		cin >> a;
		obj.SetAuthor(a);
		AddBook(obj);
		Interface();
		break;
	case 10:
		cout << "\nenter the name of the visitor\n";
		cin >> a;
		obj2.SetLastName(a);
		cout << "\nenter the ID of the visitor\n";
		cin >> a;
		obj2.SetID(a);
		AddVisitor(obj2);
		Interface();
		break;
	case 11:
		cout << "\nenter the title\n";
		cin >> a;
		i = GetIndexByTitle(a);
		cout << "\nenter the ID of the visitor\n";
		cin >> a;
		j = GetIndexByID(a);
		bookCheckin(i,j);
		Interface();
		break;
	case 12:
		cout << "\nenter the title\n";
		cin >> a;
		i = GetIndexByTitle(a);
		bookCheckout(i);
		Interface();
		break;
	case 13:
		break;
	default:
		Interface();
		break;
	}
}
