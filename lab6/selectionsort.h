/* 
Ugochuku Nwagbala
861116723
unwag001
*/

#include <iostream>
#include <utility>

using namespace std;

int moves =0;
template<typename L>

void selectionsort(L &l) 
{
      typename L::iterator itr1;
      typename L::iterator itr2;
      typename L::iterator min;
      moves =0;
      
      for (itr1 = l.begin(); itr1 != l.end(); itr1++)
      {
            min = itr1;
            for (itr2 = itr1+1; itr2 != l.end(); itr2++)
            {
                  if (*min > * itr2)
                  {
                        min = itr2;
                  }
            }
            
            if (*min != *itr1)
            {
                  moves+= 3;
                  swap(*min,*itr1);
            }
      }
}

template<typename L>

void print(L l)
{
      if (l.empty())
      {
            cout << endl;
            return;
      }
      
      else if (!l.empty())
      {
            for (typename L::iterator itr = l.begin(); itr != l.end(); itr++)
            {
                  cout << *itr << ' ';
            }
            cout << endl;
      }
}

template <typename L>

void printPair (L l)
{
      if (l.empty())
      {
            cout << endl;
            return;
      }
      
      else if (!l.empty())
      {
            for (auto itr = l.begin(); itr != l.end(); itr++)
            {
                  cout << '(' << itr->first << "," << itr->second <<')' << ' ';
            }
            cout << endl;
      }
}

template <typename L>

void printSortedPair (L l)
{
      if (l.empty())
      {
            cout << endl;
            return;
      }
      
      else if (!l.empty())
      {
            for (auto itr = l.begin(); itr != l.end(); itr++)
            {
                  cout << "(" << itr->first << "," << itr->second <<")" << ' ';
            }
      }
      cout << endl << "0 copies and " << moves << " moves" << endl;
}