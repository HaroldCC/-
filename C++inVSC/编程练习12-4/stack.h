#ifndef STACK_H_ 
#define STACK_H_ 

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;         //stack中元素的个数
    int top;         //栈顶元素
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;

    //当栈满时，push()返回false
    bool push(const Item & item);                   //入栈

    //当栈为空时，pop()返回false
    bool pop(Item & item);               //出栈

    Stack & operator= (const Stack &st);
};

#endif