#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void ShowList(list<int>& l1, list<int>& l2)
{
	int a = 5;
	int* pa = &a;
	list<int>* ptr = nullptr;
	list<int>::iterator i;
	cout << "List 1 : ";
	for ( i = l1.begin(); i != l1.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << "List 2 : ";
	for (i = l2.begin(); i != l2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
struct Book
{
	string name;
	string author;
	int pages;

};
bool CompareByName(const Book& b1, const Book& b2)
{
	return b1.name < b2.name;
}
bool CompareBAuthor(const Book& b1, const Book& b2)
{
	return b1.author < b2.author;
}
bool CompareByPages(const Book& b1, const Book& b2)
{
	return b1.pages < b2.pages;
}
int main()
{
	list<Book> library;

	library.push_back(Book{ "Kolobok", "Folclore", 20 });

	library.assign({
		Book{"Kobzar","Shevchenko",1000},
		Book{"Maria","Kotliarevskiy",333},
		Book{"Adventures Tom Soer","MArk Twain",555}
		});
	cout << "------------------- Original list : --------------" << endl;
	for (Book b: library)
	{
		cout <<left<< setw(25)<< b.name <<setw(15)<< b.author << setw(10) << b.pages << endl;
	}

	library.sort(CompareByName);
	cout << "------------------- Sorted list by name: --------------" << endl;
	for (Book b : library)
	{
		cout << left << setw(25) << b.name << setw(15) << b.author << setw(10) << b.pages << endl;
	}

	library.sort(CompareBAuthor);
	cout << "------------------- Sorted list by author: --------------" << endl;
	for (Book b : library)
	{
		cout << left << setw(25) << b.name << setw(15) << b.author << setw(10) << b.pages << endl;
	}

	library.sort(CompareByPages);
	cout << "------------------- Sorted list by pages: --------------" << endl;
	for (Book b : library)
	{
		cout << left << setw(25) << b.name << setw(15) << b.author << setw(10) << b.pages << endl;
	}


	/*
	list<int> l1, l2;
	cout << "Size : " << l1.size() << endl;
	
	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
		l2.push_front(i);
	}
	ShowList(l1, l2);

	l1.assign({ 55,44,33 });
	ShowList(l1, l2);

	l1.erase(l1.begin());
	ShowList(l1, l2);

	list<int>::iterator it = l1.begin();
	it++;

	l1.erase(it);
	ShowList(l1, l2);

	l1.insert(l1.begin(), 77);
	ShowList(l1, l2);
	l1.insert(l1.begin(), { 4,7,8,9 });
	ShowList(l1, l2);

	l1.insert(l1.end(), 5, 22);
	ShowList(l1, l2);

	l1.insert(l1.begin(), l2.begin(), l2.end());
	ShowList(l1, l2);

	l1.remove(22);
	ShowList(l1, l2);

	l1.resize(50,7);
	ShowList(l1, l2);

	l1.splice(l1.end(), l2, l2.begin());
	ShowList(l1, l2);

	l1.reverse();
	ShowList(l1, l2);

	l1.sort();
	l2.sort();
	ShowList(l1, l2);

	l1.merge(l2);
	ShowList(l1, l2);


	l1.unique();
	ShowList(l1, l2);

	l1.swap(l2);
	ShowList(l1, l2);
	*/


}

