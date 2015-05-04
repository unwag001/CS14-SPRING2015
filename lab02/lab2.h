template <class T> class List
{
    private:
    struct Node
    {
        T data;
        Node* next; 
    }
    Node* head;
    
    public:
    List(): data(0), next(NULL) {}
    void push_front(T value);
    void pop_front();
    void display();
    void elementSwap(int pos);
};

template <class T> 
void List::push_front(T value)
{
    Node<T>* temp = new Node<T>(value);
    
    temp->next = head;
    head = temp;
}

template <class T>
void List::display()
{
    if (!head) {return;}
    
    for (Node<T> * curr = head; curr->next != 0; curr = curr->next)
    {
        std::cout << curr->data << " ";
    }
}

template <class T>
void List::elementSwap(int pos)
{
    Node<T> * posit_plus_one = head;
    Node<T> * posit = 0;
    
    for (int i =0; i < pos; i++)
    {
        if(posit_plus_one->next ==0)
        {
            break;
        }
        
        posit = posit_plus_one;
        posit_plus_one = posit_plus_one->next;
    }
    
}