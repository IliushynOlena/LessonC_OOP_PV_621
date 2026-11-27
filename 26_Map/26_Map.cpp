#include <iostream>
#include <map>
#include <list>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;

using namespace std;

// sorted binary tree
class Tree
{
	struct Node
	{
		// ключ по якому відбувається розміщення елементів
		int key;
		// дані, які зберігає елемент
		int data;

		// вказівник на лівий дочірній елемент
		Node* left;
		// вказівник на правий дочірній елемент
		Node* right;

		Node(int key, int data, Node* left = nullptr, Node* right = nullptr)
			: key(key), data(data), left(left), right(right)
		{
		}
	};

	Node* root;

	void Add(int key, int data, Node*& root)
	{
		if (root == nullptr)
		{
			root = new Node(key, data);
			return;
		}

		if (key > root->key)
			Add(key, data, root->right);
		else
			Add(key, data, root->left);
	}

	// [K]oren [L]ivii [P]ravii
	void PrintKLP(Node* elem) const
	{
		if (elem != nullptr)
		{
			// K
			std::cout << elem->key << ":" << elem->data << " ";
			// L
			PrintKLP(elem->left);
			// P
			PrintKLP(elem->right);
		}
	}
	// LKP
	void PrintLKP(Node* elem) const
	{
		if (elem != nullptr)
		{
			// L
			PrintLKP(elem->left);
			// K
			std::cout << elem->key << ":" << elem->data << " ";
			// P
			PrintLKP(elem->right);
		}
	}
	// PKL
	void PrintPKL(Node* elem) const
	{
		if (elem != nullptr)
		{
			// P
			PrintPKL(elem->right);
			// K
			std::cout << elem->key << ":" << elem->data << " ";
			// L
			PrintPKL(elem->left);
		}
	}

	int Search(int key, Node* root) const
	{
		if (root == nullptr) return 0;

		if (key > root->key)
			Search(key, root->right);
		else if (key < root->key)
			Search(key, root->left);
		else
			return root->data;
	}

public:
	Tree() : root(nullptr) {}

	void Add(int key, int data)
	{
		Add(key, data, root);
	}

	int Search(int key) const
	{
		return Search(key, root);
	}

	void PrintKLP() const
	{
		PrintKLP(root);
	}
	void PrintLKP() const
	{
		PrintLKP(root);
	}
	void PrintPKL() const
	{
		PrintPKL(root);
	}
};


map<string,int>::iterator findByValue(map<string, int>& m, int value)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (i->second == value)
			return i;
	}
	return m.end();
}
int main()
{
	/*
	Tree tree;

	tree.Add(50, 200);
	tree.Add(17, 100);
	tree.Add(12, 12);
	tree.Add(23, 5474);
	tree.Add(19, 54);
	tree.Add(14, 44);
	tree.Add(9, 10);
	tree.Add(72, 30);
	tree.Add(76, 33);
	tree.Add(54, 45);
	tree.Add(67, 11);
	tree.Add(52, 233);
	tree.Add(100, 0);

	cout << " KLP : "; tree.PrintKLP(); cout << endl;
	cout << " LKP : "; tree.PrintLKP(); cout << endl;
	cout << " PKL : "; tree.PrintPKL(); cout << endl;

	cout << tree.Search(67) << endl;

	system("pause");
	return 0;
	*/
	map<string, int> m;


	pair<string, int> p("Olga", 5);
	m.insert(p);

	m.insert(pair<string, int>("Petro", 8));

	m.insert(make_pair("Lilia", 9));
	m.insert(make_pair("Mukola", 4));

	for (auto item : m)
	{
		cout << "Key : " << item.first << " . VAlue : " << item.second << endl;
	}
	cout << endl;
	cout << endl;

	//pair<map<string,int>::iterator,bool> res = m.insert(make_pair("Mukola",1));
	auto res = m.insert(make_pair("Roman",1));
	if (res.second)
	{
		cout << "User was added!" << endl;
	}
	else {
		cout << "User was not added!" << endl;
	}

	for (auto item : m)
	{
		cout << "Key : " << item.first << " . VAlue : " << item.second << endl;
	}


	cout << "Value : " << m["Mukola"] << endl;
	cout << "Value : " << m["Olga"] << endl;

	m["Olga"] = 6;
	m["Oleksander"] = 9;
	m["Lila"] = 100;
	m["Lila"] = 10;
	cout << endl;
	for (auto item : m)
	{
		cout << "Key : " << item.first << " . VAlue : " << item.second << endl;
	}

	map<string, int>::iterator it =  m.find("Roman");
	if (it == m.end())
	{
		cout << "Element not found" << endl;
	}
	else
	{
		cout << "Key : " << it->first << " . VAlue : " << it->second << endl;
		//it->first = "Roma"; //error
		it->second++;
		cout << "Key : " << it->first << " . VAlue : " << it->second << endl;
	}
	cout << endl << endl;

	it = findByValue(m, 9);
	if( it != m.end())
		cout << "Key : " << it->first << " . VAlue : " << it->second << endl;

	if (it != m.end())
		m.erase(it);

	cout << endl;
	for (auto item : m)
	{
		cout << "Key : " << item.first << " . VAlue : " << item.second << endl;
	}


	map<string, list<string>> dic;

	dic.insert(make_pair("thanks", list<string>({ "dakyu","bydlaska","mean2" })));
	dic.insert(make_pair("tank", list<string>({ "tank1","tank2","tank3" })));
	dic.insert(make_pair("table", list<string>({ "table1","table2","table3" })));

	for (auto el : dic)
	{
		cout <<  "Key : " << left << setw(10) << el.first;
		for (string t : el.second)
		{
			cout << setw(10) << t<< " - ";
		}
		cout << endl;	

	}

	string input;
	cout << "Enter word to search : ";
	cin >> input;

		for (string t : dic[input])
		{
			cout << setw(10) << t << " - ";
		}
		cout << endl;


		cout << "Enter word to search : ";
		cin >> input;
		cin.ignore();
		if (dic.find(input) == dic.end())
			cout << "Word not found " << endl;
		else
		{
			string translate = "";
			do
			{
				cout << "Enter translate : ";
				getline(cin, translate);
				dic[input].push_back(translate);
				cout << translate.empty() << endl;

			} while (!translate.empty());
		}


		for (string t : dic[input])
		{
			cout << setw(10) << t << " - ";
		}
		cout << endl;
}