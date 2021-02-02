//#include "SkipList.h"
#include "DLOrderList.h"
#include <iostream>


int main()
{
    auto orderList = DLOrderList<int>();

    orderList.add(10);
    orderList.add(9);
    orderList.printList();
    
    //std::cout <<orderList.head->val << orderList.head->next->val;
}