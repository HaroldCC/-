#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABC
{
	private:
		char * label;
		int rating;
	public:
		ABC(const char * l = "null", int r = 0);
		ABC(const ABC & a);
		virtual ~ABC();
		virtual void view() const = 0;                    //纯虚函数
		ABC & operator= (const ABC & a);
		friend std::ostream & operator<< (std::ostream & os, const ABC & a);
};

class baseDMA : public ABC
{
	private:

	public:
		baseDMA(const char * l = "null", int r = 0);
		baseDMA(const baseDMA & bd);
		virtual void view() const;
		friend std::ostream & operator<< (std::ostream & os, const baseDMA & bd);
};

class lacksDMA : public ABC
{
	private:
		enum{COL_LEN = 40};
		char color[COL_LEN];
	public:
		lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
		lacksDMA(const lacksDMA & ld);
		virtual ~lacksDMA();
		virtual void view() const;
		lacksDMA & operator= (const lacksDMA & ld);
		friend std::ostream & operator<< (std::ostream & os, const lacksDMA & ld);
};

class hasDMA : public ABC
{
	private: 
		char * style;
	public:
		hasDMA(const char * s, const char * l = "null", int r = 0);
		hasDMA(const hasDMA & hd);
		virtual ~hasDMA();
		virtual void view() const;
		hasDMA & operator= (const hasDMA & hd);
		friend std::ostream & operator<< (std::ostream & os, const hasDMA & hd);
};

#endif
