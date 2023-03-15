#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int end = 0;
    int *arr = (int *)malloc(size * sizeof(int));

public:
    Stack(int sz)
    {
        size = sz;
    }

    bool isFull()
    {
        return (this->end == this->size);
    }

    bool isEmpty()
    {
        return (this->end == 0);
    }

    void showSize()
    {
        cout << this->size;
    }

    void insert(int value)
    {
        if (!(this->isFull()))
        {
            this->arr[this->end] = value;
            this->end++;
        }

        else
        {
            cout << "stack overflow\n";
        }
    }

    void peek()
    {
        if (this->isEmpty())
        {
            cout << "stackunserflow\n";
        }
        else
        {
            cout << (this->arr)[this->end - 1] << "\n";
        }
    }

    int pop()
    {

        if (this->isEmpty())
        {
            cout << "stackunderflow\n";
            return -1;
        }

        else
        {
			cout<<"Else entered in pop\n";
            int x = this->arr[this->end - 1];
            this->end--;
			cout<<"x: "<<x<<"from function\n";
            return x;
        }
    }
};

int main()
{
    cout << "Entering main\n";
    Stack s = Stack(4);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.peek();
    int x = s.pop();
//    return 0;
     cout << s.pop() << endl;
    s.peek();

    return 0;
}