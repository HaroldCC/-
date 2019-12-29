#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
#include<cctype>
#include<cstdlib>

using std::string;
using std::vector;

void read_words(const string filename, vector<string>& wordlist)
{
    std::ifstream fin;
    fin.open(filename);

    if(!fin.is_open())
    {
        std::cout << "打开文件" << filename << "失败！";
        std::exit(EXIT_FAILURE);
    }

    string word;
    while (fin >> word)
    {
       wordlist.push_back(word); 
    }
    
}

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::tolower;
    
    // 获取文件中的单词
    vector<string> wordlist;
    read_words("words.txt", wordlist);
    int num = wordlist.size();
    cout << "words.txt文件中有" << num << "个单词！\n";

    std::srand(std::time(0));
    char play;
    cout << "Will you play word game? <y/n>";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % num];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length 
             << "letters, and you guess\n" << "one letter at a time. " 
             << "You get " << guesses << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
            {
                cout << "你已经猜到了, 再试一次。\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            }
            else 
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc+1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc+1);
                }
                
            }

            cout << "You word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }  
        }

        if (guesses > 0)
            cout << "正确！\n";
        else 
            cout << "Sorry, the word is " << target << ".\n";
        cout << "要再来一次吗！<y/n> ";
        cin >> play;
        play = tolower(play);
    }
    cout << "END!\n";
    
    return 0;
}