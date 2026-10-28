#include "Library.h"

Library::Library()
{
	name = "no name";
	address = "no address";
	books = nullptr;
	countBooks = 0;
}

Library::Library(string name, string address)
{
	this->name = name;
	this->address = address;
	books = nullptr;
	countBooks = 0;
}

 Library::Library(const Library& other)
{
	this->name = other.name;     //"Youtn"
	this->address = other.address;//Rivne
	this->countBooks = other.countBooks;
	//this->books = other.books;    //0z2z3z5z ---> 0z2z3z5z
	this->books = new Book[countBooks];
	for (int i = 0; i < countBooks; i++)
	{
		this->books[i] = other.books[i];
	}
}

 Library::Library(Library&& other)
 {
	 this->name = other.name;
	 this->address = other.address;
	 this->countBooks = other.countBooks;
	 this->books = other.books;
	 other.books = nullptr;
	 cout << "Move constructor" << endl;
 }

 Library& Library::operator=(const Library& other)
 {
	 this->name = other.name;
	 this->address = other.address;
	 this->countBooks = other.countBooks;
	 if (books != nullptr)
		 delete[]books;
	 this->books = new Book[countBooks];
	 for (int i = 0; i < countBooks; i++)
	 {
		 this->books[i] = other.books[i];
	 }
	 return *this;
 }

void Library::ShowLibrary() const 
{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
	for (int i = 0; i < countBooks; i++)
	{
		books[i].ShowInfo(); 
		cout << endl << endl;
	}
}

void Library::AddBook(Book b) 
{
	Book* temp = new Book[countBooks + 1];
	for (int i = 0; i < countBooks; i++)
	{
		temp[i] = books[i];
	}
	temp[countBooks] = b;
	if (books != nullptr)
		delete[]books;
	books = temp;
	countBooks++;
	
}

 Library::~Library()
{
	if (books != nullptr)
		delete[]books;
}
