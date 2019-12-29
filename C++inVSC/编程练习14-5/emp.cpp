/*************************************************************************
    > File Name       : .\emp.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-03 22:26:10
 ************************************************************************/
#include "emp.h"

using namespace std;

abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j){
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::ShowAll() const {
	cout << "abstr_emp:\n";
	cout << "firstname:" << fname << endl;
	cout << "lastname:" << lname << endl;
	cout << "job:" << job << endl;
}

void abstr_emp::SetAll() {
	cout << "输入第一个名字：";
	getline(cin, fname);
	cout << "输入最后一个名字：";
	getline(cin, lname);
	cout << "输入工作：";
	getline(cin, job);
}

ostream & operator<< (ostream & os, const abstr_emp & e){
	os << e.fname << "," << e.lname;
	return os;
}

abstr_emp::~abstr_emp() {}

employee::employee() : abstr_emp() {}

employee::employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const{
	cout << "employee:\n";
	abstr_emp::ShowAll();
}

void employee::SetAll() {
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const string & fn, const string & ln, const string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const {
	cout << "manager:\n";
	abstr_emp::ShowAll();
	cout << "inchargeof:" << inchargeof << endl;
}

void manager::SetAll() {
	abstr_emp::SetAll();
	cout << "输入inchargeof";
	cin >> inchargeof;
	while (cin.get() != '\n')
		continue;
}


fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const{
	cout << "fink:" << endl;
	abstr_emp::ShowAll();
	cout << "reportsto:" << reportsto << endl;
}

void fink::SetAll() {
	abstr_emp::SetAll();
	cout << "输入reportsto:";
	getline(cin, reportsto);
}


highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp & e, const string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager & m, const string & rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
	cout << "highfink:\n";
	abstr_emp::ShowAll();
	cout << "inchargeof:" << manager::InChargeOf() << endl;
	cout << "reportsTo:" << fink::ReportsTo() << endl;
}

void highfink::SetAll() {
	manager::SetAll();
	cout << "输入reportsto：";
	getline(cin, fink::ReportsTo());
}

