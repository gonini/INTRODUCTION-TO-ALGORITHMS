//
//  main.cpp
//  BASIC-STACK
//
//  Created by GangGongUi on 2016. 8. 8..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class basicStack
{
private:
    int arr[100];
    int top = 0;
    
public:
    basicStack()
    {
        memset(arr, 0, sizeof(arr));
    }
    
    bool empty()
    {
        if(top <= 0)
            return true;
        else return false;
    }
    
    void push(int x)
    {
        arr[++top] = x;
    }
    
    int pop()
    {
        if(empty())
        {
            perror("stack empty return -1");
            return -1;
        }
        else return arr[top--];
    }
};


int main()
{
    // insert code here...
    
    basicStack stack;
    
    for(int i = 1; i < 50; i++)
        stack.push(i);
    for(int i = 1; i < 50; i++)
        cout << stack.pop() << " ";
    

    return 0;
}
