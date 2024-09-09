#ifndef COP4530_STACK_H
#define COP4530_STACK_H
/********************************
 * COP 4530
 * FSU Department of Computer Sience
 ********************************/

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace cop4530
{
    template <typename T>
    class Stack
    {
    private:
        vector<T> stack;
        int theSize;

    public:
        // constructors/destructor
        Stack();
        ~Stack();
        Stack(const Stack &rhs);            // copy constructor
        Stack(Stack &&rhs);                 // move constructor
        Stack &operator=(const Stack &rhs); // copy assignment operator
        Stack &operator=(Stack &&rhs);      // move assignment operator
        // other
        bool empty() const;
        int size();
        T &top();
        const T &top() const;
        void pop();
        void push(const T &val);
        void push(T &&val);
    };
#include "Stack.hpp"
}
#endif