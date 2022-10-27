#include <iostream>
#include "PriorityQueue.h"

int main()
{
    PriorityQueue firstQ;

    firstQ.push(5);
    firstQ.push(3);
    firstQ.push(4);
    firstQ.push(6);
     firstQ.push(7);
      firstQ.push(8);
       firstQ.push(12);
        firstQ.push(12);
         firstQ.push(12);
    firstQ.display();
    firstQ.remove();
    firstQ.removeValue(12);
    firstQ.display();
    
    return 0;
}