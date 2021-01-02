#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>

using namespace std;

namespace listsavitch
{
	template < class ItemType>
	class GenericList
	{
	public:
		GenericList(int max);
		//Initializes the object to an empty list that can hold up to
			//max items of type ItemType.
		~GenericList();
		//Returns all the dynamic memory used by the object to the freestore.

		int length() const;
		//Returns the number of items on the list.

		void add(ItemType newItem);
		//Precondition: The list is not full.
			//Postcondition: The newItem has been added to the list.

		bool full() const;
		//Returns true if the list is full.

		void erase();
		//Removes all items from the list so that the list is empty.

		friend ostream& operator <<(ostream& outs,
			const GenericList<ItemType>& theList)
		{
			for (int i = 0; i < theList.currentLength; i++)
				outs << theList.item[i] << endl;
			return outs;
		}

		ItemType getCurrent();

	private:
		ItemType* item; //pointer to the dynamic array that holds the list.
		int maxLength; //max number of items allowed on the list.
		int currentLength; //number of items currently on the list.
	};
}//listsavitch
#endif //GENERICLIST_H