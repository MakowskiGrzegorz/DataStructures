#include "SkipList.h"
#include <iostream>
template <typename T>
SkipList<T>::SkipList()
{
    this->head = nullptr;
}


template <typename T>
void SkipList<T>::add(T&& value)
{
    if(this->head == nullptr)
    {
        this->head = std::make_unique<Node<T>>();

        this->head->value = value;
        this->head->next = nullptr;
    }
    else
    {
        Node<T>* tmp = this->head.get();
        Node<T>* prev = nullptr;
        while(tmp->value < value && tmp->next != nullptr)
        {
            prev = tmp;
            tmp = tmp->next.get();
        }
        if(tmp->next == nullptr)
        {
            tmp->next = std::make_unique<Node<T>>();
            tmp->next->value = value;
            tmp->next->next = nullptr;
        }
        else
        {
            std::cout <<prev<<"\n";
            std::cout <<tmp<<"\n";
        }
        
    }
}