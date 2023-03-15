#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int front = -1;
    int rear = -1;
    int cap;
    int *arr = (int *)malloc(cap * sizeof(int));
    // int *arr = new int(cap);
public:
    Queue(int cap)
    {
        this->cap = cap;
    }

    bool isempty()
    {
        return ((this->front == -1) && (this->rear == -1));
    }

    bool isfull()
    {
        return (this->rear + 1) % this->cap == this->front;
    }

    void enqueue(int val)
    {
        if (this->isfull())
        {
            cout << "queue full";
        }
        else if (this->isempty())
        {
            this->front = 0;
            this->rear = 0;
            this->arr[rear] = val;
        }
        else
        {
            this->rear = (this->rear + 1) % (*this).cap;
            this->arr[this->rear] = val;
        }
    }

    int dequeue()
    {
        int x = -1;
        if (this->isempty())
        {
            cout << "queue empty";
        }
        else if (this->front == this->rear)
        {
            this->arr[this->front] = 0;
            x = arr[this->front];
            this->front = -1;
            this->rear = -1;
        }
        else
        {
            x = arr[this->front];
            this->arr[this->front] = 0;
            this->front = (this->front + 1) % this->cap;
        }
        return x;
    }

    void display()
    {
        if (this->isempty())
        {
            cout << "queue empty";
        }

        else
        {
            for (int i = 0; i < this->cap; i++)
            {
                cout << this->arr[i] << " ";
            }
        }
    }
};

int main()
{

    Queue q = Queue(4);
    q.enqueue(1);
    q.enqueue(2);

    q.dequeue();

    q.dequeue();

    q.display();
    return 0;
}