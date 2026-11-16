#include <iostream>
using namespace std;

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

int main()
{
	srand(time(0));
	/*Person student("Vasia", 18);
	student.Print();*/

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
}

