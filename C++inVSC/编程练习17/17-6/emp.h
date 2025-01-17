/*************************************************************************
    > File Name       : emp.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-27 22:12:45
 ************************************************************************/
#ifndef EMP_H_
#define EMP_H_

#include<iostream>
#include<string>
#include<fstream>

enum classkind { Employee, Manager, Fink, HighFink };

class abstr_emp
{
	private:
		std::string fname;
		std::string lname;
		std::string job;
	public:
		abstr_emp();
		abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);
		virtual void ShowAll() const;
		virtual void SetAll();
		friend std::ostream& operator<< (std::ostream& os,const abstr_emp& e);
		virtual ~abstr_emp() = 0;
		virtual std::ofstream& WriteAll(std::ofstream& fout) const;
};

class employee : public abstr_emp
{
	public:
		employee();
		employee(const std::string& fn, const std::string& ln, const std::string& j);
		virtual void ShowAll() const;
		virtual void SetAll();
		std::ofstream& WriteAll(std::ofstream& fout) const;
};

class manager : virtual public abstr_emp
{
	private:
		int inchargeof;
	protected:
		int InChargeOf() const { return inchargeof; }
		int & InChargeOf() { return inchargeof; }
	public:
		manager();
		manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
		manager(const abstr_emp& e, int ico);
		manager(const manager& m);
		virtual void ShowAll() const;
		virtual void SetAll();
		std::ofstream& WriteAll(std::ofstream& fout) const;
};

class fink : virtual public abstr_emp
{
	private:
		std::string reportsto;
	protected:
		const std::string ReportsTo() const { return reportsto; }
		std::string& ReportsTo() { return reportsto; }
	public:
		fink();
		fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
		fink(const abstr_emp& e, const std::string& rpo);
		fink(const fink& e);
		virtual void ShowAll() const;
		virtual void SetAll();
		std::ofstream& WriteAll(std::ofstream& fout) const;
};

class highfink : public manager, public fink
{
	public:
		highfink();
		highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
		highfink(const abstr_emp& e, const std::string& rpo, int ico);
		highfink(const fink& f, int ico);
		highfink(const manager& m, const std::string& rpo);
		highfink(const highfink& h);
		virtual void ShowAll() const;
		virtual void SetAll();
		std::ofstream& WriteAll(std::ofstream& fout) const;
};


#endif
