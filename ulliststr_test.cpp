/* Write your test code for the ULListStr in this file */
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	//Test 1, testing push_back()
	ULListStr test;
	test.push_back("6");
	test.push_back("5");
	test.push_back("4");
	cout << test.get(0) << " " << test.get(1) << " " << test.get(2) << " ";
	test.push_back("7");
	cout << test.get(3) << " " << endl;
  //Test 2
	test.push_front("3");
	test.push_front("4");
	cout << test.get(0) << " " << test.get(1) << " " << test.get(2) << " " << test.get(3) << endl;
	test.pop_back();
	test.pop_back();
	cout << test.get(0) << " " << test.get(1) << endl;
	//Test 3 
	//testing pop_front()
	//and push_back 
	test.pop_front();
	test.pop_front();
	test.push_back("13");
	test.push_back("24");
	test.push_back("32");
	cout << test.get(0) << " " << test.get(1) << " " << test.get(2);
	//Test 4
	//grabbed the first and last string 
	string a = test.back();
	string b = test.front();
	cout << a << " " << b << endl;
	//Test 5
	//testing the push_back to
	//esnure everything is properly
	//allocatedl; tested size() and get()
	test.push_back("76");
	test.push_back("45");
	test.push_back("34");
	test.push_back("11");
	test.push_back("199");
	test.push_back("32");
	test.push_back("12");
	test.push_back("1");
	test.push_back("111");
	cout << "size: " << test.size() << endl;
	cout << "loc1 = " << test.get(1) << endl;
	//Test 6, testing to see if 6 and 5
	//the first two elements will remain
	//and be in the proper position
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	cout << test.get(0) << " " << test.get(1) << endl;
	//Test 7, trying to grab index out of scope
	//should terminate and throw a instance of std::invalid_argument
	test.get(12);
  return 0;
}
