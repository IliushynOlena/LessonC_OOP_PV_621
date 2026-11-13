#include <iostream>
#include <Windows.h>
using namespace std;


class Car
{
private:
	string model;
	int year;
	float capacity_of_engine;
protected:
	int speed;
public:
	Car():model("no model"),year(0),speed(0),capacity_of_engine(0){}
	Car(string m, int y, float c):model(m),year(y),speed(0),capacity_of_engine(c){}	
	void setSpeed(int speed)
	{
		if (speed > 0)
			this->speed = speed;
		else
			this->speed = 0;
	}
	virtual void Drive()const
	{
        cout << "I am a Car. I can drive with speed " << speed << " km/h" << endl;;
	}
	virtual void Print()const
	{
		cout << "Model : " << model << endl;
		cout << "Year : " << year << endl;
		cout << "Speed : " << speed << endl;
		cout << "Capacity engine : " << capacity_of_engine << endl;
	}
};
class PoliceCar : public Car
{
	float soundVolume;
public:
	PoliceCar() :soundVolume(0), Car() {}
	PoliceCar(string m, int y, float c, float s) :soundVolume(s), Car(m,y,c) {}
	void Drive()const override
	{
		cout << "I am a Police Car. I can drive with speed " << speed << " km/h"<<endl;
	}
	void Print()const override
	{		
		Car::Print();
		cout << "Sound volume : " << soundVolume << endl;
	}
	void BeepBeep()
	{
        Beep(330, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(392, 100); Sleep(700);
        Beep(196, 100); Sleep(700);
        Beep(262, 300); Sleep(300);
        Beep(196, 300); Sleep(300);
        Beep(164, 300); Sleep(300);
        Beep(220, 300); Sleep(100);
        Beep(246, 100); Sleep(300);
        Beep(233, 200);
        Beep(220, 100); Sleep(300);
        Beep(196, 100); Sleep(150);
        Beep(330, 100); Sleep(150);
        Beep(392, 100); Sleep(150);
        Beep(440, 100); Sleep(300);
        Beep(349, 100); Sleep(100);
        Beep(392, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(100);
        Beep(247, 100); Sleep(500);
        Beep(262, 300); Sleep(300);
        Beep(196, 300); Sleep(300);
        Beep(164, 300); Sleep(300);
        Beep(220, 300); Sleep(100);
        Beep(246, 100); Sleep(300);
        Beep(233, 200);
        Beep(220, 100); Sleep(300);
        Beep(196, 100); Sleep(150);
        Beep(330, 100); Sleep(150);
        Beep(392, 100); Sleep(150);
        Beep(440, 100); Sleep(300);
        Beep(349, 100); Sleep(100);
        Beep(392, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(100);
        Beep(247, 100); Sleep(900);
        Beep(392, 100); Sleep(100);
        Beep(370, 100); Sleep(100);
        Beep(349, 100); Sleep(100);
        Beep(311, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(207, 100); Sleep(100);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(500);
        Beep(392, 100); Sleep(100);
        Beep(370, 100); Sleep(100);
        Beep(349, 100); Sleep(100);
        Beep(311, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(523, 100); Sleep(300);
        Beep(523, 100); Sleep(100);
        Beep(523, 100); Sleep(1100);
        Beep(392, 100); Sleep(100);
        Beep(370, 100); Sleep(100);
        Beep(349, 100); Sleep(100);
        Beep(311, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(207, 100); Sleep(100);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(500);
        Beep(311, 300); Sleep(300);
        Beep(296, 300); Sleep(300);
        Beep(262, 300); Sleep(1300);
        Beep(262, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(300);
        Beep(330, 200); Sleep(50);
        Beep(262, 200); Sleep(50);
        Beep(220, 200); Sleep(50);
        Beep(196, 100); Sleep(700);
        Beep(262, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(100);
        Beep(330, 100); Sleep(700);
        Beep(440, 100); Sleep(300);
        Beep(392, 100); Sleep(500);
        Beep(262, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(300);
        Beep(330, 200); Sleep(50);
        Beep(262, 200); Sleep(50);
        Beep(220, 200); Sleep(50);
        Beep(196, 100); Sleep(700);
        /*Intro*/
        Beep(330, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(392, 100); Sleep(700);
        Beep(196, 100); Sleep(700);
        Beep(196, 100); Sleep(125);
        Beep(262, 100); Sleep(125);
        Beep(330, 100); Sleep(125);
        Beep(392, 100); Sleep(125);
        Beep(523, 100); Sleep(125);
        Beep(660, 100); Sleep(125);
        Beep(784, 100); Sleep(575);
        Beep(660, 100); Sleep(575);
        Beep(207, 100); Sleep(125);
        Beep(262, 100); Sleep(125);
        Beep(311, 100); Sleep(125);
        Beep(415, 100); Sleep(125);
        Beep(523, 100); Sleep(125);
        Beep(622, 100); Sleep(125);
        Beep(830, 100); Sleep(575);
        Beep(622, 100); Sleep(575);
        Beep(233, 100); Sleep(125);
        Beep(294, 100); Sleep(125);
        Beep(349, 100); Sleep(125);
        Beep(466, 100); Sleep(125);
        Beep(587, 100); Sleep(125);
        Beep(698, 100); Sleep(125);
        Beep(932, 100); Sleep(575);
        Beep(932, 100); Sleep(125);
        Beep(932, 100); Sleep(125);
        Beep(932, 100); Sleep(125);
        Beep(1046, 675);
	}


};
class SportCar : public Car
{
    float turboSpeed;
public:
    SportCar() :turboSpeed(0), Car() {}
    SportCar(string m, int y, float c, float s) :turboSpeed(s), Car(m, y, c) {}
    void Drive()const
    {
        cout << "I am a Sport Car. I can drive with speed " << speed << " km/h" << endl;
    }
    void Print()const override
    {
        Car::Print();
        cout << "Turbo speed : " << turboSpeed << endl;
    }
    void Nitro()
    {
        speed += turboSpeed;
        cout << "Nitro speed : "<< speed<<"km/h" << endl;
    }
  
};

void TestDrive(Car &car)
{
    car.setSpeed(70);
    car.Drive();
}
int main()
{
    Car car("BMW", 2025, 3.0);
    car.setSpeed(280);
    car.Drive();
    car.Print();
    
    cout << endl;
	PoliceCar police("Toyota",2024,3.5,1000);
    police.setSpeed(300);
    police.Drive();
    police.Print();
    //police.BeepBeep();

    SportCar sport("Formula 1", 2025, 2.6, 100);
    sport.setSpeed(150);
    sport.Nitro();
    sport.Drive();
    sport.Print();

    TestDrive(car);
    TestDrive(police);
    TestDrive(sport);

    Car* cars[3]{
        new Car("BMW", 2025, 3.0),
        new PoliceCar("Toyota",2024,3.5,1000),
        new SportCar("Formula 1", 2025, 2.6, 100)
    };

    for (int i = 0; i < 3; i++)
    {
        cars[i]->Print();
        delete cars[i];
        cout << endl << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i <= j && i + j <= 9)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

	

}

