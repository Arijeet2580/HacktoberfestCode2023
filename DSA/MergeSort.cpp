// Merge Sort Algorithm
// input n (no of integers in the array) 
// followed by n integers of the array
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void merge(vector<int>&arr, int const start, int const m, int const end)
{
    int n1 = m-start+1;
    int n2 = end-m;
    int left[n1];
    int right[n2];
    
    for(int j=0;j<n1;j++)
    {
        left[j] = arr[start+j];
    }
    for(int j=0;j<n2;j++)
    {
        right[j] = arr[m+1+j];
    }
    int l = 0, r = 0, ind = start;
    while(l<n1&&r<n2)
    {
        if(left[l]<=right[r])
        {
            arr[ind] = left[l];
            l++;
        }
        else{
            arr[ind] = right[r];
            r++;
        }
        ind++;
    }
    while(l<n1)
    {
        arr[ind] = left[l];
        l++;
        ind++;
    }
    while(r<n2)
    {
        arr[ind] = right[r];
        r++;
        ind++;
    }
}
void split(vector<int>&arr, int const start, int const end)
{
    if(start>=end)
    return ;
    int m = start + (end-start)/2;
    split(arr, start, m);
    split(arr, m+1, end);
    merge(arr, start, m, end);
}
void mergeSort(vector<int>&arr)
{
    int n = arr.size();
    split(arr, 0, n-1);
}
int main() {
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
	    int val;
	    cin>>val;
	    a[i] = val;
	}
	mergeSort(a);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
