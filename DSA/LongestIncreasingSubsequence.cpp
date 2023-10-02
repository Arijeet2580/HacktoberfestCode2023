// Longest Increasing Subsequence using linear Dynamic Programming
// for every integer in array we will compare it with all the previous elements which are smaller than it. 
// Now we will update the length of the longest increasing subsequence for the current element.
// Input length of the array then followed by the elements of the array
// e.g 
// 8
// 10 22 9 33 21 50 41 60
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longIncreasingSub(vector<int>arr, int n)
{
    vector<int>dp(n, 0);
    int ans = INT_MIN;
    dp[0] = 1;
    for(int i=1;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&dp[i]<1+dp[j])
            dp[i] = 1+dp[j];
        }
        ans = max(ans, dp[i]);
    }
    return ans;
    
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
	int ans = longIncreasingSub(a, n);
	cout<<ans<<endl;
	return 0;
}
