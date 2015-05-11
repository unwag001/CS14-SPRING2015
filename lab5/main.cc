#include "lab5.h"

using namespace std;

int main ()
{
      cout << "Part 1: " << endl;
      
      BST<int> mytree;
      mytree.insert(50);
      mytree.insert(20);
      mytree.insert(10);
      mytree.insert(40);
      mytree.insert(35);
      mytree.insert(45);
      mytree.insert(60);
      mytree.insert(70);
      
      // mytree.inorder();
      mytree.minCover();
      mytree.displayMinCover();
      
      
      cout << "Part 3: " << endl;
      
      mytree.vertSum();
      
      
      return 0;
}