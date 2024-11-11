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

	// 檢查陣列是否有空間可添加新項目（判斷當前項目數是否小於最大容量）
	bool hasRoomToAdd = (itemCount < maxItems);

	if(hasRoomToAdd) { // 如果有空間
		// 檢查新項目是否已經存在於陣列中
		for(size_t i = 0; i < itemCount; i++) {
			if(items[i] == newEntry) // 若找到重複項目
				return false; // 返回 false，不添加新項目
		}
		// 若未發現重複項目，將新項目添加到陣列並增加 itemCount
		items[itemCount++] = newEntry;
		return true; // 添加成功，返回 true
	}

	// 若無法添加（無空間），返回 false
	return false;
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
