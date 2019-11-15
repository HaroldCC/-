/*************************************************************************
    > File Name       : cow.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-13 19:34:14
 ************************************************************************/



#ifndef COW_H_
#define COW_H_


class Cow{
	private:
		char name[20];
		char* hobby;
		double weight;
	public:
		Cow();
		Cow(const char* nm, const char* ho, double wt);
		Cow(const Cow & c);
		~Cow();
		Cow & operator= (const Cow & c);
		void ShowCow() const;
};


#endif
