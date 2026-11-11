#include <iostream>
using namespace std;
class train;
template<typename T>
class list
{
	struct node
	{
		node* previous;
		T value;
		node* next;
		node() :value(T()), previous(nullptr), next(nullptr) {}
		node(node* previous, T value, node* next) :value(value), previous(previous), next(next) {}
	};
	node* head;
	node* tail;
public:
	list()
	{
		head = tail = nullptr;
	}
	void addtohead(T value)
	{
		node* newnode = new node(nullptr, value, head);
		if (head == nullptr)
			head = tail = newnode;
		else
			head->previous = newnode;
		head = newnode;
	}
	void printlist()
	{
		for (node* i = head; i != nullptr; i = i->next)
			cout << i->value << " ";

		cout << endl;
	}
	~list()
	{
		node* current = nullptr;
		while (current != nullptr)
		{
			current = head;
			head = current->next;
			delete current;
		}
	}
	void addtotail(T value)
	{
		node* newnode = new node(tail, value, nullptr);
		if (head == nullptr)
			head = tail = newnode;
		else
		{
			tail->next = newnode;
			tail = newnode;

		}

	}
	T getelement(int pos)
	{
		int  i = 0;
		node* current = head;
		while (current != nullptr)
		{
			if (i == pos - 1)return current->value;
			current = current->next;
			i++;
		}
	}
	void deletefromtail()
	{
		if (tail == nullptr)return;
		if (tail->previous == nullptr)
		{
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->previous;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	void deletefromhead()
	{
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->previous;
			head->previous = nullptr;
		}
	}
	void addtoposition(int pos, T value)
	{
		node* current = head;
		if (pos == 0)
		{
			addtohead(value);
			return;
		}

		for (int i = 0; i < pos - 1; i++)
		{
			if (current == nullptr)
			{
				cout << "Error: position out of range" << endl;
				return;
			}
			current = current->next;
		}
		if (current->next != nullptr) {
			node* newnode = new node(current, value, current->next);
			current->next->previous = newnode;
			current->next = newnode;

		}
		else {
			addtotail(value);
		}
	}
	void deletefromposition(int pos)
	{
		node* current = head;
		if (pos == 0)
		{
			deletefromhead();
			return;
		}

		for (int i = 0; i < pos - 1; i++)
		{
			if (current == nullptr)
			{
				cout << "Error: position out of range" << endl;
				return;
			}
			current = current->next;
		}

		current->previous->next = current->next;
		current->next->previous = current->previous;
		delete current;

	}
};
class vagon
{
	int nomer;
	int passagers;
	int maxpassagers;

public:
	friend ostream& operator<<(ostream& out, const vagon& v);
	friend train;
	vagon() :nomer(0), passagers(0), maxpassagers(0) {}
	vagon(int nomer, int passagers, int maxpassagers) :nomer(nomer), passagers(passagers), maxpassagers(maxpassagers) {}
};
class train
{
	int numberoffvagons;
	list <vagon> vagons;
public:
	string name;
	train()
	{
		numberoffvagons = 0;
		name = " ";
	}
	void addvagontobeginningself()
	{
		vagon new_vagon;
		cout << "Enter vagon number: "; cin >> new_vagon.nomer;
		cout << "Enter number of passengers: "; cin >> new_vagon.passagers;
		cout << "Enter maximum number of passengers: "; cin >> new_vagon.maxpassagers;
		vagons.addtohead(new_vagon);
		numberoffvagons++;
	}
	void addvagontoendself()
	{
		vagon new_vagon;
		cout << "Enter vagon number: "; cin >> new_vagon.nomer;
		cout << "Enter number of passengers: "; cin >> new_vagon.passagers;
		cout << "Enter maximum number of passengers: "; cin >> new_vagon.maxpassagers;
		vagons.addtotail(new_vagon);
		numberoffvagons++;
	}
	void addvagontoend(vagon p)
	{
		vagons.addtotail(p);
		numberoffvagons++;
	}
	void addvagontobeginning(vagon p)
	{
		vagons.addtohead(p);
		numberoffvagons++;
	}
	void deletevagonfrombeginning()
	{
		vagons.deletefromhead();
		numberoffvagons--;
	}
	void deletevagonfromend()
	{
		vagons.deletefromtail();
		numberoffvagons--;
	}
	void showvagon()
	{
		cout << "Train name: " << name << endl;
		cout << "Number of wagons: " << numberoffvagons << endl;
		vagons.printlist();
	}
	void deletevagonfromposition(int pos)
	{
		vagons.deletefromposition(pos);
		numberoffvagons--;
	}
	void addvagontoposition(vagon p, int pos)
	{
		vagons.addtoposition(pos, p);
		numberoffvagons++;
	}
	void Addvagontopositionself()
	{
		int pos;
		cout << "Enter position to add: ";
		cin >> pos;
		vagon new_vagon;
		cout << "Enter vagon number: "; cin >> new_vagon.nomer;
		cout << "Enter number of passengers: "; cin >> new_vagon.passagers;
		cout << "Enter maximum number of passengers: "; cin >> new_vagon.maxpassagers;
		vagons.addtoposition(pos, new_vagon);
		numberoffvagons++;
	}
};
ostream& operator<<(ostream& out, const vagon& v)
{
	out << "Vagon number: " << v.nomer << endl;
	out << "Passengers: " << v.passagers << endl;
	out << "Maximum passengers: " << v.maxpassagers << endl;
	return out;
}
int main()
{
	/*list<int> l;
	l.printlist();
	for (int i = 0; i < 10; i++)
	{
		l.addtotail(i);
	}
	l.printlist();
	l.deletefromhead();
	l.printlist();*/

	train t;
	cout << "Enter train name: "; cin >> t.name;
	t.addvagontobeginningself();
	t.addvagontoendself();
	t.addvagontobeginningself();
	t.showvagon();
	int pos;
	cout << "Enter position to delete from: ";
	cin >> pos;
	t.deletevagonfromposition(pos);
	t.showvagon();
	vagon v;

	
	t.Addvagontopositionself();
	t.showvagon();
	t.deletevagonfromend();
	t.showvagon();
}