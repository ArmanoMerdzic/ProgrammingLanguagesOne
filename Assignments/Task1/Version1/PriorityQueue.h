#include <iostream>
class PriorityQueue
{
    private:
        int capacity;
        int arrSize;
        int *arr;

    public:
    
    PriorityQueue();
    PriorityQueue(int arrSize, int *arr);
    ~PriorityQueue();
    
    PriorityQueue copy();

    int size();
    int find(int value);

    void display();
    void push(int value);

    bool remove();
    bool removeValue(int value);
    
    

    private:

    bool removeAt(int index);
    
    void realloc(int newSize);
    void dispose();
        

};