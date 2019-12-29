#include<iostream>
#include<algorithm>

template <typename T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar+n);
    T* reduced_ar = std::unique(ar, ar+n);

    return reduced_ar - ar;
}

template <typename T>
void show(T ar[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << ar[i] << " ";
    std::cout << std::endl;
}

int main(void)
{
    long arr[10] {1, 2, 2, 3, 5, 6, 7, 9, 9, 9};
    show(arr, 10);

    int newsize = reduce(arr, 10);
    show(arr, newsize);

    std::string str[10] {"zhangsan", "lisi", "lisi", "zhangsan", 
                            "wangwu", "zhangmazi", "xiaoming", "tom", 
                            "tom", "xiaohong"};
    show(str, 10);

    newsize = reduce(str, 10);
    show(str, newsize);
    
    return 0;
}