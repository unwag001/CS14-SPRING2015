/*  Ugochuku Nwagbala
    861116723
    4/25/15
*/

#include <iostream>

using namespace std;

template <class T>
class TwoStackFixed
{
    public:
    
    TwoStackFixed(int size, int maxtop)
    {
        arrSize = size;
        arr = new T[size];
        stack1 = 0;
        stack2 = size;
        max = maxtop;
    }
    
    void pushStack1(T value)
    {
        if (stack1 < max)
        {
            arr[stack1] = value;
            stack1++;
            display();
            //cout << "adding value... " << arr[value] << endl;
        }
    
        else 
        {
            cout << "Not enough room!!!!" << endl;
            exit(1);
        }
    }
    
    void pushStack2(T value)
    {
        if (max <= stack2 -1)
        {
            stack2--;
            arr[stack2] = value;
            display();
        }
    
        else 
        {
            cout << "Not enough room!!!" << endl;
            exit(1);
        }
    }
    
    void display()
    {
        for (unsigned i =0; i < arrSize; i++)
        {
            if (arr[i] == 0)
            {
                cout << ' ';
            }
            else 
            {
                cout << arr[i] << ' ';
            }
        }
        
        cout << endl;
    }
    
    T popStack1()
    {
        if (stack1 > 0)
        {
            T temp = arr[stack1];
            arr[stack1-1] =0;
            stack1--;
            return temp;
        }
        else
        {
            cout << "nothing to pop!!!" << endl;
            return(1);
        }
    }
    
    T popStack2()
    {
        if (stack2 < arrSize)
        {
            T temp = arr[stack2];
            arr[stack2] =0;
            stack2++;
            return temp;
        }
        
        else 
        {
            cout << "nothing to pop!!!" << endl;
            return(-1);
        }
    }
    
    bool isFullStack1()
    {
        if (stack1 +1 > max)
        {
            cout << "stack1 is full" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack1 is not full" << endl;
            return false;
        }
    }
    
    bool isFullStack2()
    {
        if (stack2 -1 < max)
        {
            cout << "stack2 is full" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack2 is not full" << endl;
            return false;
        }
    }
    
    bool isEmptyStack1()
    {
        if (stack1 == 0)
        {
            cout << "stack1 is empty" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack1 is not empty" << endl;
            return false;
        }
    }
    
    bool isEmptyStack2()
    {
        if (stack2 == arrSize)
        {
            cout << "stack2 is empty" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack2 is not empty" << endl;            
            return false;
        }
    }
    
    private:
    T *arr;
    int arrSize;
    int stack1;
    int stack2;
    int max;
};

template <class T>
class TwoStackOptimal 
{
    public:
    
    TwoStackOptimal(int size)
    {
        arrSize = size; 
        arr = new T[size];
        stack1 = 0;
        stack2 = size;
    }
    
    void pushFlexStack1(T value)
    {
        if (stack1 < stack2 )
        {
            arr[stack1] = value;
            stack1++;
            display();
        }
        
        else 
        {
            cout << "not enough room!!!" << endl;
            exit(-1);
        }
    }
    
    void pushFlexStack2(T value)
    {
        if (stack1 < stack2 )
        {
            stack2--;
            arr[stack2] = value;
            display();
        }
        
        else 
        {
            cout << "not enough room!!!" << endl;
            exit(-1);
        }
    }
    
    T popFlexStack1()
    {
        if (stack1 > 0 && stack1 <= stack2)
        {
            T temp = arr[stack1];
            arr[stack1-1] =0;
            stack1--;
            return temp;
        }
        else
        {
            cout << "nothing to pop!!!" << endl;
            return(1);
        }
    }
    
    T popFlexStack2()
    {
        if (stack2 < arrSize && stack2 >= stack1)
        {
            T temp = arr[stack2];
            arr[stack2] =0;
            stack2++;
            return temp;
        }
        
        else 
        {
            cout << "nothing to pop!!!" << endl;
            return(-1);
        }
    }
    
    
    bool isFullStack1()
    {
        if (stack1 +1 > stack2)
        {
            cout << "stack1 is full" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack1 is not full" << endl;
            return false;
        }
    }
    
    bool isFullStack2()
    {
        if (stack2 -1 < stack1)
        {
            cout << "stack2 is full" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack2 is not full" << endl;
            return false;
        }
    }
    
    bool isEmptyStack1()
    {
        if (stack1 == 0)
        {
            cout << "stack1 is empty" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack1 is not empty" << endl;
            return false;
        }
    }
    
    bool isEmptyStack2()
    {
        if (stack2 == arrSize)
        {
            cout << "stack2 is empty" << endl;
            return true;
        }
        
        else 
        {
            cout << "stack2 is not empty" << endl;            
            return false;
        }
    }
    
    void display()
    {
        for (unsigned i =0; i < arrSize; i++)
        {
            if (arr[i] == 0)
            {
                cout << ' ';
            }
            else 
            {
                cout << arr[i] << ' ';
            }
        }
        
        cout << endl;
    }
    
    
    private:
    T *arr;
    int stack1;
    int stack2;
    int arrSize;
};

// void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C);
// {
    
//     if (n ==0)
//     {
//         cout << "Moved " << n << " from peg " << A << " to peg" << C;
//     }
// }
