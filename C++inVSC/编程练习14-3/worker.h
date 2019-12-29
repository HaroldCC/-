/*************************************************************************
    > File Name       : worker.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 11:00:54
 ************************************************************************/

#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker
{
	private:
		std::string fullname;
		long id;
	public:
		Worker() : fullname("none"), id(0L) {}
		Worker(const std::string & s, long n) : fullname(s), id(n) {}
		virtual ~Worker() {}
		virtual void Set();
		virtual void Show() const;
};

#endif
