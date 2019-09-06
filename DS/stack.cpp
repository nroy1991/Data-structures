#include <bits/stdc++.h>

using namespace std;

template <class T>

class stacky
{
private:
    int top;  //Top element of the array.
    T a[200]; //Declaration of a big array which will be used as a stack.

public:
    /*
    Push function takes the arguments of just the data to be pushed into the stack.
    */

    bool push(T x)
    {
        if (top > 199)
        {
            cout << "Stack overflow" << endl;
            return false;
        }
        top += 1;
        a[top] = x;
        return true;
    }

    /*
    Pop function takes no arguments just pops the topmost value of the stack and returns it.
    */

    T pop()
    {
        if (top < 1)
        {
            cout << "Stack underflow" << endl;
            return false;
        }
        T temp = a[top];
        top -= 1;
        return temp;
    }

    /*
    Peep takes the argument of the number to be peeped from the top and the returns the number to be peeped.
    */

    T peep(int x)
    {
        if (top - x + 1 < 0)
        {
            cout << "Stack underflow" << endl;
            return false;
        }
        T temp = a[top - x + 1];
        return temp;
    }
    stacky() : top(0) {}
};