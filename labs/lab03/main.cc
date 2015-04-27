#include "lab3.h"

using namespace std;

int main()
{
    
    // TwoStackFixed<int> taco(10,5); 
    // taco.pushStack1(1);
    // taco.popStack1();
    // taco.pushStack2(2);
    // taco.pushStack2(3);
    // taco.popStack2();
    // taco.pushStack2(4);
    // taco.pushStack2(5);
    // taco.pushStack2(6);
    
    
    // taco.popStack1();
    // taco.pushStack1(7);
    // taco.pushStack1(8);
    // taco.pushStack1(9);
    // taco.pushStack1(12);
    // taco.isFullStack2();
    // taco.isFullStack1();
    // taco.isEmptyStack1();
    
    TwoStackOptimal<char> legolas(10);
    
    char chel = 'a';
    
    for (int i = 0; i < 7; i++)
    {
        legolas.pushFlexStack1(chel);
        chel++;
    }
    
    legolas.pushFlexStack2('m');
    legolas.pushFlexStack2('m');
    legolas.popFlexStack1();    
    legolas.pushFlexStack1('m');
    legolas.isEmptyStack1();
    legolas.isEmptyStack2();
    legolas.isFullStack1();
    legolas.isFullStack2();
    
    return 0;
}