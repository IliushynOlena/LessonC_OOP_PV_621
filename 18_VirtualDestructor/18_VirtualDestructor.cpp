#include <iostream>
using namespace std;

class Student
{
	string name;
	int age;
	int* marks;
	int countMarks;
public:
	Student() :name("no name"), age(0), marks(nullptr), countMarks(0) {}
	Student(string name, int age):name(name),age(age)
	{
		countMarks = rand() % 10 + 1;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++)
		{
			marks[i] = rand() % 5 + 8;//0...4
		}
	}
	virtual void Print()const 
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Marks : ";
		for (int i = 0; i < countMarks; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}
	virtual ~Student()
	{
		if (marks != nullptr)
			delete[]marks;
	}
};
class Aspirant : public Student
{
	string *subjects;
	int countSubjects;
public:
	Aspirant() :subjects(nullptr),countSubjects(0), Student() {}
	Aspirant(string name, int age,initializer_list<string> list) :
		Student(name,age) 
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
		Student::Print();
		cout << "Subject : " ;
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
	Student student("Vasia", 18);
	student.Print();

	Aspirant aspirant("Petro", 20, { "Human fabrix","Animals" });
	aspirant.Print();
	cout << endl << endl;



	Student* group[3]{
		new Student("Vasia", 18),
		new Aspirant("Petro", 20, { "Human fabrix","Animals" }),
		new Aspirant("Olga", 20, { "UA/UX","Design main page" })
	};
	for (int i = 0; i < 3; i++)
	{
		group[i]->Print(); 
		delete group[i];
	}
}

