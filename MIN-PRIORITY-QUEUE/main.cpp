//
//  main.cpp
//  Min-Priority-Queue
//
//  Created by GangGongUi on 2016. 8. 1..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int getParentIdx(int i);
void heapify(vector<int>& A, int i, int heapSize);
int heapMinimum(const vector<int>& A);
int heapExtractMin(vector<int>& A);
void minHeapInsert(vector<int>& A, int key);
void heapDecreaseKey(vector<int>& A, int i, int key);

int heapMinimum(const vector<int>& A)
{
    if ( !A.size() ) return -1;
    return A[0];
}

int heapExtractMin(vector<int>& A)
{
    if( !A.size() )
    {
        cout << "heap underflow return -1" << endl;
        return -1;
    }
    
    int min = A[0];
    
    // exchange A[0] with A[A.heapsize]
    int temp = A.back();
    A[A.size()-1] = A[0];
    A[0] = temp;
    A.pop_back();
    heapify(A, 0, A.size() - 1);
    
    return min;
}

void heapify(vector<int>& A, int i, int heapSize)
{
    while ( i <= heapSize )
    {
        int min = i;
        int l = (i<<1) + 1;
        int r = (i<<1) + 2;
        
        if( l <= heapSize && A[l] < A[min] )
            min = l;
        
        if( r <= heapSize && A[r] < A[min] )
            min = r;
        
        if( min != i )
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            i = min;
        }
        else break;
    }
}

void minHeapInsert(vector<int>& A, int key)
{
    A.push_back(numeric_limits<int>::max());
    heapDecreaseKey(A, A.size() - 1, key);
}

void heapDecreaseKey(vector<int>& A, int i, int key)
{
    
    if(A[i] < key)
    {
        cout << "new key is smaller than current key" << endl;
        return;
    }
    
    A[i] = key;
    
    while( i > 0 && A[i] < A[getParentIdx(i)] )
    {
        int temp = A[getParentIdx(i)];
        A[getParentIdx(i)] = A[i];
        A[i] = temp;
        i = getParentIdx(i);
    }
}

int getParentIdx(int i)
{
    return (i>>1);
}


int main()
{
    // insert code here...
    vector<int> A;
    
    minHeapInsert(A, 4);
    minHeapInsert(A, 9);
    minHeapInsert(A, 20);
    minHeapInsert(A, 2);
    
    cout << heapMinimum(A) << endl;
    cout << heapExtractMin(A) << endl;
    cout << heapExtractMin(A) << endl;
    cout << heapExtractMin(A) << endl;
    cout << heapExtractMin(A) << endl;
    
    return 0;
}
