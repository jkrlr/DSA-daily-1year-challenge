// Linked List Node

template <typename T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

// Creating a Node in Main
Node<int> *n = new Node<int>(10);