#include <vector>
using namespace std;
// constructors
template <class T>
Stack<T>::Stack()
{
    vector<T> temp;
    stack = temp;
    theSize = 0;
}
template <class T>
Stack<T>::~Stack()
{
    // do nothing
}
template <class T>
Stack<T>::Stack(const Stack &rhs)
{
    stack = rhs.stack;
    theSize = rhs.theSize;
}
template <class T>
Stack<T>::Stack(Stack &&rhs)
{
    std::swap(stack, rhs.stack);
    std::swap(theSize, rhs.theSize);
}
template <class T>
Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    Stack copy = rhs; // calling copy constructor
    std::swap(*this, copy);
    return *this;
}
template <class T>
Stack<T> &Stack<T>::operator=(Stack &&rhs)
{
    std::swap(theSize, rhs.theSize);
    std::swap(stack, rhs.stack);
    return *this;
}
template <class T>
bool Stack<T>::empty() const
{
    return theSize == 0;
}
template <class T>
int Stack<T>::size()
{
    return theSize;
}
template <class T>
T &Stack<T>::top()
{
    return stack.back();
}
template <class T>
const T &Stack<T>::top() const
{
    return stack.back();
}
template <class T>
void Stack<T>::pop()
{
    stack.erase(stack.end() - 1);
    theSize--;
}
template <class T>
void Stack<T>::push(const T &val)
{
    stack.push_back(val);
    theSize++;
}
template <class T>
void Stack<T>::push(T &&val)
{
    stack.push_back(std::move(val));
    theSize++;
}