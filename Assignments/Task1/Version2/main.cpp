#include <iostream>
#include "PriorityQueue.h"

int main()
{
    PriorityQueue firstQ;

    firstQ.display();
    firstQ.push(5);
    firstQ.push(3);
    firstQ.push(5);
    firstQ.push(3);
    firstQ.display();
    firstQ.removeValue(3);
    firstQ.display();
    
    return 0;
}