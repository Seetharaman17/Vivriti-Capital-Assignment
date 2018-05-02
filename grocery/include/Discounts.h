#ifndef DISCOUNTS_H
#define DISCOUNTS_H
#include <iostream>
#include "Items.h"
#include "Customers.h"
using namespace std;

/*
 * Discount classes for applying discounts based on the type of items or customers
 */

class Discounts{

	public:
		/* Method to apply discount on the price based on the type of item*/

		void applyDiscount(Items *it,int &val){
			string name = it->getName();
			if(name.compare("CHIPS")==0){
				if(val!=0){
					cout << "\n\t5% discount applied CHIPS" << endl;
					val -= (0.05*val);	
				}
			}
		}

		/* Method to apply discount on the total bill Amount  based on the type of customer*/
		void applyDiscount(Customer *c,int& billAmt ){
			string type = c->getType();		

			if(type.compare("Employee")==0){
				if(billAmt!=0){
					cout << "\n\t5% discount applied for Store employee" << endl;
					billAmt -= (0.05*billAmt);
				}
			}else if(type.compare("SeniorCitizen")==0){
				if(billAmt!=0){
					cout << "\n\t2% discount applied for Senior citizen" << endl;
					billAmt -= (0.02*billAmt);
				}
			}
		}
};

#endif
