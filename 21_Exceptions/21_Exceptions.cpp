#include <iostream>
using namespace std;

class List
{
    int size;
    int* arr;
public:
    int getElement(int pos)
    {
        //Code errors:
        // 1 - empty
        // 2 - pos < 0
        // 3 - pos > size
        if (size == 0) return 1;
        if (pos < 0) return 2;
        if (pos > size) return 3;

        return rand() % 10;
    }
};


float Divide(float a, float b)
{

    float res = 0;
    if (b == 0)
    {
        throw exception("Can * t divide by zero !!!");
    }
    if (b == 1)
    {
        throw 404;
    }
    if (b == 2)
    {
        throw "Can * t divide by zero !!!";
    }
    else
    {
        res = a / b;
        cout << "Result = " << res << endl;
        return res;
    }    
}

class PasswordInvalidException : public exception
{
public:
    PasswordInvalidException(const char* message) :exception(message) {}

};
class PasswordSmallException: public exception
{
    int length;
public:
    PasswordSmallException(const char * message, int length):length(length),
        exception(message){ }
    void Message()
    {
        cout << what() << endl;
        cout << "Actual lenght : " << length << endl;
    }

};

void ValidateLogin(const char* login, const char* password)
{
    if (strlen(password) < 6)
        throw PasswordSmallException("Password to small", strlen(password));
    if (!isalpha(password[0]) || !islower(password[0]))
        throw PasswordInvalidException("Password invalid!!!");
    if (!isalpha(login[0]) || !isupper(login[0]))
        throw exception("Login invalid!!!" );

    cout << "Loading................" << endl;

}
class MyArr
{
    int* arr;
    int size;
public:
    MyArr(int size = 20):size(size)
    {
        arr = new int[size] {};
    }
    ~MyArr()
    {
        delete[]arr;
    }
    void Print()const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int operator[](int index)
    {
        if (index >= 0 and index < size)
            return arr[index];
        else
            throw out_of_range("Index is less than o or more than size");
    }
    void CheckLenght(int len)
    {
        if (len < 0)
            throw length_error("Some lenght error....");
        cout << "Lenght correct " << endl;
    }
    void SetSize(int newSize)
    {
        if (newSize < 0)
            throw invalid_argument("Size less than 0.");
        else
        {
            int* temp = new int[newSize];
            for (int i = 0; i < size && i < newSize; i++)
            {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;
            size = newSize;
        }

    }

};
int main()
{
    MyArr arr;
    arr.Print();


    try
    {
        //cout << arr[100];
        //arr.CheckLenght(-10);
        arr.SetSize(-10);
    }
    catch (logic_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    



    /*

    char login[100];
    char password[100];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter login : "; cin >> login;
        cout << "Enter password : "; cin >> password;
        try
        {
            ValidateLogin(login, password);
        }
        catch (PasswordInvalidException ex)
        {
       
            cout << ex.what() << endl;
            cout << "Password start with small letter. a-z,A-Z,0-9" << endl;

        }
        catch (PasswordSmallException ex)
        {
            ex.Message();
            cout << "Password length must bemore than 6 symbols" << endl;
        }
        catch (exception ex)
        {
            cout << "Login start with big letter" << endl;
            cout << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Unknow exception" << endl;
        }
    }
    */

    /*
    //try catch throw 
    int a, b;
    cout << "Enter numbers : ";
    cin >> a >> b;

    try
    {
        float res = Divide(a, b);
        cout << "Result in main = " << res << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
    catch (int ex)
    {
        cout << ex<< endl;
    }
    catch (const char* ex)
    {
        cout << ex << endl;
    }
    catch (...)
    {
        cout << "Unknow exception" << endl;
    }
   */
}

