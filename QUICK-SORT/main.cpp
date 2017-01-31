//
//  main.cpp
//  QUICK-SORT
//
//  Created by GangGongUi on 2016. 8. 4..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void quickSort(vector<int>& A, int p, int r);
int partiton(vector<int>& A, int p, int r);

void quickSort(vector<int>& A, int p, int r)
{
    if(p < r)
    {
        int q = partiton(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int partiton(vector<int>& A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int cnt = 0;
    
    for(int j = p; j < r; j++)
        if( A[j] <= x )
        {
            if( A[j] == x) cnt++;
            i = i + 1;
            swap(A[j], A[i]);
        }
    
    if(A[i + 1] == A[r]) cnt++;
    
    swap(A[i + 1], A[r]);
    
    if(cnt == r - p + 1)
        return (p + r) / 2;
    return i + 1;
}

int main()
{
    // insert code here...
    vector<int> A = { 4, 4, 4, 4, 4, 1, 4, 3, 6 ,7 ,9, 2, 5 };
    
    quickSort(A, 0, A.size() - 1);
    
    for(auto e : A)
        cout << e << " ";
    
    return 0;
}
