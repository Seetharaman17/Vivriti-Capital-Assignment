#ifndef CUSTOMER_FACTORY_H
#define CUSTOMER_FACTORY_H

#include "Customers.h"

/*
* CustomerFactory class produces different customers based on the type of input
*/

class CustomerFactory{

	public:

	Customer* getCustomer(int type){

		Customer* cust;
		if(type==1){
			cust = new Normal();
		}else if(type==2){
			cust = new SeniorCitizen();
		}else if(type==3){
			cust = new Employee();
		}

		return cust;
	}


	void printAvlCustOptions(){
		cout << "Choose the type of Customer 1.Normal 2.SeniorCitizen 3.StoreEmployee" << endl;
	}

	int validateCustOption(int t){

		if(t<1 || t>3){
			return -1;		

		}

	}

};
#endif
