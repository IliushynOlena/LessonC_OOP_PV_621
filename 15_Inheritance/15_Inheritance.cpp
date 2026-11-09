#include <iostream>
using namespace std;

class Enemy {
    string name;
    float hp;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy():name("no name"),hp(maxHealth),strength(0){}
    Enemy(string n, float s):name(n),hp(maxHealth),strength(s){}
    void Print()const
    {
        cout << "Name :" << name << endl;
        cout << "Hp :" << hp <<"%" << endl;
        cout << "Strength :" << strength << endl;
    }
    void DecreaseHealth(int value)
    {
        if (hp - value < 0)
            hp = 0;
        else
            hp -= value;
    }
    bool IsAlive()
    {
        return hp > 0;
    }
    void IncreaseHealth(int value)
    {
        hp += value;
    }
    float Attack()
    {
        cout << "Attacking with strength " << strength << endl;
        return strength;
    }
    void Fight(int damage)
    {
        cout << "Getting damage " << damage << "%" << endl;
        DecreaseHealth(damage);
        cout << "Health after damage : " << hp << "%" << endl;
    }
    
};
//Inheritance 
//class Child :[spetificator] Parent
//[spetificator]- public protected private
class Dragon : public Enemy
{
    float armor;
public:
    Dragon() :armor(0), Enemy() {}
    Dragon(string n, float s, float a) :armor(a), Enemy(n,s) {}
    void Fight(int damage)
    {
        Enemy::Fight(damage - armor);
    }
    void Print()const
    {
        cout << "----------------------Dragon-----------------" << endl;
        Enemy::Print();
        cout << "Armor " << armor << endl;

    }
};

class Monster: public Enemy
{
    float runSpeed;
public:
    Monster():runSpeed(0),Enemy(){}
    Monster(string n, float s, float r):runSpeed(r),Enemy(n,s){}
    void Print()const
    {
        cout << "----------------------Monster-----------------" << endl;
        Enemy::Print();
        cout << "Run speed " << runSpeed << endl;
    }
    void Run()
    {
        cout << "I am monster. I run with speed " << runSpeed << "km/h" << endl;
    }

};
int main()
{
    Dragon dragon("Oleg",10,5);
    dragon.Print();

    Dragon boss("Boss", 11, 4);
    boss.Print();
    int i = 1;
    do
    {
        cout << "---------------Round " << i << "----------------" << endl;
        dragon.Fight(boss.Attack());
        boss.Fight(dragon.Attack());
        i++;

    } while (boss.IsAlive()&&dragon.IsAlive());


   

    dragon.Print();
    boss.Print();


    Monster monster("Comunagi",4,250);
    monster.Run();
    monster.Print();

   
}
