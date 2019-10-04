#include "stack.h"
#include<iostream>
#include<cctype>

int main(void)
{
    Stack st;
    customer temp;
    double payment = 0;
    char ch;
    std::cout << "请输入A以添加客户" << std::endl;
    std::cout << "P弹出客户，q退出。\n";
    while (std::cin >> ch && toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }
        
        switch (ch)
        {
        case 'A':
        case 'a': std::cout << "输入顾客的名字：";
                  std::cin.getline(temp.fullname, 35);
                  std::cout << "输入支出：";
                  std::cin >> temp.payment;
                  if (st.isfull())
                  {
                      std::cout << "堆栈已满！\n";
                  }
                  else
                  {
                      st.push(temp);
                  }
                  break;
        case 'P':
        case 'p': if (st.isempty())
                  {
                      std::cout << "堆栈为空！\n";
                  }
                  else
                  {
                      st.pop(temp);
                      payment += temp.payment;
                      std::cout << "total = " << payment << std::endl;
                  }
                  break;
        default:
            break;
        }
    std::cout << "请输入A以添加客户" << std::endl;
    std::cout << "P弹出客户，q退出。\n";
    }
    std::cout << "Bye!\n";
    
    system("pause");
    return 0;
}