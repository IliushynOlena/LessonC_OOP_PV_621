//#include <iostream>
//using namespace std;
//
//struct Date {
//	int day;
//	int month;
//	int year;
//	Date()
//	{
//		day = 0;
//		month = 0;
//		year = 0;
//	}
//	Date(int day, int month, int year)
//	{
//		this->day = day;
//		this->month = month;
//		this->year = year;
//	}
//	void PrintDate()
//	{
//		cout << "Birthdate : " << day << "/" 
//			<< month << "/" << year << endl;
//	}
//};
//class Student
//{
//private:
//	string name;
//	string surname;
//	Date birthdate;
//	string phone;
//	int *marks;
//	int countMark;
//	float averageMark;
//	void AverageMArk()
//	{
//		float summa = 0;
//		for (int i = 0; i < countMark; i++)
//		{
//			summa += marks[i];
//		}
//		averageMark = summa / countMark;
//	}
//public:
//	//ctor+TAB
//	Student()//method
//	{
//		cout << "Default constructor" << endl;
//		name = "no name";
//		surname = "no name";
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMark = 0;
//		averageMark = 0;
//	}
//	Student(string name, string surname,Date b, string phone)
//	{
//		cout << "Parametrized constructor" << endl;
//		this->name = name;
//		this->surname = surname;
//		this->birthdate = b;
//		this->phone = phone;
//		marks = nullptr;
//		countMark = 0;
//		averageMark = 0;
//
//	}
//	void Print()
//	{
//		cout << "Name : " << name << endl;
//		cout << "Surname : " << surname << endl;
//
//		birthdate.PrintDate();
//		cout << "Phone : " << phone << endl;
//		cout << "Marks : ";
//		for (int i = 0; i < countMark; i++)
//		{
//			cout << marks[i] << " ";
//		}
//		cout << "\nAverage Mark : " << averageMark << endl;
//		
//	}
//	void Initialization()
//	{
//		name = "no name";
//		surname = "no name";
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMark = 0;
//		averageMark = 0;
//	}
//	void setName(string name)
//	{
//		this->name = name;
//	}
//	void setSurname(string surname)
//	{
//		this->surname = surname;
//	}
//	void AddMark(int mark)
//	{
//		int *temp = new int[countMark+1];
//		for (int i = 0; i < countMark; i++)
//		{
//			temp[i] = marks[i];
//		}
//		temp[countMark] = mark;
//		if (marks != nullptr)
//		{
//			delete[]marks;
//		}
//		marks = temp;
//		countMark++;
//		AverageMArk();
//
//	}
//	~Student()
//	{
//		cout << "Destructor " << name << endl;
//		if (marks != nullptr)
//		{
//			delete[]marks;
//		}
//	}
//};
//int main()
//{
//	Student student;//Default constructor
//	//student.Initialization();
//	student.Print();
//
//	
//	student.setName("Vasia");
//	student.setSurname("Ivanchuk");
//	student.AddMark(12);
//	student.AddMark(8);
//	student.AddMark(10);
//	student.Print();
//	cout << endl<<endl;
//	Student st("Yoseph", "Petruk", { 14,5,2000 }, "+709514782547");
//	st.AddMark(8);
//	st.AddMark(6);
//	st.AddMark(10);
//	st.AddMark(7);
//	st.Print();
//
//	if (true)
//	{
//		Student st3("Olga", "Petruk", { 14,5,2000 }, "+709514782547");
//		st3.Print();
//	}
//
//
//
//	
//}
//

#include <iostream>
using namespace std;

struct Coord
{
    int x;
    int y;
};
class Human
{
    Human()
    {

    }
    ~Human()
    {

    }
};

class Rectangle
{
private:
    int width;
    int height;
    char symbol;
    Coord position;

public:
    Rectangle()
    {
        width = 5;
        height = 3;
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    Rectangle(int size)
    {
        if (size > 0)
        {
            width = size;
            height = size;
        }
        else
        {
            width = 5;
            height = 5;
        }

        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    Rectangle(int w, int h)
    {
        width = (w > 0) ? w : 5;
        height = (h > 0) ? h : 3;
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    void print()
    {
        for (int i = 0; i < position.y; i++)
            cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < position.x; j++)
                cout << ' ';

            for (int j = 0; j < width; j++)
                cout << symbol;

            cout << endl;
        }
    }
    void resize(int dh, int dw)
    {
        if (height + dh > 0 && width + dw > 0)
        {
            height += dh;
            width += dw;
        }
        else
        {
            cout << "Incorrect size!" << endl;
        }
    }
    void move(int dx, int dy)
    {
        if (position.x + dx >= 0 && position.y + dy >= 0)
        {
            position.x += dx;
            position.y += dy;
        }
        else
        {
            cout << "Incorrect coordinates!" << endl;
        }
    }

    void setSymbol(char s)
    {
        if (s != ' ')
            symbol = s;
        else
            cout << "Incorrect symbol!" << endl;
    }
};

int main()
{
    Rectangle r1;

    Rectangle r2(4);

    Rectangle r3(8, 3);

    cout << "Default rectangle:" << endl;
    r1.print();

    cout << "\nSquare rectangle:" << endl;
    r2.print();

    cout << "\nRectangle with width and height:" << endl;
    r3.setSymbol('#');
    r3.move(5, 2);
    r3.print();

    cout << "\nAfter resizing:" << endl;
    r3.resize(2, 3);
    r3.print();

    cout << "\nAfter moving:" << endl;
    r3.move(2, 1);
    r3.print();

    cout << "\nTesting incorrect size:" << endl;
    r3.resize(-100, -100);

    cout << "\nTesting incorrect coordinates:" << endl;
    r3.move(-100, -100);

}
