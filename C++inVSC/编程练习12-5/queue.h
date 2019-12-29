#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
    long arrive;                     //顾客到达时间
    int processtime;                 //顾客办理时间
public:
    Customer(){ arrive = processtime = 0;}
    ~Customer(){}

    void set(long when);
    long when() const { return arrive;}
    int ptime() const { return processtime; }
};

typedef Customer Item;


class Queue
{
private:
    struct Node { Item item; struct Node* next;};
    enum {Q_SIZE = 10};

    Node * front;                  //队头指针
    Node * rear;                   //队尾指针
    int items;                      //队列中目前存在的项目
    const int qsize;                //队列中项目最大数

     Queue(const Queue & q) : qsize(0) { }
     Queue & operator= (const Queue & q) { return *this;}
public:
    Queue(int qs = Q_SIZE);
    ~Queue();

    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);              //入队
    bool dequeue (Item &item);                  //出队
};


#endif