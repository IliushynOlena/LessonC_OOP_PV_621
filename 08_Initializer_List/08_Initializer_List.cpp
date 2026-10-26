#include <iostream>
using namespace std;


class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size] {};
	}
	Array(initializer_list<int> list)
	{
		this->size = list.size();
		arr = new int[size];
		int i = 0;
		for (int elem : list)
		{
			arr[i] =elem;
			i++;
		}
	}
	void Fill(initializer_list<int> list);
	~Array()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	
};
int main()
{
	int static_arr[5] = { 1,2,3,4,5 };
	int* dynam_arr = new int[5] {5, 4, 3, 2, 1};


	Array arr(10);
	arr.Print();


	Array arr2({ 5, 7, 8, 9, 6, 2, 4, 8 ,77,88,99,111});
	arr2.Print();

	arr2.Fill({ 3,2,1 });
	arr2.Print();

	delete[]dynam_arr;
}

inline void Array::Fill(initializer_list<int> list)
{
	if (arr != nullptr)
		delete[]arr;
	this->size = list.size();
	arr = new int[size];
	int i = 0;
	for (int elem : list)
	{
		arr[i] = elem;
		i++;
	}
}
