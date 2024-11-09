/*
參考附件檔 HW0.cpp(此次作業所需的程式檔，可編譯執行，但功能並不完全)，撰寫底下的函式。
1.printArrayForward(...)：運用疊代(iteration)的方式，將Array裡的數字順向輸出到螢幕。
2.printArrayBackward(...)：運用遞迴(recursion)的方式，將陣列裡的數字反向輸出到螢幕。
3.printListForward(...)：運用疊代(iteration)的方式，將List裡的數字順向輸出到螢幕。
4.printListBackward(...)：運用遞迴(recursion)的方式，將List裡的數字反向輸出到螢幕。
*/

#include <iostream>

using namespace std;

#define MAX_terms 5

typedef struct node {
    int data;
    node *next;
}nodePtr;

nodePtr *inputListData(int num, nodePtr *headPtr) {
    nodePtr *newPtr = new nodePtr();
    newPtr->data = num;
    if(!headPtr)
        return newPtr;
    else {
        nodePtr *curPtr = headPtr;
        while(curPtr->next) {
            curPtr = curPtr->next;
        }
        curPtr->next = newPtr;
        return headPtr;
    }
}

void printArrayForward(int a[]) { 

    // add your code here

    for(int i = 0; i < MAX_terms; i++) {
        cout << a[i] << " ";
    }
}

void printArrayBackward(int a[], int i) { 

    // add your code here

    if(i == MAX_terms - 1) {
        cout << a[i] << " ";
        return;
    }
    printArrayBackward(a, i + 1);
    cout << a[i] << " ";
}

void printLinkForward(nodePtr *Ptr) { 

    // add your code here
    
    while(Ptr) {
        cout << Ptr->data << " ";
        Ptr = Ptr->next;
    }
}

void printLinkBackward(nodePtr *Ptr) { 

    // add your code here
    
    if(!Ptr->next) {
        cout << Ptr->data << " ";
        return;
    }
    printLinkBackward(Ptr->next);
    cout << Ptr->data << " ";
}

int main() {
    while(true) {
        int num;
        int array[MAX_terms] = { 0 };
        nodePtr *headPtr = nullptr;
    
        cout << "Input " << MAX_terms << " numbers: ";
        for(int i = 0; i < MAX_terms; i++) {
            cin >> num;
            array[i] = num;
            headPtr = inputListData(num, headPtr);
        }
    
        cout << "\nArray Forward Iteratively: ";
        printArrayForward(array);
        cout << "\nArray Backward Recursively: ";
        printArrayBackward(array, 0);
        cout << "\nList Forward Iteratively: ";
        printLinkForward(headPtr);
        cout << "\nList Backward Recursively: ";
        printLinkBackward(headPtr);
    }
    
    return 0;
}
