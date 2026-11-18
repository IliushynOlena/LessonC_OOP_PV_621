#include <iostream>
#include <windows.h>    
using namespace std;

void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

class Person//abstart class
{
	string name;
	int age;
public:
	Person() :name("no name"), age(0) {}
	Person(string name, int age) :name(name), age(age) {}
	virtual void Print()const
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
	}
	virtual ~Person() = 0 {}//pure virtual 
};
class Aspirant : public Person
{
	string* subjects;
	int countSubjects;
public:
	Aspirant() :subjects(nullptr), countSubjects(0), Person() {}
	Aspirant(string name, int age, initializer_list<string> list) :
		Person(name, age)
	{
		countSubjects = list.size();
		subjects = new string[countSubjects];

		int i = 0;
		for (string str : list)
		{
			subjects[i] = str;
			i++;
		}

	}
	void Print()const override
	{
		Person::Print();
		cout << "Subject : ";
		for (int i = 0; i < countSubjects; i++)
		{
			cout << subjects[i] << "  |  ";
		}cout << endl;
	}
	~Aspirant()
	{
		if (subjects != nullptr)
			delete[]subjects;
	}
};

struct Point
{
	int x;
	int y;
};
int main()
{
	Point start = { 5,5 };
	Point end = { 15,15 };
	cout << "Point start : x = " << start.x << " y = " << start.y << endl;


	gotoxy(start.x, start.y); cout << "*";
	gotoxy(end.x, end.y); cout << "*";



	srand(time(0));
	/*Person student("Vasia", 18);
	student.Print();*/
	/*
	Aspirant aspirant("Petro", 20, { "Human fabrix","Animals" });
	aspirant.Print();
	cout << endl << endl;

	Person* group[3]{
		//new Person("Vasia", 18),
		new Aspirant("Petro", 20, { "Human fabrix","Animals" }),
		new Aspirant("Petro", 20, { "Human fabrix","Animals" }),
		new Aspirant("Olga", 20, { "UA/UX","Design main page" })
	};
	for (int i = 0; i < 3; i++)
	{
		group[i]->Print();
		delete group[i];
	}
	*/
}

