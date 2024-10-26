/*
1.輸入功能：使用者每輸入一個整數，便將它按照由小到大的順序插入到Linked List中。
最後將Linked List節點裡的值一一display到螢幕上。
2.刪除功能：使用者每輸入一個整數，便將Linked List所有相同數字的節點刪除；若List中無該數字，則不處理。
最後將Linked List節點裡的值一一display到螢幕上。
*/
#include <iostream>
#include <cctype>

using namespace std;

typedef struct node {
    int Data;
    node *next;
}LinkTerm;

void inputLinkData(int inData, LinkTerm *&headPtr) {
    LinkTerm *tempPtr = new LinkTerm();
    tempPtr->Data = inData;

    if(!headPtr)
        headPtr = tempPtr;
    else {
        LinkTerm *curPtr = headPtr;
        LinkTerm *prePtr = nullptr;
        while(curPtr) {
            if(inData < curPtr->Data) {
                if(curPtr == headPtr)
                    headPtr = tempPtr;
                else
                    prePtr->next = tempPtr;
                tempPtr->next = curPtr;
                break;
            }
            prePtr = curPtr;
            curPtr = curPtr->next;
            if(!curPtr)
                prePtr->next = tempPtr;
        }
    }
}

void deleteLinkData(int inData, LinkTerm *&headPtr) {
    LinkTerm *curPtr = headPtr;
    LinkTerm *prePtr = nullptr;
    while(curPtr) {
        if(curPtr->Data == inData) {
            LinkTerm *delePtr = nullptr;
            while(curPtr && curPtr->Data == inData) {
                delePtr = curPtr;
                curPtr = curPtr->next;
                delete delePtr;
            }
            if(prePtr)
                prePtr->next = curPtr;
            else
                headPtr = curPtr;
            break;
        }
        prePtr = curPtr;
        curPtr = curPtr->next;
    }
}

void printLinkTerm(LinkTerm *headPtr) {
    LinkTerm *curPtr = headPtr;
    while(curPtr) {
        cout << curPtr->Data << " ";
        curPtr = curPtr->next;
    }
}

int main() {
    LinkTerm *headPtr = nullptr;
    int inData;
    char userChoice;

    while(cout << "\nInput integer to array or Delete integer to array: ") {
        cin >> userChoice;
        if(toupper(userChoice) == 'I') {
            cin >> inData;
            inputLinkData(inData, headPtr);
        }
        else if(toupper(userChoice) == 'D') {
            cin >> inData;
            deleteLinkData(inData, headPtr);
        }
        printLinkTerm(headPtr);
    }

    return 0;
}