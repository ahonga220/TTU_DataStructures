/*
使用Array來存放資料，撰寫一支具有輸入數字和刪除數字功能的程式。
1.輸入功能：使用者每輸入一個整數，便將它按照由小到大的順序插入到Array中，然後將Array裡儲存的值一一display到螢幕上。
注意：必須直接插入到定位，不可插入後再來排序。
2.刪除功能：使用者每輸入一個整數，便將Array中所有相同數字的節點刪除；若Array中無該數字，則不處理。
最後將Array裡儲存的值一一display到螢幕上。
*/

//add your code here

#include <iostream>
#include <cctype>

using namespace std;

#define MAX_terms 100

int main() {
    int ArrayTerms[MAX_terms] = { 0 }, curArraySize = 0, inData;
    char userChoice;

    while(cout << "\nInput integer to array or Delete integer to array: ") {
        cin >> userChoice;
        if(toupper(userChoice) == 'I') {
            cin >> inData;
            if(!curArraySize)
                ArrayTerms[curArraySize] = inData;
            else {
                for(int i = 0; i <= curArraySize; i++) {
                    if(ArrayTerms[i] > inData) {
                        for(int j = curArraySize; j >= i; j--) {
                            ArrayTerms[j] = ArrayTerms[j - 1];
                        }
                        ArrayTerms[i] = inData;
                        break;
                    }
                    else if(i == curArraySize) {
                        ArrayTerms[i] = inData;
                    }
                }
            }
            curArraySize++;
        }
        else if(toupper(userChoice) == 'D') {
            cin >> inData;
            for(int i = 0; i < curArraySize; i++) {
                if(ArrayTerms[i] == inData) {
                    for(int j = i; j < curArraySize; j++) {
                        ArrayTerms[j] = ArrayTerms[j + 1];
                    }
                    curArraySize--; i--;
                }
            }
        }
        for(int i = 0; i < curArraySize; i++) {
            cout << ArrayTerms[i] << " ";
        }
    }

    return 0;
}

/*
TestData
i0 i2 i0 i0 i2 i5 i5 i9 i9 i5 d0 d5 d2 i2 d9 d2
d9 d8 i5 i5 i0 i0 i2 i5 i0 i9 d5 i9 d0 i2 d9 i2 d2
i2 i9 i-9 i-8 i2 i8 i7 i-7 d5 d6 d-9 d9 d8 d-8 i2 d7 d7 d2 d-7
*/
