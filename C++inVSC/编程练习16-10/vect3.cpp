#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<memory>               // for 智能指针

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator< (const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else 
        return false;
}

bool worseThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->rating < r2->rating)
        return true;
    else 
        return false;
}

bool FillReview(Review& rr)
{
    std::cout << "输入书名（quit退出）：";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "输入图书评级：";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    std::cout << "输入图书价格：";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review>& rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

bool betterThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->rating > r2->rating)
        return true;
    else
        return false;
}

bool expensiveThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->price > r2->price)
        return true;
    else
        return false;
}

bool cheaperThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

int main(void)
{
    using std::cout;
    using std::endl;
    using std::cin;

    std::vector<std::shared_ptr<Review> > books;
    Review temp;
    while (FillReview(temp))
    {
        std::shared_ptr<Review> in(new Review(temp));
        books.push_back(in);
    }
    if (books.size() > 0)
    {
        cout << "输入你的选择：\n";
        cout << "1:按原始顺序显示， 2：按字母顺序显示， 3：按评级顺序显示，\n";
        cout << "4:按评级降序显示， 5：按价格升序显示， 6:按价格降序显示，\n";
        cout << "7：退出\n";
        int choice = 1;
        std::vector<std::shared_ptr<Review> > original_books(books.begin(), books.end());
        
        while (cin >> choice && choice != 7)
        {
            switch (choice)
            {
            case 1:
                copy(original_books.begin(), original_books.end(), books.begin());
                break;
            case 2:
                sort(books.begin(), books.end());
                break;
            case 3:
                sort(books.begin(), books.end(), worseThan);
                break;
            case 4:
                sort(books.begin(), books.end(), betterThan);
                break;
            case 5:
                sort(books.begin(), books.end(), cheaperThan);
                break;
            case 6:
                sort(books.begin(), books.end(), expensiveThan);
                break;
            default:
                break;
            }

            for_each(books.begin(), books.end(), ShowReview);
        }
    }
    
    return 0;
}
