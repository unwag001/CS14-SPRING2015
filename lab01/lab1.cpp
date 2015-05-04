#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

/* I didnt know whether to implement the functions in main or just create 
the functions and make sure they worked */

list<int> mergeList(list<int> l1, list<int> l2)
{
    list<int> l3;
    
    while (!l1.empty() || !l2.empty())
    {
        if (!l1.empty())
        {
            l3.push_back(l1.front());
            l1.pop_front();
        }
        if (!l2.empty())
        {
            l3.push_back(l2.front());
            l2.pop_front();
        }
    }
    
    return l3;
}

list<int> mergeSortList(list<int> l1, list<int> l2)
{
    list<int> l3;
    
    while (!l1.empty() || !l2.empty())
    {
        if (!l1.empty())
        {
            l3.push_back(l1.front());
            l1.pop_front();
        }
        if (!l2.empty())
        {
            l3.push_back(l2.front());
            l2.pop_front();
        }
    }
    l3.sort();
    return l3;
}

list<int> rotateList (list<int> l1, int n)
{
    list<int> l3;
    list<int>::iterator itr;
    list<int>::iterator itr2;
    itr = l1.begin();
    itr2 = itr;
    advance(itr,n);
    
    while(itr != l1.end())
    {
        swap(*itr,*itr2);
        itr++;
        itr2++;
    }
    
    while (!l1.empty())
    {
        l3.push_back(l1.front());
        l1.pop_front();
    }
    return l3;
}



int main()
{
    list<int> list1;
    list<int> list2;
    list<int> list3;
    //int x =0;
    //int y =0;
    
    
    list1.push_back(3);
    list1.push_back(14);
    list1.push_back(234);
    list1.push_back(8);
    
    list2.push_back(23);
    list2.push_back(1);
    list2.push_back(66);
    list2.push_back(0);
    
    // cout << "#input (enter x to quit)" << endl;
    
    // while(cin >> x)
    // {
    //     list1.push_back(x);
    //     if (x == 'x')
    //     {
    //         break;
    //     }
    // }
    
    // //cout << endl;
    
    // while (cin >> y)
    // {
    //     list2.push_back(y);
    //     if (y == 'x')
    //     {
    //         break;
    //     }
    // }
    
    
    //cout << "#output" << endl;
    
    list3 =rotateList(list1, 1);
    
    while (!list3.empty())
    {
        cout << list3.front() << ' ';
        list3.pop_front();
    }
    
    return 0;
}