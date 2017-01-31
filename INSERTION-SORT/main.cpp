//
//  main.cpp
//  INSERTION-SORT
//
//  Created by GangGongUi on 2016. 7. 28..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A)
{
    for(int j = 1; j < A.size(); j++)
    {
        int key = A[j];
        int i = j - 1;
        
        while( i >= 0 && A[i] > key )
        {
            A[i + 1] = A[i];
            i--;
        }
        
        A[i+1] = key;
    }
}

int main(int argc, const char * argv[])
{
    // insert code here...
    vector<int> A;
    int arr[] = {41, 31, 59, 26, 41, 58};
    
    for(auto i : arr)
        A.push_back(i);
    
    insertionSort(A);
    
    for(auto value : A)
        cout << value << " ";
    
    return 0;
}
