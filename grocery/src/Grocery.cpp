#include <iostream>
#include <stdlib.h>
#include "Grocery.h"
using namespace std;

Grocery::Grocery(){
}

/*
* Method to print the details of the available inventories in store
*/
void Grocery::printDetails(){
	int i = rand()%10;
	cout << "\n\n\n\t\t*****************Grocery Store*****************\t\t" << endl;
	cout << "\n\t\t**************Inventories Available************\t\t" << endl;
	r[i].printAvlItems();
	cout << "\n\t\t********************TOTAL SALES FOR THE DAY ------" << r[i].getTotalSales() << endl;
}

/*
 * Method to bill the items in store based on the customer & discounts applicable
*/

void Grocery::billItems(int t,Customer* cust){
	cout << "------------------- Counter  no - " << t << endl;
	r[t].shop(cust);
	cout << "\n\t\t********************TOTAL SALES FOR THE DAY ------" << r[t].getTotalSales() << endl;
	printDetails();
}


