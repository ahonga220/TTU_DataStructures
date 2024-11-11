#include "BagInterface.h"
#include <cstddef>
#include <string>

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	bool removeDuplicate();
	void clear();
   	vector<ItemType> toVector() const;
}; 


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
} 

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
} 

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
} 

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
} 

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;

	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   	return bagContents;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{

	// add your code here

	// 若陣列已滿，直接返回 false
	if (itemCount >= maxItems)
	        return false;
	
	// 檢查新項目是否已存在，若重複則返回 false
	for (size_t i = 0; i < itemCount; i++) {
		if (items[i] == newEntry)
	            return false;
	}
	    
	// 添加新項目並增加 itemCount，返回 true 表示成功
	items[itemCount++] = newEntry;
	return true;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::removeDuplicate()
{
	return false;
}
