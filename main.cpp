//#include "SkipList.h"
#include "DLOrderList.h"
#include <iostream>


int main()
{
    uint8_t numbers[] = {5,33,21,19,65,43,23,88,75,43,55,67,225,12,31,55,43,56,75,12,32,43};
    auto orderList = DLOrderList<int>();
    for (auto n : numbers)
    {
        orderList.add(n);
        orderList.printList();

    }
    
    //std::cout <<orderList.head->val << orderList.head->next->val;
}