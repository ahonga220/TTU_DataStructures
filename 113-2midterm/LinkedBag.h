#include "BagInterface.h"
#include "Node.h"
#include <cstddef>
#include <string>

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   bool removeDuplicate();
   void clear();
   vector<ItemType> toVector() const;
}; 

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  


template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
} 

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
} 

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   return itemCount;
} 

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;

   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
   itemCount = 0;
} 

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{

	// add your code here

       	// 宣告指標 curPtr 指向串列的開頭（headPtr）
    	Node<ItemType> *curPtr = headPtr;
   
    	// 使用迴圈檢查鏈結串列中是否已有新項目（避免重複）
    	while (curPtr) {
        	// 若找到重複項目，則返回 false，不執行添加
        	if (curPtr->getItem() == newEntry)
            		return false;
        	// 若 curPtr 指向鏈結串列的最後一個節點，則中止迴圈
        	if (!curPtr->getNext())
            		break;
        	// 移動 curPtr 指向下一個節點
        	curPtr = curPtr->getNext();
    	}

	// 建立新節點 tempPtr，並存入新項目 newEntry
	Node<ItemType> *tempPtr = new Node<ItemType>(newEntry);
	   
	if (curPtr) // 若 curPtr 非空（即鏈結串列有其他節點），將新節點添加到串列尾端
		curPtr->setNext(tempPtr);
	else // 若 curPtr 為空，表示鏈結串列為空，將新節點設為 headPtr
	        headPtr = tempPtr;
	   
	// 更新鏈結串列的項目數
	itemCount++;
	return true; // 成功添加新項目
}  

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;

	while ((curPtr != nullptr) && (counter < itemCount)) {
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}

	return bagContents;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	return false;
}

template<class ItemType>
bool LinkedBag<ItemType>::removeDuplicate()
{
	return false;
}
