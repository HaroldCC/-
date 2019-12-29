#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> lotto(int total, int select)
{
    using std::vector;

    // 得到一个总向量
    vector<int> all;
    for (int i = 1; i < total; i++)
        all.push_back(i);

    // 洗牌
    random_shuffle(all.begin(), all.end());

    // 随机向量
    vector<int> rand_vec(all.begin(), all.begin() + select);

    return rand_vec;
}

int main(void)
{
    const int TOT = 51, SELECT = 6;

    std::vector<int> winners;

    winners = lotto(TOT, SELECT);

    for (auto it = winners.begin(); it != winners.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}