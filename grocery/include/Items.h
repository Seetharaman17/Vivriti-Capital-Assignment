#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
using namespace std;

/*
*   Base & Derived classes base on the type of Items in the grocery store
*/
class Items{


	public:

		virtual string  getName(){
                        return name;
                }
                virtual int getAvlStock(){
                        return avlStock;
                }
                virtual double getPrice(){
                        return price;
                }
                virtual int checkout(int qty){
                        if(qty>avlStock){
                                return -1;
                        }else{
                                avlStock -= qty;
                                return 0;
                        }
                }

		

		static int getCount(){
			return count;
		}
	protected:
		string name;
		int avlStock;
		double price;
		static int count;
};


class Chips: public Items{

	public:
		static void loadChips(){

			if(chi==NULL){
				chi = new Chips();
				count++;	
			}	

		}

		static void unloadChips(){

			if(chi!=NULL){
				delete chi;
			}

		}


		static Chips* getInfo(){
			return chi;
		}


	private:
		Chips(){
			name = "CHIPS";
			avlStock = 100;
			price=10;
		}

		~Chips(){
			chi=NULL;
		}
		static Chips* chi;

};

class Chocolates: public Items{
	public:
		static void loadChocolates(){

			if(choc==NULL){ 
				choc = new Chocolates();
				count++;	
			}

		}


		static void unloadChocolates(){

			if(choc!=NULL){
				delete choc;
			}

		}


		static Chocolates* getInfo(){
			return choc;
		}


	private:
		Chocolates(){
			name = "CHOCOLATES";
			avlStock = 200;
			price=20;
		}

		~Chocolates(){
			choc=NULL;
		}

		static Chocolates* choc;

};



class Eggs : public Items{
	 public:
                static void loadEggs(){

                        if(e==NULL){
                                e = new Eggs();
                                count++;
                        }

                }


                static void unloadEggs(){

                        if(e!=NULL){
                                delete e;
                        }

                }


                static Eggs* getInfo(){
                        return e;
                }


        private:
                Eggs(){
                        name = "EGGS";
                        avlStock = 500;
                        price=5;
                }

                ~Eggs(){
                        e=NULL;
                }

                static Eggs* e;

	
	
};


class SoftDrinks : public Items{
	 public:
                static void loadSoftdrinks(){

                        if(sfd==NULL){
                                sfd = new SoftDrinks();
                                count++;
                        }

                }


                static void unloadSoftdrinks(){

                        if(sfd!=NULL){
                                delete sfd;
                        }

                }


                static SoftDrinks* getInfo(){
                        return sfd;
                }


        private:
                SoftDrinks(){
                        name = "SOFT DRINKS";
                        avlStock = 500;
                        price=15;
                }

                ~SoftDrinks(){
                        sfd=NULL;
                }

                static SoftDrinks* sfd;


};
#endif
