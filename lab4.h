/*  Ugochuku Nwagbala
    861116723
    4/25/15
*/

#include <queue>
#include <map>
#include <iostream>

using namespace std;


void printPreorder (int m, int n, int k)
{
      if (n +m < k)
      {
            cout << m << ' ' << n << endl;
            
            printPreorder(2*m -n, m, k);
            printPreorder(2*m +n, m, k);
            printPreorder(m + 2*n, n, k);
      }
      return;
}
void printPostorder (int m, int n, int k)
{
      if (n+m < k)
      {
            printPostorder(2*m -n, m, k);
            printPostorder(2*m +n, m, k);
            printPostorder(m + 2*n, n, k);
            
            cout << m << ' ' << n << endl;
      }
      return;
}

void postorder (int arg)
{
      if (arg<4) {
            cout << "There are none." << endl;
            return;
      }
      cout << "postorder output is: " << endl;
      if (arg == 4) {
            printPostorder(2,1,arg);
            return;
      }
      else if (arg >4) 
      {
            printPostorder(2,1,arg);
            printPostorder(3,1,arg);
      }
      return;
}

void preorder (int arg)
{
      if (arg<4) {
            cout << "There are none." << endl; 
            return;
            
      }
      cout << "preorder output is: " << endl;
      
      if (arg == 4) {
            printPreorder(2,1,arg);
            return;
      }
      else if (arg >4) 
      {
            printPreorder(2,1,arg);
            printPreorder(3,1,arg);
      }
      return;
}

void sortedTree (int m, int n, int k, priority_queue<pair<int,int> > outSorted)
{
      pair<int,int> coprimePair;
      
      if (n+m < k)
      {
            coprimePair.first = m;
            coprimePair.second = n;
            printPostorder(2*m -n, m, k);
            printPostorder(2*m +n, m, k);
            printPostorder(m + 2*n, n, k);
            outSorted.push(coprimePair);
      }
      
      // for (unsigned i =0; i < outSorted.size(); i++)
      // {
      //       cout << outSorted.top().first << ' ' 
      //       << outSorted.top().second << endl;
      //       outSorted.pop();
      // }
}

void outSortedTree (int arg)
{
      priority_queue<pair<int,int>> output;
      cout << "Sorted output is: " << endl;
      sortedTree(2,1,arg,output);
      sortedTree(3,1,arg,output);
      
      for (unsigned i =0; i < outSorted.size(); i++)
      {
            cout << outSorted.top().first << ' ' 
            << outSorted.top().second << endl;
            outSorted.pop();
      }
}