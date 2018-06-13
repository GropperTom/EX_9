#include "TestCase.hpp"
using namespace std;

TestCase::TestCase(string name, ostream& out)
	: _name(name), _out(out) {
	_num_tests = 0;
	_num_passed = 0;
}

template<class T>	TestCase& TestCase::check_equal(T input, T expected) {
	++_num_tests;
	if (input == expected) {
		++_num_passed;
	}
	else {
		_out << _name << " Failure in test #" << _num_tests << ": The inputs are not equal!" << endl;
	}
	return *this;
}

template<class T> TestCase& TestCase::check_different(T input, T expected) {
	++_num_tests;
	if (input != expected) {
		++_num_passed;
	}
	else {
		_out << _name << " Failure in test #" << _num_tests << ": The inputs are equal!" << endl;
	}
	return *this;
}

template<class T> TestCase& TestCase::check_output(T input, string expected) {
	++_num_tests;
	ostringstream oss;
	oss << input;
	string input_str = oss.str();
	if (input_str == expected) {
		++_num_passed;
	}
	else {
		_out << _name << " Failure in test #" << _num_tests << ": string value should be " << expected << " but is " << input_str << endl;
	}
	return *this;
}

template<class T, class U, class V>	TestCase& TestCase::check_function(U (*func)(V), T input, U expected) {
	try {
		++_num_tests;
		U func_result = func(input);
		if (func_result == expected) {
			++_num_passed;
		}
		else {
			_out << _name << " failure in test #" << _num_tests << ": Function should return " << expected << " but returned " << func_result << "!" << endl;
		}
	}
	catch(exception& e) {
		_out << e.what() << endl;
	}
	return *this;
}

template<class T, class U, class Lambda> TestCase& TestCase::check_function(Lambda func, T input, U expected) {
	try {
		++_num_tests;
		U func_result = func(input);
		if (func_result == expected) {
			++_num_passed;
		}
		else {
			_out << _name << " failure in test #" << _num_tests << ": Function should return " << expected << " but returned " << func_result << "!" << endl;
		}
	}
	catch (exception& e) {
		_out << e.what() << endl;
	}
	return *this;
}

void TestCase::print() {
	_out << _name << " : " << (_num_tests - _num_passed) << " failed, " << _num_passed << " passed, " << _num_tests << " total." << "\n---" << endl;
}