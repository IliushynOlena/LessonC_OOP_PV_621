#include "Book.h"


Book::Book()
{
	title = "no title";
	year = 0;
	author = "no author";
	page = 0;
	genre = None;
}

void Book::ShowInfo() const
{
	cout << "Title : " << title << endl;
	cout << "Year : " << year << endl;
	cout << "Author : " << author << endl;
	cout << "Page : " << page << endl;
	cout << "Genre : ";
	switch (genre)
	{
	case None:cout << "None" << endl;break;
	case Fantasy:cout<<"Fantasy"<<endl;break;
	case Comedy:cout<<"Comedy"<<endl;break;
	case Novel:cout<<"Novel"<<endl;break;
	case SciFi:cout<<"SciFi"<<endl;break;
	case Education:cout<<"Education"<<endl;break;
	case Roman:cout << "Roman" << endl;break;
	case Political:cout<<"Political"<<endl;break;
	case Mystery:cout << "Mystery" << endl; break;
	case Drama:cout << "Drama" << endl; break;
	}
}
