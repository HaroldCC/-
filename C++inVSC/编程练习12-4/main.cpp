#include"stack.h"
#include<iostream>

int main(void)
{
    // using namespace std;

    // Stack st;
    // Stack s2(20);
    // s2.push(10);
    // s2.push(30);
    // s2.push(200);

    // Stack s3 = s2;

    // Item ite;
    // s3.pop(ite);

    // cout << ite << "从s3中删除。" << endl;

    // st = s3;
    // st.pop(ite);
    // cout << ite << "从st中删除。" << endl;

    using namespace std;
	Stack s1;
	for (int i = 0; i < 10; i++)
		s1.push(100+i);

	Stack s2 = s1;
	Stack s3(s1);

	while(!s1.isempty())
	{
		Item i;
		s1.pop(i);
		cout << "s1 poped " << i << endl;
	}

	Item i1;
	s2.pop(i1);
	s2.pop(i1);
	while(!s2.isempty())
	{
		Item i;
		s2.pop(i);
		cout << "s2 poped " << i << endl;
	}

    
    return 0;
}