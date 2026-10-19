#include <iostream>
using namespace std;

class Date {
public:
	int day;
	int month;
	int year;
	void setDate(int day)
	{
		this->day = day;
	}
	int getDate()
	{
		day ++ ;
		return day;
	}
	int getDate() const
	{
	
		return day;
	}
	void Print()const
	{
	
		cout << "Date : " << day << "/" << month << "/" << year << endl;
	}
};
class Account
{
	double sum;
	const double rate;
public:
	Account(double sum, double rate) :rate(rate)
	{
		this->sum = sum;
	}
	double getRate() const
	{
		return rate;
	}
	double getIncome()
	{
		return sum * rate / 100;
	}
	double getIncome()const
	{
		return sum * rate / 100;
	}
	double getSum() const
	{
		return sum;
	}
	double setSum()
	{
		sum += getIncome();
		return sum;
	}
};
void doSomething(long number) {}

float doSomething() { return 3.14; }

class Array 
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
	}
	~Array()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	int getSize()const
	{
		return size;
	}
	int getValue(int index)
	{
		return arr[index];
	}
	void setValue(int num, int index)
	{
		arr[index] = num;
	}
	void display(int index)const
	{
		cout << arr[index] << " ";
	}
};

void PrintArray(const Array &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.display(i);
	}
}
void Print(string str){}

class Book
{
	// variable
	public:
	void Print(){}
};

class Library {
	string name;
	Book* books;
	int count;
	void PrintAllBooks()
	{
		for (int i = 0; i < count; i++)
		{
			books[i].Print();
			//if (books[i].getname() == name)
		}
	}
	void AddBook(Book b){}

};
int main()
{
	int size = 5;
	Array arr(size);
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.setValue(size - i, i);
	}
	PrintArray(arr);
	cout << "\n!!!!!!!!!!!!!!!!!!!!!" << endl;

	//PrintArray(8);// implicit int ---> Array

	//Array a = 100;// implicit int ---> Array
	//Array a = "Hello";// implicit int ---> Array
	//PrintArray(a);



	////implicit    explicit

	//int a = 3.14;// implicit double ---> int
	//cout << a << endl;

	//double b = 10;// implicit int >>> double
	//cout << b << endl;

	//doSomething(5);//implicit int ---> long
	/*
	Account account1(2000, 5);

	const Account account2(5000, 8);

	cout << account1.getRate() << endl;
	cout << account2.getRate() << endl;

	cout << account1.getSum() << endl;
	cout << account2.getSum() << endl;

	cout << account1.getIncome() << endl;
	cout << account2.getIncome() << endl;

	cout << account1.setSum() << endl;
	//cout << account2.setSum() << endl;
	*/

	/*
	const int size = 5;
	const string str{ "hello" };
	const int days[] = {31,30,31};
	//days[0] = 45;

	Date holidayDate = { 26,10,2026 };
	holidayDate.Print();
	holidayDate.day = 31;
	holidayDate.Print();
	holidayDate.setDate(19);
	holidayDate.Print();
	holidayDate.getDate();

	const Date independencyDay = { 24,8,2027 };
	independencyDay.getDate();
	/*independencyDay.Print();
	independencyDay.day = 31;
	independencyDay.setDate(19);
	//independencyDay.Print();*/


}
