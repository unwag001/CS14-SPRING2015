//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Quynh Nguyen <qnguy019>
// SID: 861149235
// Date: April 27, 2015
// Lab 3
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <stack>
#include "TwoStacksFixed.h"
#include "TwoStacksOptimal.h"

using namespace std;
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C);
template<typename T>
void displayStack(stack<T> A);
void test1();
void test2();
void test3();

int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    if (n > 0)
    {
        showTowerStates(n - 1, A, C, B);
        if (A.empty()) return;
        C.push(A.top());
        A.pop();
        cout << "A: ";
        displayStack(A);
        cout << "B: ";
        displayStack(B);
        cout << "C: ";
        displayStack(C);
        cout << endl;
        
        showTowerStates(n - 1, B, A, C);
    }

}
template<typename T>
void displayStack(stack<T> A)
{
    while(!A.empty())
    {
        cout << A.top() << ' ';
        A.pop();
    }
    cout << endl;
}

void test1()
{
    cout << "Test 1: TwoStacksFixed(6, 3)." << endl;
    TwoStacksFixed<int> test(6, 3);
    cout << "-Stack 1 pushed in three 1's." << endl;
    test.pushStack1(1);
    test.pushStack1(1);
    test.pushStack1(1);
    
    cout << "-Stack 2 pushed in two 2's." << endl;
    test.pushStack2(2);
    test.pushStack2(2);
    if(test.isEmptyStack1()) cout << "Stack 1 is Empty." << endl;
    if(test.isEmptyStack2()) cout << "Stack 2 is Empty." << endl;

    if(test.isFullStack1()) cout << "Stack 1 is Full" << endl;
    if(test.isFullStack2()) cout << "Stack 2 is Full" << endl;
    cout << "Display actual array: ";
    test.displayArray();
    cout << endl;
    cout << "Display Stack 1: ";
    test.displayStack1();
    cout << endl;
    cout << "Display Stack 1: ";
    test.displayStack2();
    cout << endl;
    cout << "-Stack 2 pushed in a 3." << endl;
    test.pushStack2(3);
    cout << "Display actual array: ";
    test.displayArray();
    cout << endl;
    cout << "Display Stack 1: ";
    test.displayStack1();
    cout << endl;
    cout << "Display Stack 2: ";
    test.displayStack2();
    cout << endl;
    if(test.isEmptyStack1()) cout << "Stack 1 is Empty." << endl;
    if(test.isEmptyStack2()) cout << "Stack 2 is Empty." << endl;

    if(test.isFullStack1()) cout << "Stack 1 is Full" << endl;
    if(test.isFullStack2()) cout << "Stack 2 is Full" << endl << endl;
}

void test2()
{
    cout << "Test 2: TwoStacksOptimal(10)." << endl;
    TwoStacksOptimal<int> test(10);
    cout << "-Stack 1 pushed in seven 1's." << endl;
    test.pushFlexStack1(1);
    test.pushFlexStack1(1);
    test.pushFlexStack1(1);
    test.pushFlexStack1(1);
    test.pushFlexStack1(1);
    test.pushFlexStack1(1);
    test.pushFlexStack1(1);

    cout << "-Stack 2 pushed in two 2's." << endl;
    test.pushFlexStack2(2);
    test.pushFlexStack2(2);
    if(test.isEmptyStack1()) cout << "Stack 1 is Empty." << endl;
    if(test.isEmptyStack2()) cout << "Stack 2 is Empty." << endl;

    if(test.isFullStack1()) cout << "Stack 1 is Full" << endl;
    if(test.isFullStack2()) cout << "Stack 2 is Full" << endl;
    cout << "Display actual array: ";
    test.displayArray();
    cout << endl;
    cout << "Display Stack 1: ";
    test.displayStack1();
    cout << endl;
    cout << "Display Stack 2: ";
    test.displayStack2();
    cout << endl;
    cout << "-Stack 2 pushed in a 3 then a 2." << endl;
    test.pushFlexStack2(3);
    test.pushFlexStack2(2);
    cout << "Display actual array: ";
    test.displayArray();
    cout << endl;
    cout << "Display Stack 1: ";
    test.displayStack1();
    cout << endl;
    cout << "Display Stack 2: ";
    test.displayStack2();
    cout << endl;
    if(test.isEmptyStack1()) cout << "Stack 1 is Empty." << endl;
    if(test.isEmptyStack2()) cout << "Stack 2 is Empty." << endl;

    if(test.isFullStack1()) cout << "Stack 1 is Full" << endl;
    if(test.isFullStack2()) cout << "Stack 2 is Full" << endl << endl;
}

void test3()
{
    cout << "Test 3: Tower of Hanoi." << endl;
    stack<int> A;
    A.push(5);
    A.push(4);
    A.push(3);
    A.push(2);
    A.push(1);
    stack<int> B;
    stack<int> C;
    cout << "Stack A before function: ";
    displayStack(A);
    cout << "Stack B before function: ";
    displayStack(B);
    cout << "Stack C before function: ";
    displayStack(C);
    showTowerStates(5, A, B, C);
    cout << "Done with function" << endl;
    cout << "Stack A after function: ";
    displayStack(A);
    cout << "Stack B after function: ";
    displayStack(B);
    cout << "Stack C after function: ";
    displayStack(C);
    cout << endl;
}