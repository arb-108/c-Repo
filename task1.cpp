#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
    T *data;
    int top;
    const int MAX_SIZE;

public:
    // Constructor
    Stack(const int MAX_SIZE = 10) : MAX_SIZE(MAX_SIZE)
    {
        data = new T[MAX_SIZE];
        top = -1;
    }
    ~Stack()
    {
        delete[] data;
    }
    void push(const T newItem)
    {
        if (!isFull())
        {
            data[++top] = newItem;
        }
        else
        {
            cout << "Sory there is no Space for This" << endl;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
    }
    void clear()
    {
        if (!isEmpty())
        {
            top = -1;
        }
        else
        {
            cout << "Stack is Already Empty" << endl;
        }
    }
    T getTop() const
    {
        if (!isEmpty())
        {
            return data[top];
        }
    }
    bool isEmpty() const
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool isFull() const
    {
        if (top == MAX_SIZE - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    void showStructure() const
    {
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << data[i];
                if (i == top)
                {
                    cout << " <--Top" << endl;
                }
                else
                {
                    cout << endl;
                }
            }
            // cout << "top=" << top << endl;
        }
        else
        {
            cout << "Empty hai" << endl;
        }
    }
};
int main()
{
    Stack<int> obj1(5);
    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    obj1.push(5);
    obj1.push(5);
    obj1.push(5);
    obj1.showStructure();
    obj1.pop();
    obj1.showStructure();
    cout<<"top value is "<<obj1.getTop()<<endl;
    cout << "hello" << endl;
    obj1.clear();
    obj1.showStructure();
}