#include <iostream>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void PrintDate()
	{
		cout << "Birthdate : " << day << "/" 
			<< month << "/" << year << endl;
	}
};
class Student
{
private:
	string name;
	string surname;
	Date birthdate;
	string phone;
	int *marks;
	int countMark;
	float averageMark;
	void AverageMArk()
	{
		float summa = 0;
		for (int i = 0; i < countMark; i++)
		{
			summa += marks[i];
		}
		averageMark = summa / countMark;
	}
public:
	//ctor+TAB
	Student()//method
	{
		cout << "Default constructor" << endl;
		name = "no name";
		surname = "no name";
		birthdate = { 1,1,1 };
		phone = "no phone";
		marks = nullptr;
		countMark = 0;
		averageMark = 0;
	}
	Student(string name, string surname,Date b, string phone)
	{
		cout << "Parametrized constructor" << endl;
		this->name = name;
		this->surname = surname;
		this->birthdate = b;
		this->phone = phone;
		marks = nullptr;
		countMark = 0;
		averageMark = 0;

	}
	void Print()
	{
		cout << "Name : " << name << endl;
		cout << "Surname : " << surname << endl;

		birthdate.PrintDate();
		cout << "Phone : " << phone << endl;
		cout << "Marks : ";
		for (int i = 0; i < countMark; i++)
		{
			cout << marks[i] << " ";
		}
		cout << "\nAverage Mark : " << averageMark << endl;
		
	}
	void Initialization()
	{
		name = "no name";
		surname = "no name";
		birthdate = { 1,1,1 };
		phone = "no phone";
		marks = nullptr;
		countMark = 0;
		averageMark = 0;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void AddMark(int mark)
	{
		int *temp = new int[countMark+1];
		for (int i = 0; i < countMark; i++)
		{
			temp[i] = marks[i];
		}
		temp[countMark] = mark;
		if (marks != nullptr)
		{
			delete[]marks;
		}
		marks = temp;
		countMark++;
		AverageMArk();

	}
	~Student()
	{
		cout << "Destructor " << name << endl;
		if (marks != nullptr)
		{
			delete[]marks;
		}
	}
};
int main()
{
	Student student;//Default constructor
	//student.Initialization();
	student.Print();

	
	student.setName("Vasia");
	student.setSurname("Ivanchuk");
	student.AddMark(12);
	student.AddMark(8);
	student.AddMark(10);
	student.Print();
	cout << endl<<endl;
	Student st("Yoseph", "Petruk", { 14,5,2000 }, "+709514782547");
	st.AddMark(8);
	st.AddMark(6);
	st.AddMark(10);
	st.AddMark(7);
	st.Print();

	if (true)
	{
		Student st3("Olga", "Petruk", { 14,5,2000 }, "+709514782547");
		st3.Print();
	}



	
}

