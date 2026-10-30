#include <iostream>

using namespace std;
/*
class Stack {
    enum {EMPTY = -1, FULL = 9};
    int arr[FULL + 1];//10
    int topIndex;
public:
    //default delete
    //Stack() = default;// Stack(){}
    Stack()
    {
        topIndex = EMPTY;
    }
    Stack(const Stack& other) = delete;

    bool IsFull()
    {
        return topIndex == FULL;
    }
    bool Push(int elem) {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
    }
    int GetCount() {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
*/
class Stack
{
    enum{EMPTY = -1};
    int* arr;
    int size;//100
    int topIndex;
public:
    Stack() = delete;
    Stack(int size) : size(size)
    {
        arr = new int[size] {};
        topIndex = EMPTY;
    }
    bool IsFull()
    {
        return topIndex == size-1;
    }
    bool Push(int elem) {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
    }
    int GetCount() {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
    }
    void Print()
    {
        cout << "Capacity : " << size << endl;
        cout << "Size : " << topIndex +1 << endl;
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        if (arr != nullptr)
            delete[]arr;
    }

};
int main()
{
    Stack st(20);
   // Stack st3({ 1,5,8,9,6,7,7,8 });
    cout << "Size = " << st.GetCount() << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << st.Push(rand() % 50) << endl;;
    }
    st.Print();
    cout << "Size = " << st.GetCount() << endl;

    while (!st.IsEmpty())
    {
        cout << "Delete element : " << st.Pop() << endl;
    }
    cout << "Size = " << st.GetCount() << endl;


}

