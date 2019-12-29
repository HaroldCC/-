#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void show(string& s) { cout << s << " "; }

int main(void)
{
    vector<string> mat_friends, pat_friends;
    string name;
    cout << "Mat, 请输入你朋友的名字(quit结束)：";
    while (std::getline(cin, name) && name != "quit")
    {
        mat_friends.push_back(name);
        cout << "继续输入（quit退出）：";
    }

    cout << "Pat, 输入你朋友的名字：";
    while (std::getline(cin, name) && name != "quit")
    {
        pat_friends.push_back(name);
        cout << "继续输入（quit退出）：";
    }

    // 排序
    std::sort(mat_friends.begin(), mat_friends.end());
    std::sort(pat_friends.begin(), pat_friends.end());

    // 输出mat 和 pat的朋友
    cout << "Mat's friends:" << endl;
    for_each(mat_friends.begin(), mat_friends.end(), show);
    cout << endl;
    cout << "Pat's friends:\n";
    for_each(pat_friends.begin(), pat_friends.end(), show);
    cout << endl;

    // 列表合并为一个
    vector<string> friends;
    friends.reserve(mat_friends.size() + pat_friends.size());
    friends.insert(friends.end(), mat_friends.begin(), mat_friends.end());
    friends.insert(friends.end(), pat_friends.begin(), pat_friends.end());

    std::sort(friends.begin(), friends.end());
    auto new_friends = std::unique(friends.begin(), friends.end());
    cout << "All friends: \n";
    for_each(friends.begin(), friends.end(), show);
    cout << endl;
    
    
    return 0;
}