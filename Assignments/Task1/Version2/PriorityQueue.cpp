#include "PriorityQueue.h"

PriorityQueue::PriorityQueue():arrSize(0),head(nullptr)
{

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
   Node *add = new Node(val);
   if(head == nullptr || head->value <=add->value )
   {
    add->next=head;
    head=add;
    
   }
   else{
    Node *current = head;
    while(current->next!=nullptr && current->next->value>add->value)
    {
        current = current->next;
    }
    add->next = current->next;
    current->next = add;
   }
 arrSize++;
}
bool PriorityQueue::remove()
{
    if(arrSize==0)
        return false;
    Node *tmp = head;
    head=head->next;
    delete tmp;

    arrSize--;

    return true;
       
}

void PriorityQueue::removeValue(int value)
{
   
    removeHelper(this->head,value);
}
Node* PriorityQueue::removeHelper(Node *head, int value)
{
    if(head==nullptr)
        return nullptr;
        head->next=removeHelper(head->next,value);
        return (head->value==value)? head->next:head;
   
}
void PriorityQueue::display()
{
    
     Node *tmp = head;
     while(tmp!=nullptr)
     {
        std::cout<<tmp->value<<" "<<std::flush;
        tmp = tmp->next;
     }
     std::cout<<std::endl;
}

void PriorityQueue::dispose()
{
    Node *tmp = head;
    while(head)
    {
        head=head->next;
        delete tmp;
        tmp = head;
    }
   
}
