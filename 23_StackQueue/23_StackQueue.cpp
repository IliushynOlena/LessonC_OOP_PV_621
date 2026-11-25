#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
using namespace std;
class User
{
	string name;
	int rating;

	friend ostream& operator<<(ostream& os, const User& user);
public:
	User(string n, int r) : name(n), rating(r) {}
	bool operator<(const User& other) const
	{

		return this->rating < other.rating;
	}
};
ostream& operator<<(ostream& os, const User& user)
{
	os << "Name: " << user.name << " Rating: " << string(user.rating, '*');
	return os;
}
class Train
{
	struct Time { int h, m, s; };
	int number;
	Time time;
	string destination;
public:
	void Save()
	{
		ofstream out("Trains.txt");
		out << number;
		out << time.h;
		out << time.m;
		out << time.s;
		out << destination;
		out.close();

	}
};
class Railway {
	vector<Train> trains;
	void Save()
	{
		
		for (int i = 0; i < trains.size(); i++)
		{
			trains[i].Save();
		}

	}
};
int main()
{
	





	///////////////////// Stack
	

	stack<string> plates;
	stack<int> st;

	plates.push("Plate 1");
	plates.push("Plate 2");
	plates.push("Plate 3");

	stack<string> articles;
	articles.push("Article 1");
	articles.push("Article 2");

	articles.swap(plates);
	//Empty = -1, top = Empty
	while (!plates.empty())
	{
		cout << plates.top() << endl; // повертає останній елемент Peek
		plates.pop();				  // вилучає останній елемент
	}

	while (!articles.empty())
	{
		cout << articles.top() << endl; // повертає останній елемент
		articles.pop();				    // вилучає останній елемент
	}

	///////////////////////// Queue
	queue<string> clients;

	clients.push("Vitia");
	clients.push("Kolya");
	clients.push("Sofia");
	clients.push("Oksana");
	clients.push("Petro");

	cout << "First: " << clients.front() << endl;
	cout << "Last: " << clients.back() << endl;

	while (!clients.empty())
	{
		cout << "User: " << clients.front() << endl;
		clients.pop();
	}

	//////////////////////// Priority Queue
	priority_queue<string> workers;

	workers.push("Vitia");
	workers.push("Kolya");
	workers.push("Sofia");
	workers.push("Oksana");
	workers.push("Petro");

	cout << "First: " << workers.top() << endl;

	while (!workers.empty())
	{
		cout << "User: " << workers.top() << endl;
		workers.pop();
	}
	
	// users
	priority_queue<User> users;

	users.push(User("Vitia", 5));
	users.push(User("Kolya", 1));
	users.push(User("Sofia", 1));
	users.push(User("Oksana", 3));
	users.push(User("Petro", 4));

	cout << "First: " << users.top() << endl;

	while (!users.empty())
	{
		cout << "User: " << users.top() << endl;
		users.pop();
	}
	
	/////////////////////////// Dequeue
	deque<int> deck;

	deck.push_back(10);
	deck.push_back(20);
	deck.push_front(1);
	deck.push_front(2);

	while (!deck.empty())
	{
		cout << "First: " << deck.front() << endl;
		deck.pop_front();
	}
	
	system("pause");
	return 0;

}