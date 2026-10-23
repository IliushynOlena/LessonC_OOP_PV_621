#include <iostream>
#include <Windows.h>
using namespace std;

class Point {
    int x;
    int y;
public:
#pragma region Constructors
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        x = y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
#pragma endregion
#pragma region Functions
    void Print()const
    {
        cout << "X : " << x << ". Y : " << y << endl;
    }
    Point Plus(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
#pragma endregion
#pragma region Binary Operators
    //overload operators
   //void  operator symbol (){}
    Point operator +(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator -(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other)const
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator /(const Point& other)const
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
    Point operator += (const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator = (const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

#pragma endregion
#pragma region Uno Operators
    Point operator -()const
    {
        //Point res(this->x* -1, this->y * -1);
        //return res;
        return Point(-x, -y);
    }
   
    Point operator --()
    {
        --this->x;
        --this->y;
        return *this;  
    }
    Point operator ++(int k)
    {
        this->x++;
        this->y++;
        return *this;// int a = 5; a++; // a = a + 1    
    }
    Point operator --(int)
    {
        this->x--;
        this->y--;
        return *this;
    }
#pragma endregion
#pragma region Logic Operators 
   
    bool operator > (const Point& other)const
    {
       /* if ((this->x + this->y) > (other.x + other.y))
            return true;
        else
            return false;*/
        return  ((this->x + this->y) > (other.x + other.y));
    }
    bool operator < (const Point& other)const
    {
        return  ((this->x + this->y) < (other.x + other.y));
    }
  
    bool operator <= (const Point& other)const
    {
        return  ((this->x + this->y) <= (other.x + other.y));
    }
    bool operator == (const Point& other)const
    {
        return  ((this->x == other.x) && (this->y == other.y));
    }
    bool operator != (const Point& other)const
    {
        //return  ((this->x != other.x) || (this->y != other.y));
        return !(*this == other);
    }
#pragma endregion
    int getX()const{ return x;}
    int getY()const{ return y;}
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void ChangeParameters(int value)
    {
        this->x += value;
        this->y += value;
    }
    friend Point operator ++(Point& point);
    friend ostream& operator << (ostream& out, const Point& point);
    friend istream& operator >> (istream& in,  Point& point);
};


bool operator >= (const Point& left, const Point& right)
{
    return  ((left.getX() + left.getY()) >= (right.getX() + right.getY()));
}
//Point operator ++(Point& point)
//{
//    point.setX(point.getX()+1);
//    point.setY(point.getY()+1);
//    return point; 
//}
Point operator ++(Point& point)
{
    point.x++;
    point.y++;
    return point; 
}
ostream& operator << (ostream& out, const Point& point)
{
    out << "[" << point.x << "] " << "[" << point.y << "]";
    return out;
}
istream& operator >> (istream& in, Point& point)
{
    in >> point.x;
    in >> point.y;
    return in;
}

class ShopPoint
{
    Point* points;
    int size;
public:
    ShopPoint()
    {
        points = nullptr;
        size = 0;
    }
    void AddPoint(Point p)
    {
        Point* temp = new Point[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = points[i];
        }
        temp[size] = p;

        if (points != nullptr)
            delete[]points;

        points = temp;
        size++;
    }
    ~ShopPoint()
    {
        if (points != nullptr)
            delete[]points;
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << points[i]<<endl;
        }
    }
    Point getPoint(int index)//555
    {
        if (index >= 0 && index < size)
            return points[index];
    }
    Point operator[](int index)//555
    {
        if (index >= 0 && index < size)
            return points[index];
    }
    void changePoints(int value)
    {
        for (int i = 0; i < size; i++)
        {
            points[i].ChangeParameters(value);
        }
    }
    void operator()(int value)
    {
        for (int i = 0; i < size; i++)
        {
            points[i].ChangeParameters(value);
        }
    }
    void operator()(int value, int index)
    {
        for (int i = 0; i < size; i++)
        {
            if (i == index)
                points[i].ChangeParameters(value);
        }
    }
};

int main()
{
    ShopPoint shop;
    shop.AddPoint(Point(5, 7));
    shop.AddPoint(Point(15, 71));
    shop.AddPoint(Point(45, 87));
    shop.AddPoint(Point(25, 73));
    shop.Print();
    cout << endl << endl;
    cout << shop.getPoint(0) << endl << endl;
    cout << shop[1] << endl << endl;

    shop.changePoints(10);
    shop.Print();

    shop(100);
    shop.Print();
    shop(555, 0);
    shop.Print();
   /* int sec = 0;
    while (true)
    {
        cout << sec << endl;
        sec++;
        Sleep(1000);

    }*/

    // 5555 sec
    // int hour/3600  = 1
    // minutes/60%60
    // seconds %60  5555/60 = 92   92*60 = 5520  5555-5520 = 35
    // 
    // + - * /  %  =  +=  -= *= /=  ||  && ! | &  <<   >> 
    // -5   +5  ++ -- < >  <= >=  !=  ==  ~

    // 10:55:55
    // 13:45:45
    //-----------
    // 23:100:100
    // 
    // 
    //// 8:9:10
    //int a = 5, b = 4, c = 8;
    //cout << a + b << endl;//9

    //a += b;

    //a = 100;
    //a = b = c;//<-------------


    //cout << a - b << endl;
    //cout << a * b << endl;
    //cout << a / b << endl;

    Point p1(2, 5);
    Point p2(4, 8);
    //ostream cout;
    //istream cin;
    cout << p1 << endl<< p2 << endl;

    cout << "Enter point from keyboard : ";
    cin >> p1;
    cout << p1 << endl;



    p1.Print();
    p1++;//postfix form increment
    p1.Print();
    p1--;//postfix form decrement
    p1.Print();
    ++p1;//prefix form increment
    p1.Print();
    --p1;//prefix form decrement
    p1.Print();
    p2.Print();
    if (p1 >= p2)
        cout << "p1 >= p2" << endl;
    else
        cout << "p1 <= p2" << endl;








    /*
    Point res = p1.Plus(p2);

    res = p1 + p2;//    p1.operator+(p2);

    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();
    cout << "Res : "; res.Print();

    res = p1.Minus(p2);
    cout << "Res : "; res.Print();

    res = p1 + p2;//res = p1.operator+(p2);
    cout << "Res : "; res.Print();

    res = p1 - p2;// res = p1.operator-(p2);
    cout << "Res : "; res.Print();

    res = p1 * p2;// res = p1.operator*(p2);
    cout << "Res : "; res.Print();

    res = p1 / p2;// res = p1.operator/(p2);
    cout << "Res : "; res.Print();

   


    cout << "-----------------------" << endl;
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();

    p1 += p2;
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();

    res = -p1;
    cout << "Res : "; res.Print();
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();


    res = p1 = p2;
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();
    cout << "Res : "; res.Print();

    if (p1 > p2)
        cout << "p1 > p2" << endl;
    else
        cout << "p1 < p2" << endl;

    if (p1 < p2)
        cout << "p1 < p2" << endl;
    else
        cout << "p1 > p2" << endl;

    if (p1 == p2)
        cout << "p1 == p2" << endl;
    else
        cout << "p1 != p2" << endl;
        */
    //p1 + p2;
    //p1 - p2;
    //p1 * p2;
    //p1 / p2;
    




}

