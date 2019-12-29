#include "stack.h"

Stack::Stack(int n)
{
    size = n;
    top = 0;
    pitems = new Item[n];
}
Stack::Stack(const Stack &st)
{
    size = st.size;
    top = st.top;
    pitems = new Item[size];

    for (int i = 0; i < size; i++)
    {
        pitems[i] = st.pitems[i];
    }
    
}
Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

//��ջ��ʱ��push()����false
bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
    
    
} //��ջ

//��ջΪ��ʱ��pop()����false
bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
    {
         return false;
    }
    
    
} //��ջ

Stack & Stack::operator=(const Stack &st)
{

    if (this == &st)
    {
        return *this;
    }
    
    for (int i = 0; i < st.size; i++)
    {
        pitems[i] = st.pitems[i];
    }
    
    top = st.top;
    size = st.size;

    return *this;

}