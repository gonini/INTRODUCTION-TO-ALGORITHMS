//
//  main.cpp
//  BASIC-QUEUE
//
//  Created by GangGongUi on 2016. 8. 8..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;


class basicQueue
{
    
private:
    int arr[100];
    int head = 0, tail = 0;
    const int size = 100;
    
public:
    
    basicQueue()
    {
        memset(arr, 0, sizeof(arr));
    }
    
    void enqueue(int x)
    {
        if(tail == size)
        {
            perror("queue is full");
            return;
        }
        arr[tail++] = x;
    }
    
    int dequeue()
    {
        if(head == tail)
        {
            perror("queue is empty -1");
            return -1;
        }
        return arr[head++];
    }
};


int main()
{
    // insert code here...
    
    basicQueue queue;
    
    for(int i = 1; i < 50; i++)
        queue.enqueue(i);
    
    for(int i = 1; i < 50; i++)
        cout << queue.dequeue() << " ";
    
    return 0;
}
