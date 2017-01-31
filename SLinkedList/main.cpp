//
//  main.cpp
//  SLinkedList
//
//  Created by GangGongUi on 2016. 8. 21..
//  Copyright © 2016년 goni. All rights reserved.
//

#include <iostream>
#include "SLinkedList.h"

using namespace std;

int main()
{
    // insert code here...
    SLinkedList<int> list;
    
    list.addFront(3);
    list.addFront(5);
    list.addFront(1);
    cout << list.front() << endl;
    list.removeFront();
    cout << list.front() << endl;
    
    return 0;
}
