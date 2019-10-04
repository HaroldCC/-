#ifndef LIST_H_
#define LIST_H_

//将int声明为Item
typedef int Item;

class List
{
private:
    static const int MAX = 10;
    Item items[MAX];
    int count;
public:
    List() {count = 0;};                     //声明为内联函数
    ~List();
    bool isempty() const;
    bool isfull() const;
    int itemcount() const;
    bool additem(const Item & item);
    void visit(void (*pf) (Item &));
};

#endif
