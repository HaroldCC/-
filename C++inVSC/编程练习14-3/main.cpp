/*************************************************************************
    > File Name       : main.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 11:27:16
 ************************************************************************/
#include<iostream>
#include<string>
#include "worker.h"
#include "queue.h"



int main(int argc,char *argv[])
{
	using std::cin;
	using std::cout;
	using std::endl;
	//using std::strchr;

	QueueTp<Worker> q(3);

	if (q.isempty())
		cout << "队列为空。" << endl;
	cout << "添加worker1入队..." << endl;
	Worker w1("zhangsan", 1);
	q.enqueue(w1);

	cout << "添加worker2入队..." << endl;
	Worker w2("wang", 2);
	q.enqueue(w2);

	cout << "添加worker3入队..." << endl;
	Worker w3("lisi", 3);
	q.enqueue(w3);

	if (q.isfull())
		cout << "队列已满" << endl;

	Worker w;
	cout << "删除worker1..." << endl;
	q.dequeue(w);
	w.Show();
     
    return 0;
}

