#include "PriorityQueue.h"

PriorityQueue::PriorityQueue():arrSize(0),capacity(0),arr(nullptr)
{

}
PriorityQueue::PriorityQueue(int arrSize, int *arr):
        arrSize(arrSize),
        capacity(arrSize),
        arr(new int[arrSize])
{
    for(int i = 0;i<arrSize;i++)
    {
        this->arr[i]= arr[i];
    }
}
PriorityQueue::~PriorityQueue()
{
    this->dispose();
}
int PriorityQueue::size()
{
    return this->arrSize;
}
void PriorityQueue::push(int val)
{
    if(this->arrSize>=this->capacity)
    {
        this->realloc(arrSize+1);

    }
    int i{};
    for (i = this->arrSize;; i--)
			{
                 if(arr[i-1]<val)break;
				this->arr[i] = this->arr[i - 1];
               
			}
            this->arr[i] = val;

			this->arrSize++;
}
bool PriorityQueue::remove()
{
    if(arrSize==0)
        return false;

    arrSize--;
    realloc(this->arrSize);
    return true;
}
int PriorityQueue::find(int value)
{
    
       for(int i=0;i<this->arrSize;i++)
       {
        if(arr[i]==value)
            return i;
       }
       return -1;
}
bool PriorityQueue::removeValue(int value)
{
    bool flag = false;
    if(find(value)==-1)flag=true;

    int index= find(value);
    while(index!=-1)
    {
        removeAt(index);
        index= find(value);
    }
       return flag;
}
bool PriorityQueue::removeAt(int index)
{
    if(index>=arrSize || index<0)
        return false;
         
        int* newArr = new int[this->arrSize-1]();
		
        int counter=0;
		for (int i = 0; i < this->arrSize; i++)
		{
            if(i==index)
            {
                continue;
            }
			newArr[counter] = this->arr[i];
            counter++;
		}
		this->dispose();
		this->arr = newArr;  
        arrSize--; 
        return false;
}
void PriorityQueue::display()
{
    
      for(int i=0;i<this->arrSize;i++)
      {
        std::cout<<this->arr[i]<<" "<<std::flush;
      }
      std::cout<<std::endl;
}
PriorityQueue PriorityQueue::copy()
{
    return PriorityQueue(this->arrSize,this->arr);
}
void PriorityQueue::realloc(int newCapacity)
{
    int* newArr = new int[newCapacity]();
		this->capacity = newCapacity;
		this->arrSize = this->capacity > this->arrSize ? this->arrSize : this->capacity;
		for (int i = 0; i < this->arrSize; i++)
		{
			newArr[i] = this->arr[i];
		}
		this->dispose();
		this->arr = newArr;
}
void PriorityQueue::dispose()
{
    delete []this->arr;
}
