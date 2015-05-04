#include <iostream>
#include <forward_list>


using namespace std;

bool isPrime(int n)
{
    int check =0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            check++;
        }
    }
    if (check ==2)
    {
        return true;
    }
    else if (check != 2)
    {
        return false;
    }
}

int primeCount(forward_list<int> lst)
{
    //forward_list<int>::iterator itr;
    int count = 0;
    
    if (lst.empty())
    {
        return count;
    }
    
    else 
    {
        if (isPrime(lst.front()))
        {
            count++;
            lst.pop_front();
            return count += primeCount(lst);
        }
        else if (!isPrime(lst.front()))
        {
            lst.pop_front();
            return count += primeCount(lst);
        }
    }
}

int main()
{
    forward_list<int> l1;
    
    l1.push_front(2);
    l1.push_front(7);
    l1.push_front(24);
    l1.push_front(10);
    l1.push_front(19);
    l1.push_front(23);
    // if (isPrime(13))
    // {
    //     cout << "true";
    // }
    // else if (!isPrime(13))
    // {
    //     cout << "false";
    // }
    
    // if (isPrime(l1.front()))
    // {
    //     cout << "true";
    // }
    // else if (!isPrime(l1.front()))
    // {
    //     cout <<"false";
    // }
    
    cout << primeCount(l1) << endl;
    
    return 0;
}