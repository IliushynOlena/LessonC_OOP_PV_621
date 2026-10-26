#include <iostream>
using namespace std;

#define PI 3.14
inline void Hello()
{
	cout << "Hello" << endl;
}
class Human
{
	string name;
	int age;
	int weight;
	static int count;
public:
	//спиосок ініціалізаторів
	/*Human()
	{
		name = "no name";
		age = 0;
		weight = 0;
	}*/
	//Human() :name{ "no name" }, age{ 0 }, weight{ 0 } {}
	Human() :name("no name"), age(0), weight(0) { count++; }
	
	Human(string name): Human()
	{
		this->name = name;
		//age = 0;
		//weight = 0;
	}
	Human(string name, int age):Human(name)
	{
		//this->name = name;
		this->age = age;
		//weight = 0;
	}
	Human(string name, int age , int weight):Human(name,age)
	{
		//this->name = name;
		//this->age = age;
		this->weight = weight;
	}
	static int getCount()
	{
		return count;
	}
	void Print();
	void Test();
};

void Human::Print()
{
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
	cout << "Weight : " << weight << endl << endl;
}

void Human::Test()
{
	cout << "Hello" << endl;
	cout << "Hello" << endl;
	cout << "Hello" << endl;
	cout << "Hello" << endl;
	cout << "Hello" << endl;
	cout << "Hello" << endl;
}

int Human::count = 0;
int main()
{

	cout << "Count humans : "<< Human::getCount() << endl;
	Human h1;
	h1.Print();
	cout <<"Count humans : "<< h1.getCount() << endl;


	Human h2("Petro");
	h2.Print();
	cout << "Count humans : " << h2.getCount() << endl;

	Human h3("Inna", 17);
	h3.Print();
	cout << "Count humans : " << h3.getCount() << endl;


	Human h4("Harry", 18, 65);
	h4.Print();


	cout << "Count humans : " << h1.getCount() << endl;
	cout << "Count humans : " << h2.getCount() << endl;
	cout << "Count humans : " << h3.getCount() << endl;
	cout << "Count humans : " << h4.getCount() << endl;
	cout << "Count humans : " << Human::getCount() << endl;


	//cout<< 3.14 <<endl;

	//cout << "Hello" << endl;//Hello();

	//int a = 5;
	//cout << a << endl;
}
