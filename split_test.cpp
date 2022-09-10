#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
//Test 1
	Node x( 1, nullptr ); 
	Node y( 2, &x ); 
	Node z( 3, &y ); 
	Node a( 4, &z ); 
  Node b( 5, &a ); 
	Node c(21, &b);
	Node d(31, &c);

  Node* start = &a; 
  Node* odd_digits = NULL; 
  Node* even_digits = NULL; 

  split( start, odd_digits, even_digits); 

 cout << "even numbers: "; 
  while ( even_digits != NULL ){
    cout << even_digits->value << " "; 
    even_digits = even_digits->next; 
  }
	cout << endl; 

  cout << "odd numbers: "; 
  while ( odd_digits != NULL ){
    cout << odd_digits->value << " "; 
    odd_digits = odd_digits->next; 
  }
}