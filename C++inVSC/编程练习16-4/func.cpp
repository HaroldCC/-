#include<iostream>
#include<algorithm>

int reduce(long ar[], int n)
{
    std::sort(ar, ar+n);
    long* reduced_ar = std::unique(ar, ar+n);

    return reduced_ar - ar;
}

void show(long ar[], int n)
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
    
    return 0;
}