#include "ItemsHelper.h"

int Items::count=0;
Chips* Chips::chi = NULL;
Chocolates* Chocolates::choc = NULL;
Eggs* Eggs::e = NULL;
SoftDrinks* SoftDrinks::sfd = NULL;


/*
* Method to initialize all the items in the store
*/
void ItemsHelper::loadAll(){
	 Chips::loadChips();
         Chocolates::loadChocolates();
	 Eggs::loadEggs();	
	 SoftDrinks::loadSoftdrinks();
}


/*
* Method to get the instance of items based on the type
*/
Items* ItemsHelper::getItems(int type){

	Items* it;
	if(type==1){
		it = Chips::getInfo();
	}
	else if(type==2){
		it = Chocolates::getInfo();
	}
	else if(type==3){
		it = Eggs::getInfo();
	}
	else if(type==4){
		it = SoftDrinks::getInfo();
	}

}

/*
* Method to deinitialize all the items in the store
*/
void ItemsHelper::unloadAll(){

	 Chips::unloadChips();
         Chocolates::unloadChocolates();
	 Eggs::unloadEggs();	
	 SoftDrinks::unloadSoftdrinks();
}

/*
* Method to get the number of items in the store
*/

int ItemsHelper::getCount(){
	return Items::getCount();
}
