#include <iostream>
using namespace std;

template <class T> 

class stack
{
    T *arr;
    int top;
    int capacity;
    
    public:
        stack (int size);    //constructor
        void push (T);
        T pop();
        void Display();
        
        ~stack()
        {
            delete[] arr;
        }
};

template <class T>
stack<T>::stack(int size)      //constructor to initialise the stack
{
    arr = new T[size];
    capacity = size;
    top = -1;
}

template <class T>
void stack<T>::push(T ele)      //function to push element into stack
{
    if (top == capacity - 1)
    {
        cout << "\nStack Overflow!\n";
        return;
    }
    arr[++top] = ele;
    cout << ele << " inserted into the stack successfully!\n";
}

template <class T>
T stack<T>::pop()
{
    if (top == -1)
    {
        cout << "\nStack Underflow!\n";
        return -1;
    }
    return arr[top--];
}

template <class T>
void stack<T>::Display()
{
    cout << "\nThe stack now is:\n";
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n\n";
}

int main()
{
    stack<char> s1(5);
    stack<int> s2(5);
    char del1;
    int del2;
    
    cout << "*CHARACTER STACK ARRAY:*\n\n";
    
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    s1.Display();
    del1 = s1.pop();
    cout << del1 << " deleted from the stack successfully!\n";
    del1 = s1.pop(); 
    cout << del1 << " deleted from the stack successfully!\n"; 
    s1.Display();
    
    cout << "\n*INTEGER STACK ARRAY:*\n\n";
    s2.push(1);
    s2.push(4);
    s2.push(2);
    s2.push(8);
    s2.Display();
    del2 = s2.pop();
    cout << del2 << " deleted from the stack successfully!\n";
    del2 = s2.pop(); 
    cout << del2 << " deleted from the stack successfully!\n"; 
    s2.Display();
}
