#include <iostream>
using namespace std;

class Car
{
public:
	void Drive()
	{
		cout << "I drive" << endl;
	}
	void Use()
	{
		cout << "I drive" << endl;
	}
};
class Airplane
{
public:
	void Fly()
	{
		cout << "I fly" << endl;
	}
	void Use()
	{
		cout << "I fly" << endl;
	}
};
class FlyCar : public Car, public Airplane
{

};

class A {
public:
	int value;
};
class B:public A{};
class C:public A{};
class D: public B, public C
{

};
int main()
{
	D d;
	d.value = 44;
	D::value = 77;
	D::B::value = 4;
	D::C::value = 7;
	D::B::A::value = 6;
	D::C::A::value = 4;

	FlyCar car;
	car.Drive();
	car.Fly();
	((Car)car).Use();
	((Airplane)car).Use();

}

