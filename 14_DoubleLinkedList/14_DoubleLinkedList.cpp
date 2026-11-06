
#include <iostream>
using namespace std;


template<typename T>
class List
{
	struct Node
	{
		Node* prev;
		T value;
		Node* next;
		Node() :prev(nullptr),value(0), next(nullptr) {}
		Node(Node* prev,T value, Node* next) :prev(prev),value(value), next(next) {}
	};

	Node* head;
	Node* tail;
public:
	List()
	{
		head = tail = nullptr;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void AddToHead(T value)
	{
		Node* newNode = new Node(nullptr, value, head);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}		
	}
	void PrintList()
	{
		//Node* current = head;//int i = 0;
		//while (current != nullptr)// i < 10
		//{
		//	cout << current->value << " ";
		//	current = current->next;//i++;
		//}
		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->value << " ";
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
	void AddToTail(T value)
	{
		Node* newNode = new Node(tail, value, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		if (IsEmpty())return;
		if (tail->prev == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		
	}
	void DeleteFromHead() {

	}
};

struct Vagon {

};
class Train {
	List<Vagon> vagons;
	void ShowAllVagons()
	{
		vagons.PrintList();
	}
};

int main()
{
	List<int> l;
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

