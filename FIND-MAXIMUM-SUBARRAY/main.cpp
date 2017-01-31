//
//  main.cpp
//  FIND-MAXIMUM-SUBARRAY
//
//  Created by GangGongUi on 2016. 7. 29..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class maxRange
{
public:
    int maxLeft;
    int maxRight;
    int sum;
    
    maxRange(int maxLeft, int maxRight, int sum)
    {
        this->maxLeft = maxLeft;
        this->maxRight = maxRight;
        this->sum = sum;
    }
};

maxRange findCrossingSubarray(const vector<int>& A, int left, int mid, int right);
maxRange findMaximumSubarray(const vector<int>& A, int left, int right);

maxRange findCrossingSubarray(const vector<int>& A, int left, int mid, int right)
{

    int leftSum = numeric_limits<int>::min();
    int maxLeft = 0;
    int sum = 0;
    
    for(int i = mid; i >= left; i--)
    {
        sum += A[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightsum = numeric_limits<int>::min();
    int maxRight = 0;
    sum = 0;

    for(int i = mid + 1; i <= right; i++)
    {
        sum += A[i];
        if(sum > rightsum)
        {
            rightsum = sum;
            maxRight = i;
        }
    }
    
    return maxRange(maxLeft, maxRight, leftSum + rightsum);
}

maxRange findMaximumSubarray(const vector<int>& A, int left, int right)
{
    if(left == right)
        return maxRange(left, right, A[left]);
    else
    {
        int mid = (left + right) / 2;
        
        maxRange leftRangeMax = findMaximumSubarray(A, left, mid);
        maxRange rightRangeMax = findMaximumSubarray(A, mid + 1, right);
        maxRange crossRangeMax = findCrossingSubarray(A, left, mid, right);
        
        if(leftRangeMax.sum >= rightRangeMax.sum && leftRangeMax.sum >= crossRangeMax.sum)
            return leftRangeMax;
        else if(rightRangeMax.sum >= leftRangeMax.sum && rightRangeMax.sum >= crossRangeMax.sum)
            return rightRangeMax;
        else
            return crossRangeMax;
    }
}

int main()
{
    // insert code here...
    int arr[] = { 9, -7, 3, 5, -2, 4 };
    vector<int> A;
    for(auto i : arr)
        A.push_back(i);
    
    maxRange m = findMaximumSubarray(A, 0, A.size()-1);
    
    cout << m.sum << endl;
    
    return 0;
}
