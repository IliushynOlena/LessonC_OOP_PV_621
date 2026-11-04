
#include <iostream>
using namespace std;



class List
{
	struct Node
	{
		int value;
		Node* next;
		Node() :value(0), next(nullptr) {}
		Node(int value, Node* next) :value(value), next(next) {}
	};
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(value, head);
		//newNode->value = value;
		//newNode->next = head;
		head = newNode;
	}
	void PrintList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(int value)
	{
		Node* newNode = new Node(value, nullptr);

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	int GetElement(int pos)
	{
		int  i = 0;
		Node* current = head;
		while (current != nullptr)
		{
			if (i == pos - 1)return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
};

class Point {

};
class Vector
{
	//List<Point> list;//Point* points;
	List list;//Point* points;
	int size;
	void AddPoint(){list.}
};
int main()
{
	List l;
	/* for (int i = 0; i < 10; i++)
	 {
		 l.AddToHead(i);
	 }
	 l.PrintList();*/
	l.AddToTail(100);
	l.AddToTail(200);
	l.AddToTail(300);
	l.PrintList();
	cout << "Get second element : " << l.GetElement(2) << endl;
	l.DeleteFromTail();
	l.PrintList();
	l.DeleteFromTail();
	l.PrintList();
	l.DeleteFromTail();
	l.PrintList();
}

