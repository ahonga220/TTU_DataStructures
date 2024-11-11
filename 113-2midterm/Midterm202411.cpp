// Midterm202411.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <cctype>
#include "polynomial1.h"
#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"

#define SIZE 10

using namespace std;

void input(string sMessage, string& sInputString)
{
	cout << sMessage << endl;
	cin >> sInputString;
	return;
}

void output(string sMessage)
{
	if (sMessage.length() > 0)
		cout << endl << sMessage << endl;

	return;
}

int inputNumber(string sMessage, int A[])
{
	int i = 0;

	for (; i < SIZE; i++) {
		cout << sMessage;
		cin >> A[i];

		if (A[i] == 0)
			break;
	}

	return i;
}

// ================ Question 1 Begins Here ==================

// 遞迴檢查陣列是否為嚴格遞增數列
bool isIncreasing(int A[], int size)
{

	// add your code here

	// 若陣列大小為 1，返回 false，視為非遞增
    	// 若最後一個元素小於或等於倒數第二個元素，則陣列不是遞增的
    	// 若陣列剩下兩個元素且符合遞增條件，返回 true
   	 // 否則，遞迴檢查陣列的前 size - 1 個元素
	return  (size == 1 || A[size - 1] <= A[size - 2]) ? false : (size == 2) ? true : isIncreasing(A, size - 1);
	
	// if(size == 1 || A[size - 1] <= A[size - 2]) return false
	// if(size == 2) return true
	// return isIncreasing(A, size - 1)
}

// 遞迴檢查陣列是否對稱
bool isSymmetrical(int A[], int begin, int end)
{

	// add your code here

	// 若起始索引大於或等於終止索引，則視為對稱
	// 若起始索引元素不等於終止索引元素，則不是對稱
	// 否則，遞迴檢查去掉兩端元素後的子陣列
	return (begin >= end) ? true : (A[begin] != A[end]) ? false : isSymmetrical(A, begin + 1, end - 1);
	
	// if(begin >= end) return true
	// if(A[begin] != A[end]) return false
	// return isSymmetrical(A, begin + 1, end - 1)
}

// 遞迴輸出陣列中的奇數
void printOddNumbers(int A[], int size)
{

	// add your code here

	// 基礎條件：若陣列大小為 0，則返回
	if(size == 0) 
		return;
	// 遞迴處理陣列的前 size - 1 個元素
	printOddNumbers(A, size - 1);
	// 若當前元素為奇數，則輸出
	if(A[size - 1] % 2) 
		cout << A[size - 1] << " ";
}

// 遞迴計算陣列中的奇數總和
int SumOddNumbers(int A[], int size)
{
	// add your code here

	// 基礎條件：若陣列大小為 0，則總和為 0
	// 若當前元素為奇數，則加上該元素並遞迴處理剩餘陣列
	// 若當前元素為偶數，則跳過並遞迴處理剩餘陣列
	return (!size) ? 0 : (A[size - 1] % 2) ? A[size - 1] + SumOddNumbers(A, size - 1) : SumOddNumbers(A, size - 1);
	
	// if(!size) return 0
	// if(A[size - 1] % 2) return A[size - 1] + sumoddnumbers(A, size - 1)
	// else return sumoddnumbers(A, size - 1)
	
}

void doQ1()
{
	int n;

	cout << "How many integers? ";
	cin >> n;

	int* A = new int[n];

	cout << "Input integers: ";

	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << "The intrgers are ";

	if (!isIncreasing(A, n))
		cout << "NOT ";

	cout << "in increasing order\n";

	cout << "The intrgers are ";

	if (!isSymmetrical(A, 0, n - 1))
		cout << "NOT ";

	cout << "symmetrical\n";

	cout << "Odd numbers: ";
	printOddNumbers(A, n);

	cout << "\nSum of odd numbers: ";
	cout << SumOddNumbers(A, n);
	cout << endl;
}

// ================ Question 1 Ends Here ==================

// ================ Question 2 Begins Here =================
void doQ2()
{
	ArrayPolynomial aArrPoly, bArrPoly, cArrPoly;
	LinkedPolynomial aLinkPoly, bLinkPoly, cLinkPoly;

	int coef, expo;

	aArrPoly.clear();

	for (int i = 0; i < MAX_TERMS; i++) {
		cout << "\ninput A's coefficient and exponent: ";
		cin >> coef >> expo;

		if (expo == 0 && coef == 0)
			break;

		aArrPoly.inputTerms(coef, expo);
		aLinkPoly.inputTerms(coef, expo);
	}

	cout << endl;

	for (int i = 0; i < MAX_TERMS; i++) {
		cout << "\ninput B's coefficient and exponent: ";
		cin >> coef >> expo;

		if (expo == 0 && coef == 0)
			break;

		bArrPoly.inputTerms(coef, expo);
		bLinkPoly.inputTerms(coef, expo);
	}

	cout << "\n\n[Array Polynomial]\n";
	cout << "\na(X) = ";
	aArrPoly.printArrayBasedPoly();
	cout << "\nCoefficient of Max degree's term: " << aArrPoly.maxDgreeCoef();
	cout << "\nb(X) = ";
	bArrPoly.printArrayBasedPoly();
	cout << "\nCoefficient of Max degree's term: " << bArrPoly.maxDgreeCoef();

	if (aArrPoly.contain(bArrPoly))
		cout << "\na(X) contains b(X)\n";
	else
		cout << "\na(X) does NOT contain b(X)\n";

	aArrPoly.difference(bArrPoly);
	cout << "After difference a(X) = ";
	aArrPoly.printArrayBasedPoly();

	cout << "\n\n[Link Polynomial]\n";
	cout << "\na(X) = ";
	aLinkPoly.printLinkBasedPoly();
	cout << "\nCoefficient of Max degree's term: " << aLinkPoly.maxDgreeCoef();
	cout << "\nb(X) = ";
	bLinkPoly.printLinkBasedPoly();
	cout << "\nCoefficient of Max degree's term: " << bLinkPoly.maxDgreeCoef();

	if (aLinkPoly.contain(bLinkPoly))
		cout << "\na(X) contains b(X)\n";
	else
		cout << "\na(X) does NOT contain b(X)\n";

	aLinkPoly.difference(bLinkPoly);
	cout << "After difference a(X) = ";
	aLinkPoly.printLinkBasedPoly();

	cout << "\n";
}
// ================ Question 2 Ends Here ==================

// ================ Question 3 Begins Here ==================

void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize() << " items: ";
	vector<string> bagItems = bag.toVector();
	int numberOfEntries = (int)bagItems.size();

	for (int i = 0; i < numberOfEntries; i++)
		cout << bagItems[i] << " ";

	cout << endl;
}

void bagTester(ArrayBag<string>& bag)
{
	string items[] = { "5E", "1A", "5E", "3C", "5E", "3C", "5E", "3C", "5E", "5E" };
	string otherItems[] = { "1A", "5E", "3C", "2B", "4D" };

	cout << "Add 10 items to the bag: ";

	for (int i = 0; i < 10; i++) {
		bag.add(items[i]);
		cout << items[i] << ' ';
	}
	cout << endl;
	displayBag(bag);
}

void displayBag(LinkedBag<string>* bagPtr)
{
	cout << "The bag contains " << bagPtr->getCurrentSize() << " items: ";
	vector<string> bagItems = bagPtr->toVector();

	int numberOfEntries = (int)bagItems.size();

	for (int i = 0; i < numberOfEntries; i++)
		cout << bagItems[i] << " ";

	cout << endl;
}

void bagTester(LinkedBag<string>* bagPtr)
{
	string items[] = { "5E", "1A", "5E", "3C", "5E", "3C", "5E", "3C", "5E", "5E" };

	cout << "Add 10 items to the bag: ";

	for (int i = 0; i < 10; i++) {
		bagPtr->add(items[i]);
		cout << items[i] << ' ';
	}
	cout << endl;
	displayBag(bagPtr);
}

void doQ3()
{
	char userChoice = ' ';

	while (toupper(userChoice) != 'X') {
		cout << "Enter \n 'A' to test the array-based implementation\n"
			<< " 'L' to test the link-based implementation or\n 'X' to exit: ";
		cin >> userChoice;

		if (toupper(userChoice) == 'A') {
			ArrayBag<string> bag;
			cout << "Testing the Array-Based Bag:" << endl;
			cout << "The initial bag is empty." << endl;
			bagTester(bag);
		}
		else {
			LinkedBag<string>* bagPtr = nullptr;
			bagPtr = new LinkedBag<string>();

			cout << "Testing the Link-Based Bag:" << endl;
			cout << "The initial bag is empty." << endl;
			bagTester(bagPtr);
			delete bagPtr;
			bagPtr = nullptr;
		}

		cout << "All done!\n\n" << endl;
	}
}

// ================ Question 3 Ends Here ==================

// ============== Main Program Begins Here ================

int main()
{
	string sCommand, sName, sNum, sMessage;

	while (1) {
		cout << endl;
		cout << "1. Recursive functions" << endl;
		cout << "2. Polynomial functions" << endl;
		cout << "3. Bag functions" << endl;
		input("Enter Question Number( 1 ~ 3 ) or 0 to Exit:", sNum);

		switch (sNum[0] - '0') {
		case 0:
			return 0;
		case 1:
			doQ1();
			break;
		case 2:
			doQ2();
			break;
		case 3:
			doQ3();
			break;
		}
	}
}

// ============== Main Program Ends Here ================
