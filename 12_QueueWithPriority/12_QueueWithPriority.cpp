#include <iostream>
using namespace std;



class QueueWithPriority
{
    struct Element {
        char letter;
        int priority;
        void Print()
        {
            cout << letter << " : " << priority << "  |  ";
        }
    };
private:
    Element* elements;
    int size;
public:
    QueueWithPriority():elements(nullptr),size(0){}
    ~QueueWithPriority()
    {
        if (elements != nullptr)
            delete[]elements;
    }
    void Enqueue(char l, int p)
    {
        int index = 0;
        while (index < size && elements[index].priority  < p){index++;}

        size++;
        Element* temp = new Element[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = elements[i];
        }
        temp[index] = Element{ l,p };
        for (int i = index+1; i < size; i++)
        {
            temp[i] = elements[i-1];
        }
        if (elements != nullptr)
            delete[]elements;
        elements = temp;

    }
    void Print()const
    {
        for (int i = 0; i < size; i++)
        {
            elements[i].Print();
        }
        cout << endl;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = elements[0];
            for (int i = 0; i < size; i++)
            {
                elements[i] = elements[i + 1];
            }
            size--;
            return first;
        }
    }



};

int main()
{
    QueueWithPriority q;

    q.Enqueue('A', 1);
    q.Enqueue('B',2);
    q.Enqueue('C',3);
    q.Enqueue('G',5);
    q.Enqueue('K',7);
    q.Print();
    q.Enqueue('D',5);
    q.Print();

    while (!q.IsEmpty())
    {
        cout << "Deleted element : ";
        q.Dequeue().Print();
        cout << endl;
        q.Print();
        cout << endl;
    }

    
}

