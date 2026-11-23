#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v1, vector<int> v2)
{
	cout << "Vector 1 : ";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "Vector 2 : ";
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	cout << endl;
}
int main()
{

	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	vector<int> v2 = { 10,11,12,13 };

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	v[0] = 88;
	for (int item : v)
	{
		cout << item << " ";
	}
	cout << endl;
	PrintVector(v, v2);

	
	v.erase(v.begin());
	PrintVector(v, v2);
	v.erase(v.begin() + 2);
	PrintVector(v, v2);
	v.erase(v.begin(), v.begin() + 4);
	PrintVector(v, v2);

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	//int a = 5; int * pa = &a;
	vector<int>::iterator pointer;
	pointer = v.end();
	v.erase(pointer-1);
	PrintVector(v, v2);


	v.insert(v.end(), 777);
	PrintVector(v, v2);
	v.insert(v.begin(), { 11,22,33,44 });

	PrintVector(v, v2);

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin() + 3, 5, 88);
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.end(), v2.begin() + 1, v2.end() - 1);
	PrintVector(v, v2);

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.push_back(222);
	v.push_back(222);
	v.push_back(222);
	PrintVector(v, v2);

	v.pop_back();
	v.pop_back();
	PrintVector(v, v2);

	v.swap(v2);
	PrintVector(v, v2);

	cout << "First element : " << v.front() << endl;
	cout << "Last element : " << v.back() << endl;

	//v.resize(50);
	v.resize(50,5);
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;


	v.push_back(222);
	v.push_back(222);
	v.push_back(222);
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.resize(5);
	PrintVector(v, v2);
	v.shrink_to_fit();
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;





  


}

