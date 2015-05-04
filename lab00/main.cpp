#include <iostream>

using namespace std;

// 1 find the sum of integers in a num
// 2 swap values of 2 integers w/o using a temp var

int sum (int num)
{
    int total=0;
    
    if (num == 0)
    {
        return total;
    }
    
    int dig = num % 10;
    
    num = num /10;
    
    total = dig + sum(num);
    
    return total;
    
}
    

int main ()
{
    int x = 5255;
    
    cout << sum(x);
    

    
    return 0;
}