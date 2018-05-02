#include <iostream>
#include <stdlib.h>
#include "Registers.h"
using namespace std;


double  Registers::totalSales=0.0;



Registers::Registers(){
	itF.loadAll();
}

Registers::~Registers(){
	itF.unloadAll();
}

/*
* Method to display all the Items Available Qty & Price present in the grocery store
*/
void Registers::printAvlItems(){


	for(int i=1;i<=itF.getCount();i++){
		Items* it = itF.getItems(i);
		cout <<"\n"<<i << "\t"<< it->getName() << "\t\tAvl Stock - " << it->getAvlStock() << "\t\tPrice - " << it->getPrice() << endl;
	}	

}

/*
* Method to shop items,apply discounts, generate bill 
*/
void Registers::shop(Customer* c){

	string cho;
	int ch,billAmt=0;
	stringstream billDetails;
	billDetails << "\n\n\t------------------------------Bill Details----------------------------" << endl;	
	billDetails << "\t\tNAME: " << c->getName() <<  "\t\tTYPE: "<< c->getType()<< endl;	
	do{
		printAvlItems();
		cout << "\nPlease enter ur choice of item (1/2/3/4 )to checkout, 'Y' to generate bill" << endl;
	
		cin >> cho;
		if(cho=="Y"){
			break;
		}else{
			ch = atoi(cho.c_str());			
			if(ch==0||ch>itF.getCount()){
				cout << "\nPlease enter proper input (1/2/3/4)" << endl;
				continue;
			}
		}

		Items* it = itF.getItems(ch);
		string qty;
		cout << "Enter Qty of "<< it->getName() << " - Avl Stock " << it->getAvlStock() << endl;
		cin>> qty;
		int q= atoi(qty.c_str());
		if(q==0){
			cout << "Invalid Quantity.Please enter proper input"<< endl;
			continue;
		}
		if(it->checkout(q)!=-1){
			int val  = q* it->getPrice();
			d.applyDiscount(it,val);
			billAmt+= val;
			billDetails << "\n\t" << it->getName() << "\tQuantity " << q << "\tValue " << val << endl;
		}else{
			cout << "Sorry the required stocks are not available now, pls try  with less Qty" << endl;
		}

		cout << "Your current bill amount is " << billAmt << endl;

	}while (cho!="Y");


	cout << billDetails.str() << endl;
	cout << "\n\t----------------------------------Bill amount is---------- " << billAmt << endl;
	d.applyDiscount(c,billAmt);
	cout << "\n\t----------------------------------Total Bill amount after discount---------- " << billAmt << "\n\n\n";
	totalSales+=billAmt;
}


/*
* Method to get Total sales of the store 
*/
double Registers::getTotalSales(){

	return totalSales; 
}
