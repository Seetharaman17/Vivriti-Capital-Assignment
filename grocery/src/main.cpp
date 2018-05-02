#include <iostream>
#include <stdlib.h>
#include "Grocery.h"
#include "CustomerFactory.h"
using namespace std;



int main(){

	Grocery g;
	g.printDetails();
	CustomerFactory cf;

	while(1){
	
		int t,r;
		string opt,name,rOpt,cOpt;
		cout << "\nEnter 'Y' -To continue.... Any other key for Exit" << endl;
		cin >> opt;
		if(opt!="Y") break;

		cout << "\nChoose any valid counter (1-10) for billing" << endl;
		while(1){
			cin >> rOpt;
			r = atoi(rOpt.c_str());
			if(r<=0 || r>10) { 
			cout << "\nChoose any valid counters (1-10) for billing" << endl;}
		        else {break;}
		}

		cf.printAvlCustOptions();
		cin >> cOpt;
		t = atoi(cOpt.c_str());
		if(cf.validateCustOption(t)==-1){ cout << "\n Invalid customer type..." << endl; continue;}
	
		Customer *cust = cf.getCustomer(t);
		cout << "Enter customer name: " << endl;
		cin>> name;
		cust->setName(name);	

		g.billItems(r,cust);
		delete cust;
	}

	return 0;

}

