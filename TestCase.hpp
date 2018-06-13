#ifndef INC_6_TESTCASE_H
#define INC_6_TESTCASE_H

#include <iostream>
#include <sstream>
#include <functional>

using namespace std;

class TestCase {
private:
	string _name;
	size_t _num_tests;
	size_t _num_passed;
	ostream& _out;

public:

	TestCase(string name, ostream& out);

	template<class T>
	TestCase& check_equal(T input, T expected);

	template <class T> TestCase& check_different(T input, T expected);

	template<class T>
	TestCase& check_output(T input, string expected);

	template<class T, class U, class V>
	TestCase& check_function(U (*func)(V), T input, U expected);

	template<class T, class U, class Lambda>
	TestCase& check_function(Lambda func, T input, U expected);

	void print();

};

#endif //INC_6_TESTCASE_H