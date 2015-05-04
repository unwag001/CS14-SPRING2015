/*  Ugochuku Nwagbala
    861116723
    4/25/15
*/
#include "lab4.h"

int main (int argc, char *argv[])
{
      
      //int arg = 1; //*argv[1];
      
      preorder(atoi(argv[1]));
      
      cout << endl;
      
      postorder(atoi(argv[1]));
      
      cout << endl;

      outSortedTree(atoi(argv[1]));
      
      //cout << endl;
      
      return 0;
}