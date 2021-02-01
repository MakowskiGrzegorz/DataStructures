#ifndef SKIP_LIST
#define SKIP_LIST
#include <memory>

template <typename T>
class Node
{
  public:
    T value;
    std::unique_ptr<Node> next;
};

template <typename T>
class SkipList
{
  public:
    std::unique_ptr<Node<T>> head;
    SkipList();

    void add(T&& value);
    bool isEmpty();
};

#include "SkipList.tpp"
#endif