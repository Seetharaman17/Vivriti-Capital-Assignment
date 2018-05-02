#ifndef CUSTOMER_H 
#define CUSTOMER_H

#include <iostream>
using namespace std;

/*
*Customer Base class & Derived classes based on type of customers
*/
class Customer{

	public:
		void setName(string name){
			this->name=name;
		}

		virtual string getName(){
			return name;
		};
		virtual string getType(){
			return type;
		}

		virtual ~Customer(){
		}
	protected:
		string name;
		int age;
		string type;
};

class Normal: public Customer{
	public:
	      Normal(){
		type="Normal";
	      }
		
};


class SeniorCitizen: public Customer{
        public:
              SeniorCitizen(){
                type="SeniorCitizen";
              } 
                

};


class Employee: public Customer{
        public:
              Employee(){
                type="Employee";
              } 
                

};
#endif
