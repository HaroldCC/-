#ifndef STACK_H_ 
#define STACK_H_ 

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;         //stack��Ԫ�صĸ���
    int top;         //ջ��Ԫ��
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;

    //��ջ��ʱ��push()����false
    bool push(const Item & item);                   //��ջ

    //��ջΪ��ʱ��pop()����false
    bool pop(Item & item);               //��ջ

    Stack & operator= (const Stack &st);
};

#endif