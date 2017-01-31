#include <vector>
#include <iostream>

using namespace std;
void marge(vector<int>& A, int left, int mid, int right);
void margeSort(vector<int>& A, int left, int right);

void marge(vector<int>& A, int left, int mid, int right)
{
    int lSize = mid - left + 1;
    int rSize = right - mid;

    int L[lSize + 1];
    int R[rSize + 1];

    for(int i = 0; i < lSize; i++)
        L[i] = A[left + i];
    for(int i = 0; i < rSize; i++)
        R[i] = A[mid + i + 1];
    
    L[lSize] = numeric_limits<int>::max();
    R[rSize] = numeric_limits<int>::max();
    
    int k = 0;
    int j = 0;

    for(int i = left; i <= right; i++)
    {
        if(L[k] <= R[j])
            A[i] = L[k++];
        else if(L[k] > R[j])
            A[i] = R[j++];
    }
}

void margeSort(vector<int>& A, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        margeSort(A, left, mid);
        margeSort(A, mid + 1, right);
        marge(A, left, mid, right);
    }
}

int main()
{
    int arr[] = { 3, 4, 5, 2, 4, 6, 13, 24, 8, 4 };
    int size = sizeof(arr) / sizeof(int);
    vector<int> A;
    
    for(int i = 0; i < size; i++)
        A.push_back(arr[i]);

    margeSort(A, 0, A.size()-1);
    
    for(auto v : A)
        cout << v << " ";
    
    return 0;
}
