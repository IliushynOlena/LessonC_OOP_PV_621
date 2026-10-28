#pragma once
#include "Book.h"

class Library
{
	string name;
	string address;
	Book* books;
	int countBooks;
public:
	Library();
	Library(string name, string address);
	Library(const Library & other);
	Library(Library&& other);
	Library& operator =(const Library& other);
	void ShowLibrary()const;
	void AddBook(Book b);
	~Library();
};

