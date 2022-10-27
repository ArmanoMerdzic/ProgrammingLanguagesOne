#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node():next(nullptr),value(0)
    {

    }
    Node(int value):next(nullptr),value(value)
    {

    }
};
class PriorityQueue
{
    private:
        Node *head;
        int arrSize;

    public:
    
    PriorityQueue();
    PriorityQueue(int arrSize, int *arr);
    ~PriorityQueue();

    PriorityQueue copy();

    int size();

    void push(int value);
    void display();
    void removeValue(int value);

    bool remove();

    private:

    Node* removeHelper(Node *curr, int value);
    void dispose();
      
        

};