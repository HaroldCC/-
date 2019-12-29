/*************************************************************************
    > File Name       : emp.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-28 9:39:51
 ************************************************************************/
#include"emp.h"

// abstr_emp 方法定义
abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") { }
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) { }
void abstr_emp::ShowAll() const 
{
	std::cout << "abstr_emp's ShowAll():\n";
	std::cout << "fname: " << fname << std::endl;
	std::cout << "lname: " << lname << std::endl;
	std::cout << "job: " << job << std::endl;
	std::cout << std::endl;
}
void abstr_emp::SetAll()
{
	std::cout << "abstr_emp's SetAll():\n";
	std::cout << "输入 fname: ";
	std::getline(std::cin, fname);
	std::cout << "输入 lname: ";
	std::getline(std::cin, lname);
	std::cout << "输入 job: ";
	std::getline(std::cin, job);
}
std::ostream& operator<< (std::ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname << ","  << e.job << std::endl;
	return os;
}
abstr_emp::~abstr_emp() { }
std::ofstream& abstr_emp::WriteAll(std::ofstream& fout) const
{
	fout << "abstr_emp's fout:\n";
	fout << fname << " " << lname << "," << job;
	return fout;
}



// employee 方法定义
employee::employee() : abstr_emp() { }
employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j) { }
void employee::ShowAll() const
{
	std::cout << "employee's ShowAll():\n";
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	std::cout << "employee's SetAll():\n";
	abstr_emp::SetAll();
}
std::ofstream& employee::WriteAll(std::ofstream& fout) const
{
	fout << "employee's fout:\n";
	abstr_emp::WriteAll(fout);
	return fout;
}




// manager 方法定义
manager::manager() : abstr_emp(), inchargeof(0) { }
manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) { }
manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) { }
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) { }
void manager::ShowAll() const
{
	std::cout << "manager's ShowAll():\n";
	abstr_emp::ShowAll();
	std::cout << "inchargeof: " << inchargeof << std::endl;
}
void manager::SetAll()
{
	std::cout << "manager's SetAll():\n";
	abstr_emp::SetAll();
	std::cout << "输入 inchargeof: ";
	std::cin >> inchargeof;
	while (std::cin.get() != '\n')
		continue;
}
std::ofstream& manager::WriteAll(std::ofstream& fout) const
{
	fout << "manager's fout:\n";
	abstr_emp::WriteAll(fout);
	fout << "," << inchargeof;
	return fout;
}






// fink 方法定义
fink::fink() : abstr_emp(), reportsto("none") { }
fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) { }
fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo){ }
fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) { }
void fink::ShowAll() const
{
	std::cout << "fink's ShowAll():\n";
	abstr_emp::ShowAll();
	std::cout << "reportsto: " << reportsto << std::endl;
}
void fink::SetAll()
{
	std::cout << "fink's SetAll():\n";
	std::cout << "输入 reportsto: ";
	std::getline(std::cin, reportsto);
}
std::ofstream& fink::WriteAll(std::ofstream& fout) const
{
	fout << "fink's fout:\n";
	abstr_emp::WriteAll(fout);
	fout << "," << reportsto;
	return fout;
}





// highfink 方法定义
highfink::highfink() : abstr_emp(), manager(), fink() { }
highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) { }
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) { }
highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f) { }
highfink::highfink(const manager& m, const std::string& rpo) : abstr_emp(m), manager(m), fink(m, rpo) { }
highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) { }
void highfink::ShowAll() const 
{
	std::cout << "highfink's ShowAll():\n";
	abstr_emp::ShowAll();
	std::cout << "inchargeof: " << manager::InChargeOf() << std::endl;
	std::cout << "reportsto: " << fink::ReportsTo() << std::endl;
}
void highfink::SetAll() 
{
	std::cout << "highfink's SetAll():\n";
	abstr_emp::SetAll();
	std::cout << "输入 inchargeof: ";
	std::cin >> manager::InChargeOf();
	std::cout << " 输入 reportsto: ";
	std::getline(std::cin, fink::ReportsTo());
}
std::ofstream& highfink::WriteAll(std::ofstream& fout) const
{
	fout << "highfink's fout:\n";
	abstr_emp::WriteAll(fout);
	manager::WriteAll(fout);
	fink::WriteAll(fout);
	return fout;
}
