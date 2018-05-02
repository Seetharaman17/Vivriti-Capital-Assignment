#ifndef REGISTERS_H
#define REGISTERS_H
#include <iostream>
#include <sstream>
#include "ItemsHelper.h"
#include "Customers.h"
#include "Discounts.h"
using namespace std;

/*
*	Registers class that contains all details about the counters of the grocery store
*/

class Registers{

	public:

		Registers();
		~Registers();

		void printAvlItems();

		void shop(Customer* c);

		double getTotalSales();

	private:
		ItemsHelper itF;
		Discounts d;
		static double totalSales;

};
#endif
