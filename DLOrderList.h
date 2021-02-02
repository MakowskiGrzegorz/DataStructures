#ifndef DL_ORDER_LIST
#define DL_ORDER_LIST
#include <memory>
#include <iostream>

template <typename T>
class DLOrderNode
{
    public:
        DLOrderNode():val(0), next(nullptr), prev(nullptr)
        {
            std::cout <<"DLOrderNode Default constructor\n";
        }
        DLOrderNode(const DLOrderNode& other):val(other.val), next(std::move(other.next)), prev(other.prev)
        {
            std::cout <<"DLOrderNode Copy constructor\n";
        }
        DLOrderNode(DLOrderNode&& other):val(other.val), next(std::move(other.next)), prev(other.prev)
        {
            std::cout <<"DLOrderNode Move constructor\n";
        }
        DLOrderNode& operator=(DLOrderNode& other)
        {
            std::cout << "DLOrderNode assignment operator\n";
            return *this = DLOrderNode(other);
        }
        DLOrderNode& operator=(DLOrderNode&& other)
        {
            std::cout << "DLOrderNode move operator\n";
            std::swap(this->val,other.val);
            std::swap(this->next, other.next);
            std::swap(this->prev, other->prev);
            return *this;
        }
        ~DLOrderNode(){
            std::cout << "Destructor\n";
        }
        T val;
        std::unique_ptr<DLOrderNode> next;
        DLOrderNode* prev;
};

template <typename T>
class DLOrderList
{
    public:
        std::unique_ptr<DLOrderNode<T>> head;
        //DLOrderNode<T>* tail;
        DLOrderList(): head(nullptr)/*, tail(nullptr)*/{}
        void add(const T& val);
        void printList(void) const noexcept;
};

template <typename T>
void DLOrderList<T>::add(const T& val)
{
    if(nullptr == this->head)// if list empty
    {
        this->head = std::make_unique<DLOrderNode<T>>();
        this->head->val = val;
        this->head->next = nullptr;
        this->head->prev = nullptr;
    }
    else if(nullptr == this->head->next)// if one element
    {
        if(val > this->head->val) // if new element bigger
        {
            this->head->next = std::make_unique<DLOrderNode<T>>();
            this->head->next->val = val;
            this->head->next->prev = head.get();
            this->head->next->next = nullptr;    
        }
        else
        {
            auto newNode = std::make_unique<DLOrderNode<T>>();
            newNode->val = val;
            newNode->prev = nullptr;
    
            this->head->prev = newNode.get();

            newNode->next = std::move(head);
            head = std::move(newNode);
        }
        
    }
    else// if more elements
    {
        
    }
    
}

template <typename T>
void DLOrderList<T>::printList(void) const noexcept
{
    auto tmp = this->head.get();
    while(tmp != nullptr)
    {
        std::cout << tmp->val << " ";
        tmp = tmp->next.get();
    }
    std::cout <<"\n";
}
#endif

