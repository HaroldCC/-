/*************************************************************************
    > File Name       : QueueTp.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 10:28:43
 ************************************************************************/

#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename T>
class QueueTp
{
	private:
		enum {Q_SIZE = 10};
		struct Node
		{
			T item;
			Node * next;
		};

		Node * front;
		Node * rear;
		int items;
		const int qsize;
	public:
		QueueTp(int qs = Q_SIZE);
		~QueueTp();
		bool isempty() const {return items == 0;}
		bool isfull() const {return items == qsize;}
		int queuecount() const {return items;}
		bool enqueue(const T & item);              //入队
		bool dequeue(T & item);                    //出队
};

template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

template <typename T>
QueueTp<T>::~QueueTp()
{
	Node * temp;
	while (front != nullptr)
	{
		temp = front;
		front = front -> next;
		delete temp;
	}
}

template <typename T>
bool QueueTp<T>::enqueue(const T & item)
{
	if (isfull())
		return false;
	Node * add = new Node;
	if (front == nullptr)       //如果队列为空
	{
		add->item = item;
		add->next = nullptr;
		front = rear = add;
	}
	else {
		add->item = item;
		add->next = nullptr;
		rear->next = add;
		rear = add;
	}
	items++;

	return true;
}

template <typename T>
bool QueueTp<T>::dequeue(T & item)
{
	if (isempty())
		return false;
	item = front->item;
	Node * temp;
	temp = front;
	front = front->next;
	delete temp;
	items--;

	return true;
}


#endif
