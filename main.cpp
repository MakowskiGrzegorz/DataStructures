#include "SkipList.h"
#include <iostream>


int main()
{
    auto list = SkipList<int>();

    int val = 20;
    list.add(5);
    list.add(10);
    list.add(7);

    auto lambda = [&](SkipList<int> list)
    {
        Node<int>* tmp;
        tmp = list.head.get();
        while(tmp != nullptr)
        {
            std::cout << tmp->value <<"\n";
            tmp = tmp->next.get();
        }
    };
    
    //lambda(std::move(list));
}