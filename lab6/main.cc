#include "selectionsort.h"
#include <vector>

using namespace std;

int main()
{

      vector<int> v;
      v.push_back(2);
      v.push_back(4);
      v.push_back(5);
      v.push_back(1);
      v.push_back(8);
      v.push_back(9);
      
      cout << "pre: ";
      print(v);
      cout << "post: ";
      selectionsort(v);
      print(v);
      
      vector<int> v2;
      
      cout << "pre:  ";
      print(v2);
      cout << "post: ";
      selectionsort(v2);
      print(v2);
      
      vector <pair<int,int> > v3;
      pair<int,int> pairToPush;
      
      pairToPush = make_pair(1,2);
      v3.push_back(pairToPush);
      pairToPush = make_pair(3,-1);
      v3.push_back(pairToPush);
      pairToPush = make_pair(-1,3);
      v3.push_back(pairToPush);
      pairToPush = make_pair(0,0);
      v3.push_back(pairToPush);
      pairToPush = make_pair(2,3);
      v3.push_back(pairToPush);
      pairToPush = make_pair(1,2);
      v3.push_back(pairToPush);
      pairToPush = make_pair(1,-2);
      v3.push_back(pairToPush);
      pairToPush = make_pair(8,10);
      v3.push_back(pairToPush);
      
      cout << "pre:  ";
      printPair(v3);
      cout << "post: ";
      selectionsort(v3);
      printSortedPair(v3);
      
      vector <pair<int,int> > v4;
      
      pairToPush = make_pair(10,2);
      v4.push_back(pairToPush);
      pairToPush = make_pair(3,-1);
      v4.push_back(pairToPush);
      pairToPush = make_pair(-8,0);
      v4.push_back(pairToPush);
      pairToPush = make_pair(1,1);
      v4.push_back(pairToPush);
      pairToPush = make_pair(1,1);
      v4.push_back(pairToPush);
      pairToPush = make_pair(0,0);
      v4.push_back(pairToPush);
      pairToPush = make_pair(10,2);
      v4.push_back(pairToPush);
      pairToPush = make_pair(5,5);
      v4.push_back(pairToPush);
      pairToPush = make_pair(5,-5);
      v4.push_back(pairToPush);
      pairToPush = make_pair(0,0);
      v4.push_back(pairToPush);
      pairToPush = make_pair(10,2);
      v4.push_back(pairToPush);
      
      cout << "pre:  ";
      printPair(v4);
      cout << "post: ";
      selectionsort(v4);
      printSortedPair(v4);
      
      vector <pair<int,int> > v5;
      pairToPush = make_pair(-1,3);
      v5.push_back(pairToPush);
      pairToPush = make_pair(0,0);
      v5.push_back(pairToPush);
      pairToPush = make_pair(1,-2);
      v5.push_back(pairToPush);
      pairToPush = make_pair(1,2);
      v5.push_back(pairToPush);
      pairToPush = make_pair(2,3);
      v5.push_back(pairToPush);
      pairToPush = make_pair(3,-1);
      v5.push_back(pairToPush);
      pairToPush = make_pair(8,10);
      v5.push_back(pairToPush);
      
      cout << "pre:  ";
      printPair(v5);
      cout << "post: ";
      selectionsort(v5);
      printSortedPair(v5);
      
      return 0;
}
