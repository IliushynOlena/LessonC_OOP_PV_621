#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Student {
	string name;
	int age;
	int* marks;
	int countMark;
public:
	Student()
	{
		name = "no name";
		age = 0;
		marks = nullptr;
		countMark = 0;
	}
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
		marks = nullptr;
		countMark = 0;
	}
	Student(const Student &other)
	{
		this->name = other.name;
		this->age = other.age;
		this->countMark = other.countMark;
		//this->marks = other.marks;
		this->marks = new int[countMark];
		for (int i = 0; i < countMark; i++)
		{
			this->marks[i] = other.marks[i];
		}

	}
	void AddMArk(int mark)
	{
		int* temp = new int[countMark + 1];
		for (int i = 0; i < countMark; i++)
		{
			temp[i] = marks[i];
		}
		temp[countMark] = mark;

		if (marks != nullptr)
			delete[]marks;

		marks = temp;
		countMark++;

	}
	void Delete()
	{
		if (marks != nullptr)
			delete[]marks;
	}
	void Print()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Count marks : " << countMark << endl;
		cout << "MArks : ";
		for (int i = 0; i < countMark; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}
	~Student()
	{
		Delete();
	}
};
class Test {
	//default constructor
	//destructor
	// copy c-tor
}; 
class Array {
	long* arr;
	int size;
};
struct Vagon
{
	int number;
	int places;
	int passangers;
};
class Train {
	string model;
	Vagon* vagons;
	int countVagons;

};
int main()
{
	Student st;
	st.Print();

	Student student("Ivan", 18);
	student.AddMArk(11);
	student.AddMArk(12);
	student.AddMArk(7);
	student.AddMArk(8);
	student.Print();


	Student copy = Student(student);
	cout << "-----------Original----------" << endl;
	student.Print();
	cout << "-----------Copy----------" << endl;
	copy.Print();

}

