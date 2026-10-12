// 01_IntroToOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*
struct Player
{
    string name;
    int age;
    int games;
    int goals;
};

void PrintPlayer(Player &pl)
{
    cout << "Name : " << pl.name << endl;
    cout << "Age : " << pl.age << endl;
    cout << "Games : " << pl.games << endl;
    cout << "Goals : " << pl.goals << endl;
}
void InitPlayer(Player& pl)
{
    cout << "Enter name : "; cin >> pl.name;
    cout << "Enter age : "; cin >> pl.age;
    pl.games = 0;
    pl.goals = 0;
}
void AddGameToPlayer(Player &pl, int goals = 0)
{
    pl.games++;
    pl.goals += goals;
}

struct Player // public
{
    string name;
    int age;
    int games;
    int goals;
};
*/
class Player  //private
{
private:
    string name;
    int age;
    int games;
    int goals;
public:
    void PrintPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void InitPlayer()
    {
        cout << "Enter name : "; cin >> name;
        cout << "Enter age : "; cin >> age;
        games = 0;
        goals = 0;
    }
    void AddGameToPlayer( int goals = 0)
    {
        games++;
       // (*this).goals += goals;
        this->goals += goals;
    }
};

class Student 
{
private:
    string name;//data members. змінні-члени класу
    int marks[3];
public:
    //setter
    void setName(string name)
    {
        this->name = name;
    }
    void setMark(int index, int mark)
    {
        if (mark >= 1 and mark <= 12)
        {
            marks[index] = mark;
        }
        else
        {
            marks[index] = 0;
        }
    }

    //getter
    string getName()
    {
        return name;
    }
    int getMark(int index)
    {
        return marks[index];
    }


    double getAverageMark()// member function. функції-члени класу,методи
    {
        double summa = 0;
        for (int i = 0; i < 3; i++)
        {
            summa += marks[i];
        }
        return (double)summa / 3;
    }
};


int main()
{
    Student st;
   /* st.Init();
    st.Print();

    st.setX(100);
    st.setX(100);
    st.setX(100);
    
    cout<< st.getX()<< st.getY()*/

    st.setName("Ivan");
    st.setMark(0, 10);
    st.setMark(1, 7);
    st.setMark(2, 8);

    cout << "Name : " << st.getName() << " Marks : " << st.getMark(0) << endl;

    cout << "Average mark : " << st.getAverageMark() << endl;


 /*   Player player;
    player.InitPlayer();
    player.PrintPlayer();

    player.AddGameToPlayer(1);
    player.AddGameToPlayer(2);
    player.AddGameToPlayer(3);
    player.PrintPlayer();*/


    /*InitPlayer(player);
    PrintPlayer(player);

    AddGameToPlayer(player);
    AddGameToPlayer(player,1);
    AddGameToPlayer(player,2);
    PrintPlayer(player);*/
    



}

