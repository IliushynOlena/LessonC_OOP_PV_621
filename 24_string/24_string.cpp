#include <iostream>
using namespace std;

int main()
{
	string name = "Ivan";
	string lastname = "Oliunuk";

	lastname += "!!!!!!!!!!!!!!!!!!!!!";
	cout << lastname << endl;

	string one("Hello world");
	cout << one << endl;

	string two(20, '$');
	cout << two << endl;

	string three(one);
	cout << three << endl;

	one += " Opppsss !!!";
	cout << one << endl;

	two = "Sorry !!! ";
	cout << two << endl;

	string four = one + two;
	cout << four << endl;

	char alls[] = "All's well that end well";
	string  five(alls);
	cout << five << endl;

	string  six(alls, 20);
	cout << six << endl;

	string  seven(alls+6, alls +10);//alls --> 0a2a2a2
	cout << seven << endl;

	string  eight(&alls[6], &alls[10]);//alls --> 0a2a2a2
	cout << seven << endl;

	string nine(five, 7, 16);
	cout << nine << endl;

	cout << five << endl;
	for (int i = 0; i < five.size(); i++)
	{
		cout << five[i] << " ";
	}
	cout << "\n--------------------------" << endl;
	for (char s : five)
	{
		cout << s << " ";
	}
	cout << "\n--------------------------" << endl;
	for (auto i = five.begin(); i != five.end(); i++)
	{
		cout << *i << " ";
	}
	int a = 5;
	auto b = 7;
	float c = 3.4;
	auto d = 3.33;

	const char c_str[] = "Hello";
	string str = "hello world!";

	cout << "\nSize : " << str.size() << endl;
	cout << "Capacity : " << str.capacity() << endl;
	cout << "Lenght : " << str.length() << endl;

	//str.clear();

	if (str.empty())
		cout << "Str is empty" << endl;


	cout << "\nSize : " << str.size() << endl;
	cout << "Capacity : " << str.capacity() << endl;

	str[0] = 'H';
	cout << str[0] << endl;
	cout << str << endl;

	str.append(str.begin() + 3, str.end());
	cout << str << endl;

	str.append(" end ");
	cout << str << endl;

	str.append(c_str, 3);
	cout << str << endl;

	str.append({ 'f','g','h' });
	cout << str << endl;

	str += "aaaaaa";
	cout << str << endl;

	str.insert(str.begin(), 'H');
	cout << str << endl;

	str.insert(0, 5, 'G');
	cout << str << endl;

	str.insert(2, "OOOO");
	cout << str << endl;

	str.insert(str.begin(), str.begin(), str.end());
	cout << str << endl;

	str.erase(str.begin());
	cout << str << endl;

	str.erase(str.begin() + 15, str.begin() + 20);
	cout << str << endl;

	//str.erase(0, 15);
	//cout << str << endl;

	//str.erase(10);
	//cout << str << endl;

	//str.erase();
	//cout << str << endl;

	str.replace(0, 15, "Yes");
	cout << str << endl;

	const char * arr = str.c_str();
	cout << arr << endl;


	cout << "Find element : " << str.find('q') << endl;

	if (str.find('q') == string::npos)
		cout << "Letter not found" << endl;
	cout << "Find element : " << str.find('o') << endl;
	cout << "Find element : " << str.rfind('o') << endl;

	cout << "Find element : " << str.find_first_of("abcd") << endl;
	cout << "Find element : " << str.find_last_of("abcd") << endl;

	cout << "Find element : " << str.find_first_not_of("abcd") << endl;
	cout << "Find element : " << str.find_last_not_of("abcd") << endl;

	cout << "Substring : " << str.substr(7, 8) << endl;

	
}
