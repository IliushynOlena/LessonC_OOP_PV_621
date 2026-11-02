#include <iostream>
#include <conio.h>
using namespace std;

class Queue {
    int* arr;
    int maxSize;
    int topIndex;
public:
    Queue() = default;
    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        topIndex = 0;
    }
    ~Queue()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    bool IsFull()const
    {
        return topIndex == maxSize;
    }
    void Enqueue(int elem)
    {
       
        if (!IsFull())
        {
            //arr[++topIndex] = elem;  <----------------
            //++topIndex  <----------------
            //arr[topIndex] = elem;  <----------------

            arr[topIndex++] = elem;

            //  arr[topIndex] = elem;
            //  topIndex++;
         
        }
    }
    bool IsEmpty()const
    {
        return topIndex == 0;
    }
   /* int Dequeue()
    {
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            topIndex--;
            return first;
        }
    }*/
    int Dequeue()//queue cycles
    {
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[topIndex - 1] = first;
            return first;
        }
    }
    int GetCount()const
    {
        return topIndex;
    }
    void Clear()
    {
        topIndex = 0;
    }
    void Show()const
    {
        for (int i = 0; i < topIndex; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    //FIFO  
    Queue q(25);
    for (int i = 0; i < 10; i++)
    {
        q.Enqueue(rand() % 50);
    }
    q.Show();
    cout << "Size : " << q.GetCount() << endl;
    while (!q.IsEmpty())
    {
        cout << "Deleted element : " << q.Dequeue() << endl;
        q.Show();
        cout << endl;
        _getch();
        system("cls");
    }
    cout << "Size : " << q.GetCount() << endl;

    

}

