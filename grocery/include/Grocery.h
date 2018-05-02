#ifndef GROCERY_H
#define GROCERY_H
#include <iostream>
#include <stdlib.h>
#include "Registers.h"
#include "Customers.h"
using namespace std;

/*
 * Grocery class which contains details about the grocery store
*/

class Grocery{

   public:
	Grocery();	
	void printDetails();
	void billItems(int t,Customer* c);

   private:
	Registers r[11];
};
#endif


