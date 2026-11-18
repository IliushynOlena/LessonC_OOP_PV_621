#include <iostream>
using namespace std;

enum Type{None, Standart, XL, XXL};
class Cartridge
{
	string color;
	float volume;
	Type type;
public:
	Cartridge() :color("none"), volume(0), type(None) {}
	Cartridge(string c, float v, Type t) :color(c), volume(v), type(t) {}
	void ShowInfo()const
	{
		cout << "Color : " << color << endl;
		cout << "Volume : " << volume << endl;
		cout << "Type : " ;
		switch (type)
		{
		case None:cout << "None" << endl;break;
		case Standart:cout << "Standart" << endl;break;
		case XL:cout << "XL" << endl;break;
		case XXL:cout << "XXL" << endl;break;
		}
	}
	
};

class Scanner
{
	float scanResolution;
	float height, width;
public:
	Scanner():scanResolution(0),height(0),width(0){}
	Scanner(float s,float h, float w):scanResolution(s),height(h),width(w){}
	void ShowInfo()const
	{
		cout << "Scan revolution : " << scanResolution << endl;
		cout << "Scan area  : " << height <<" x " << width<< endl;
	}
	
};
class Printer
{
	string model;


	Cartridge* cartridges;
	int countCartridges;

	Scanner scanner;//default c-tor

	//Aggregation
	Document* doc;
public:
	Printer() :model("none"), cartridges(nullptr), countCartridges(0),doc(nullptr) {}
	Printer(string model, float s, float h, float w):doc(nullptr)
	{
		this->model = model;

		countCartridges = 4;
		cartridges = new Cartridge[countCartridges];
		cartridges[0] = Cartridge("Red", 300, Type::Standart);
		cartridges[1] = Cartridge("Green", 300, Type::Standart);
		cartridges[2] = Cartridge("Blue", 300, Type::Standart);
		cartridges[3] = Cartridge("Black", 300, Type::Standart);

		scanner = Scanner(s, h, w);
	}
	void AddDocument(Document *doc) {
		this->doc = doc;

	}
	~Printer()
	{
		if (cartridges != nullptr)delete[]cartridges;
	}
	void Scan()
	{
		cout << "Scanning............" << endl;
	}
	void PrintDocument()
	{
		cout << "Printing document.........." << endl;
		doc->ShowInfo();
	}
	void PrintSettings()
	{
		cout << "Print settings : " << endl;
		for (int i = 0; i < countCartridges; i++)
		{
			cartridges[i].ShowInfo();

		}
		cout << endl;
		cout << "Scan settings : " << endl;
		scanner.ShowInfo();
	}
	
};

class Document {
	string name;
	string format;
	int pages;
public:
	Document() :name("none"), format("none"), pages(0) {}
	Document(string n, string f,int p) :name(n), format(f), pages(p) {}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Format : " << format << endl;
		cout << "Pages : " << pages << endl;
	}

	
};
int main()
{
	Printer printer("HP", 300, 30, 50);
	printer.Scan();
	printer.PrintDocument();
	printer.PrintSettings();

	Document doc1("Passport", "A5", 2);
	Document doc2("C++ for begginers", "A4", 1520);

	printer.AddDocument(&doc1);
	printer.PrintDocument();

	printer.AddDocument(&doc2);
	printer.PrintDocument();





}

