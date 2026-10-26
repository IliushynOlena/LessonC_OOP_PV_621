#include <iostream>
#include <vector>
using namespace std;
/*
int getMAx(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
short getMAx(short arr[], int size)
{
	short max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
long getMAx(long arr[], int size)
{
	long max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
*/
template<typename T>
T getMAx(T arr[], int size)
{
	T max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template<typename T_coll, typename T_value>
class MyClass
{
	T_coll* collection;
	int size;
	T_value value;
public:
	MyClass()
	{
		collection = nullptr;
		size = 0;
		//value = nullptr;
	}
	MyClass(T_coll* coll,int size, T_value value):collection(coll),
		size(size), value(value){}
	~MyClass()
	{
		if (collection != nullptr)
			delete[]collection;
	}
	void SetCollection(T_coll* coll);
	void SetValue(T_value value);
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << collection[i] << " ";
		}
		cout << endl;
		cout << value << endl;
	}
};

template<typename T_coll, typename T_value>
void MyClass<T_coll, T_value>::SetCollection(T_coll* coll)
{
	collection = coll;
}
template<typename T_coll, typename T_value>
void MyClass<T_coll, T_value>::SetValue(T_value value)
{
	this->value = value;
}

template<typename T_coord>
class Point {
	T_coord x;
	T_coord y;
public:
#pragma region Constructors
	Point()
	{
		x = y = 0;
	}
	Point(T_coord value)
	{
		x = y = value;
	}
	Point(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
#pragma endregion
	void Print()const
	{
		cout << "X : " << x << ". Y : " << y << endl;
	}
	void setNewCoords(T_coord newX, T_coord newY) {
		this->x = newX;
		this->y = newY;
	}
};

template<typename T_X, typename T_Y>
class NewPoint {
	T_X x;
	T_Y y;
public:
#pragma region Constructors
	NewPoint()
	{
		x = y = 0;
	}
	NewPoint(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
#pragma endregion
	void Print()const
	{
		cout << "X : " << x << ". Y : " << y << endl;
	}
	void setNewCoords(T_X newX, T_Y newY) {
		this->x = newX;
		this->y = newY;
	}
};
int main()
{
	NewPoint<float, short> p3(1.54, 25);
	p3.Print();

	Point<int> p(5, 14);
	p.Print();

	Point<float> p2(1.25, 3.25);
	p2.Print();
	p2.setNewCoords(5.35, 14.33);
	p2.Print();

	vector<int> v1 = { 1,2,3,4,5 };
	vector<string> v2 = { "red","white" };
	vector<float> v3 = { 1.1,2.2,3.3,4.4 };

	/*

	long* long_arr = new long[5];
	for (int i = 0; i < 5; i++)
	{
		long_arr[i] = i + 1;
		cout << long_arr[i] << " ";
	}
	cout << endl;
	char* char_arr = new char[5];
	for (int i = 0; i < 5; i++)
	{
		char_arr[i] = 'a' + i; 
		cout << char_arr[i] << " ";
	}
	cout << endl;

	MyClass<long,string> cl1(long_arr,5, "Class with long arr");
	MyClass<char,string> cl2(char_arr,5, "Class with char arr");

	cl1.Print();
	cl2.Print();
	*/
	//delete[] long_arr;
	//delete[] char_arr;
	/*const int size = 10;
	int arr1[size] = { 5,77,4,1,22,98,63,25,45,11 };
	short arr2[size] = { 5,77,4,1,22,98,63,25,45,11 };
	long arr3[size] = { 5,77,4,1,22,98,63,25,45,11 };
	string colors[6] = { "red","blue", "pink","green","white" };
	string names[6] = { "Vlad", "Zina","Andriy","Muxaulo","Oleksandr" };
	string letters[6] = { "leter","letter","lettter","AAAA","AAAAA","AAAAAA" };
	cout << "Max element  : " << getMAx(arr1, size) << endl;
	cout << "Max element  : " << getMAx(arr2, size) << endl;
	cout << "Max element  : " << getMAx(arr3, size) << endl;
	cout << "Max element  : " << getMAx(colors, 6) << endl;
	cout << "Max element  : " << getMAx(names, 6) << endl;
	cout << "Max element  : " << getMAx(letters, 6) << endl;*/
  
}

