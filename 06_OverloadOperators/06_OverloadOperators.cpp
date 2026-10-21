#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
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
    void Print()
    {
        cout << "X : " << x << ". Y : " << y << endl;
    }
    Point Plus(const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    //overload operators
    //void  operator symbol (){}
    Point operator +(const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator -(const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other)
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator /(const Point& other)
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
    Point operator -()
    {
        //Point res(this->x* -1, this->y * -1);
        //return res;
        return Point(-x, -y);
    }
    Point operator = (const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
    bool operator > (const Point& other)
    {
       /* if ((this->x + this->y) > (other.x + other.y))
            return true;
        else
            return false;*/
        return  ((this->x + this->y) > (other.x + other.y));
    }
    bool operator < (const Point& other)
    {
        return  ((this->x + this->y) < (other.x + other.y));
    }
    bool operator >= (const Point& other)
    {
        return  ((this->x + this->y) >= (other.x + other.y));
    }
    bool operator <= (const Point& other)
    {
        return  ((this->x + this->y) <= (other.x + other.y));
    }
    bool operator == (const Point& other)
    {
        return  ((this->x == other.x) && (this->y == other.y));
    }
    bool operator != (const Point& other)
    {
        //return  ((this->x != other.x) || (this->y != other.y));
        return !(*this == other);
    }
};
int main()
{
    // 5555 sec
    // int hour/3600  = 1
    // minutes/60%60
    // seconds %60  5555/60 = 92   92*60 = 5520  5555-5520 = 35
    // 
    // + - * /  %  =  +=  -= *= /=  ||  && ! | &  <<   >> 
    // -5   +5  ++ -- < >  <= >=  !=  ==  ~

    // 15:55:55
    //13:45:45
    //-----------
    // //28:100:100
    // 8:9:10
    int a = 5, b = 4, c = 8;
    cout << a + b << endl;//9

    a += b;

    a = 100;
    a = b = c;//<-------------


    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    Point p1(2, 5);
    Point p2(4, 8);

    Point res = p1.Plus(p2);
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

    //p1 + p2;
    //p1 - p2;
    //p1 * p2;
    //p1 / p2;
    




}

