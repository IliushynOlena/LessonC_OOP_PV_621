#include <iostream>
using namespace std;

class Animal//abstract class
{
	string name;
	string place;
	int maxAge;
	float weight;
	int IQ;
public:
	Animal() :name("no name"), place("no place"), maxAge(0), weight(0), IQ(0) {}
	Animal(string n, string p,int a, float w, int iq) :name(n), place(p)
	{
	/*	if (a > 0) {
			maxAge = a;
		}
		else
		{
			maxAge = 0;
		}
		
		if (w > 0) {
			weight = w;
		}
		else
		{
			weight = 0;
		}
		if (iq > 0) {
			IQ = iq;
		}
		else
		{
			IQ = 0;
		}*/
		maxAge = (a > 0) ? a : 0;
		weight = (w > 0) ? w : 0;
		IQ = (iq > 0) ? iq : 0;
	
	}
	void Show()const
	{
		cout << "Name : " << name << endl;
		cout << "Place : " << place << endl;
		cout << "max Age : " << maxAge << endl;
		cout << "Weight : " << weight  << "kg" << endl;
		cout << "IQ : " << IQ << endl;
	}
	void EatFood(float weight)
	{
		cout << "I ate " << weight << " kg of foods " << endl;
		this->weight += weight;
		cout << "I weigh : " << this->weight << endl;
	}
	virtual void Move()
	{
		cout << "I am moving....." << endl;
	}
	virtual void MakeSound() = 0;//pure virtual function
};
class Lion : public Animal
{
	float runSpeed;
public:
	Lion() :runSpeed(0), Animal() {}
	Lion(string n, string p, int a, float w, int q, int r) :runSpeed(r), 
		Animal(n,p,a,w,q) {}
	void Show()
	{
		Animal::Show();
		cout << "Run speed : " << runSpeed << endl;
	}
	void Move()
	{
		cout << "I am running with speed "<< runSpeed<< "km/h" << endl;
	}
	void MakeSound() {
		cout << "Rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << endl;
	}
};
class Sheep: public Animal
{
	int distance_vision;
public:
	Sheep():distance_vision(0),Animal(){}
	Sheep(string n, string p, int a, float w, int q, int d):distance_vision(d),
		Animal(n,p,a,w,q){}
	
	void Show()
	{
		Animal::Show();
		cout << "Distance vision : " << distance_vision << "m " << endl;
	}
	void Move()
	{
		cout << "I am walking and eatig grass" << endl;
	}
	void MakeSound() {
		cout << "Beeeeee-beeeeee-beeeeee-beeee-beeee" << endl;
	}
};
class Amphibian : public Animal
{
	float swinDeep;
public:
	Amphibian() :swinDeep(0), Animal() {}
	Amphibian(string n, string p, int a, float w, int q, int s) :swinDeep(s), 
		Animal(n,p,a,w,q) {}
	void Show()
	{
		Animal::Show();
		cout << "Swim deep : " << swinDeep << "m " << endl;
	}
	void Move()
	{
		cout << "I am swimming down "<< swinDeep<< " m" << endl;
	}

};
class Frog : public Amphibian
{
public:
	Frog():Amphibian(){}
	Frog(string n, string p, int a, float w, int q, int s):Amphibian(n,p,a,w,q,s){}

	void MakeSound() {
		cout << "Kvaaaaaaa-kvaaaaaaaaaa-kvaaaaaaa" << endl;
	}
};

void RollCall(Animal& a)
{
	a.MakeSound();
	a.Move();
}
int main()
{
	Frog frog("Crazy Frog", "Lake", 3, 0.3, 20, 2);
	frog.EatFood(0.03);
	frog.Move();
	frog.MakeSound();

	Sheep sheep("Stepan", "Farm", 7, 100, 30, 50);
	sheep.EatFood(2);
	sheep.Move();
	sheep.MakeSound();


	Lion lion("Kind Lion", "Africa", 20, 100, 120, 80);
	lion.EatFood(150);
	lion.Move();
	lion.Show();
	lion.MakeSound();
	//Animal animal("Tom", "Flat", 15, 5, 87);
	//animal.EatFood(5);
	//animal.Move();
	//animal.Show();
	//animal.MakeSound();

	RollCall(frog);
	RollCall(sheep);
	RollCall(lion);

   
}

