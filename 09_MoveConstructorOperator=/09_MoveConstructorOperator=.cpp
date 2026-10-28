#include "Library.h"

class MyClass {
	//default constructor
	//destructor
	//copy constructor
	//move constructor
	//operator =
};

Library Test(Library& lib) 
{
	Library temp;
	//some code...
	return temp;
}
int main()
{
	Book book("Kobzar",1865, "Shevchenko",1200,Genre::Education);
	book.ShowInfo();

	Library lib("Youngth library", "Kyivska 15, Rivne, Ukraine");
	lib.AddBook(Book("The Hitchhiker's Guide to the Galaxy", 1979, "Douglas Adams", 224, Comedy));
	lib.AddBook(Book("Good Omens", 1990, "Neil Gaiman & Terry Pratchett", 416, Comedy));
	lib.AddBook(Book("To Kill a Mockingbird", 1960, "Harper Lee", 281, Drama));
	lib.AddBook(Book("Harry Potter and the Sorcerer's Stone", 1997, "J.K. Rowling", 309, Fantasy));
	lib.AddBook(Book("Dune", 1965, "Frank Herbert", 896, SciFi));
	lib.AddBook(Book("The Adventures of Sherlock Holmes", 1892, "Arthur Conan Doyle", 307, Mystery));
	lib.AddBook(Book("Pride and Prejudice", 1813, "Jane Austen", 279, Romance) );
	lib.AddBook(Book("1984", 1949, "George Orwell", 328, SciFi));
	lib.AddBook(Book("Three Men in a Boat", 1889, "Jerome K. Jerome", 223, Comedy) );
	lib.AddBook(Book("The Great Gatsby", 1925, "F. Scott Fitzgerald", 180, Drama));

	lib.ShowLibrary();

	cout << "\n----------- Clone lib ----------\n\n";
	Library clone(lib);//copy constructor
	clone.ShowLibrary();

	cout << "\n----------- New lib ----------\n\n";
	Library newLib = lib;
	newLib.ShowLibrary();

	//3     5        10   <------------------
	lib = clone = newLib;

	Test(lib);

}



