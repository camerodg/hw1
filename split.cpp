/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <cstddef>
#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  //Checks to see if the list is empty
  if(!in)
  {
		odds = evens = nullptr;
    return;
  }
//Evens Case
if(in->value % 2 == 0)
		{
		evens = in;
		in = in->next;
		evens->next = NULL;
		split(in,odds,evens->next);
	}
//Odds Case
	else
	{
   	odds = in;
	 	in = in->next;
	 	odds->next = NULL;
	 	split(in,odds->next,evens);
	}
}
