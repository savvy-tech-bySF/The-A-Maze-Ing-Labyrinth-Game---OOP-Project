#include "CircularQueue.hpp"
#include <iostream>


void Cqueue::insertCQ(int val) 
{
    if ((Cqueue::front == 0 && Cqueue::rear == n-1) || (Cqueue::front == Cqueue::rear+1)) 
    {
        std::cout<<"Queue Overflow \n";
        return;
    }
    if (Cqueue::front == -1) 
    {
        Cqueue::front = 0;
        Cqueue::rear = 0;
    } 
    else 
    {
        if (Cqueue::rear == n - 1)
        Cqueue::rear = 0;
        else
        Cqueue::rear = Cqueue::rear + 1;
    }
    Cqueue::cqueue[Cqueue::rear] = val ;
}
void Cqueue::deleteCQ() 
{
    if (Cqueue::front == -1) 
    {
        std::cout<<"Queue Underflow\n";
        return ;
    }
    std::cout<<"Element deleted from queue is : "<<Cqueue::cqueue[Cqueue::front]<<std::endl;

    if (Cqueue::front == Cqueue::rear) {
        Cqueue::front = -1;
        Cqueue::rear = -1;
    } else {
        if (Cqueue::front == n - 1)
        Cqueue::front = 0;
        else
        Cqueue::front = Cqueue::front + 1;
    }
}