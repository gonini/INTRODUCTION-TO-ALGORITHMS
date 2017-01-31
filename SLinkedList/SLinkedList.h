//
//  SLinkedList.h
//  SLinkedList
//
//  Created by GangGongUi on 2016. 8. 21..
//  Copyright © 2016년 goni. All rights reserved.
//

#ifndef SLinkedList_h
#define SLinkedList_h

template<typename E>
class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();
private:
    template<typename T>
    class SNode
    {
    private:
        T elem;
        SNode<T> * next;
        friend class SLinkedList<T>;
    };
    
    SNode<E> * head;
};

template<typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {}

template<typename E>
SLinkedList<E>::~SLinkedList() { while(!empty()) removeFront(); }

template<typename E>
bool SLinkedList<E>::empty() const { return head == NULL; }

template<typename E>
const E& SLinkedList<E>::front() const { return head->elem; }

template<typename E>
void SLinkedList<E>::addFront(const E &e)
{
    SNode<E> *v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template<typename E>
void SLinkedList<E>::removeFront()
{
    SNode<E> *old = new SNode<E>;
    old = head;
    head = head->next;
    delete old;
}

#endif /* SLinkedList_h */
