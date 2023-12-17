#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class List {

public:

    Node<T>* head;

    List() :head{ nullptr } {}

    void Add(const T& value)
    {
        Node<T>* nextPtr = new Node<T>(value);
        nextPtr->next = head;
        head = nextPtr;


    }

    void Remove()
    {

        if (head != nullptr)
        {
            Node<T>* nextPtr = head;
            head = head->next;
            delete nextPtr;
        }

    }

    void Clear()
    {
        while (head)Remove();
    }

    Node<T>* Find(const T& value)const
    {
        if (head == nullptr)return nullptr;

        for (Node<T>* nextPtr = head; nextPtr != nullptr; nextPtr = nextPtr->next)
        {
            if (nextPtr->value == value)return nextPtr;
        }
        return nullptr;

    }

    Node<T>* FindPrev(const T& value)const
    {

        if (head == nullptr)return nullptr;

        for (Node<T>* nextPtr = head->next, *prevPtr = head; nextPtr != nullptr;
            nextPtr = nextPtr->next, prevPtr = prevPtr->next)
        {
            if (nextPtr->value == value)return prevPtr;
        }
        return nullptr;

    }

    Node<T>* FindAfter(const T& value)const
    {

        if (head == nullptr)return nullptr;

        for (Node<T>* nextPtr = head, *afterPtr = nextPtr->next; afterPtr != nullptr;
            nextPtr = nextPtr->next, afterPtr = afterPtr->next)
        {
            if (nextPtr->value == value)return afterPtr;
        }
        return nullptr;

    }

    void Insert(int position, const T& value)
    {
        if (head != nullptr)
        {

            position = position <= 0 ? 1 : position;
            Node<T>* newNode = new Node<T>(value);
            Node<T>* prev = nullptr;
            Node<T>* current = head;

            if (position == 1)
            {
                Add(value);
                return;

            }

            for (size_t i{ 1 }; current != nullptr; i++, prev = current, current = current->next)
            {
                if (i == position)
                {
                    newNode->next = current;
                    prev->next = newNode;
                    return;
                }
            }
        }
        else Add(value);


    }

    void AddAfter(const T& value) {

        if (head == nullptr)Add(value);
        else
        {

            Node<T>* nextPtr = new Node<T>(value);
            Node<T>* tempPtr = head;
            Node<T>* temBeforpPtr = nullptr;

            while (tempPtr)
            {
                temBeforpPtr = tempPtr;
                tempPtr = tempPtr->next;
            }

            temBeforpPtr->next = nextPtr;
            nextPtr->next = tempPtr;


        }

    }

    void ChangeValue(int position, const T& value)
    {

        if (head != nullptr)
        {

            position = position <= 0 ? 1 : position;
            Node<T>* tempPtr = head;
            for (size_t i{ 1 }; tempPtr != nullptr; i++, tempPtr = tempPtr->next)
            {
                if (i == position)
                {
                    tempPtr->value = value;
                    return;
                }
            }

        }


    }

    void ChangeValueEach(const T& value)
    {
        if (head != nullptr)
        {

            Node<T>* tempPtr = head;
            while (tempPtr)
            {
                tempPtr->value = value;
                tempPtr = tempPtr->next;
            }

        }
    }

    void PrintAllValue()
    {
        if (head != nullptr)
        {
            Node<T>* nextPtr = head;
            while (nextPtr)
            {
                cout << nextPtr->value << "  |  ";
                nextPtr = nextPtr->next;
            }
            cout << endl;
        }
        else cout << "None" << endl;

    }

    T Print(int position)
    {
        if (head != nullptr)
        {
            position = position <= 0 ? 1 : position;
            Node<T>* tempPtr = head;
            for (size_t i{ 1 }; tempPtr != nullptr; i++, tempPtr = tempPtr->next)
            {
                if (i == position)
                {
                    return tempPtr->value;
                }
            }
            return "None";

        }
        else return "None";
    }
};