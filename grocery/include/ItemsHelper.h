#ifndef ITEMS_HELPER_H
#define ITEMS_HELPER_H
#include <iostream>
#include "Items.h"
using namespace std;

/*
*  Helper class that initializes the number of items in the store
*/

class ItemsHelper {

	public:

		ItemsHelper(){
		}

		~ItemsHelper(){
		}

		void loadAll();
		void unloadAll();

		Items* getItems(int type);
		int getCount();
};
#endif
