#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n) {
        long long int temp=0;
        long long int max=INT_MIN;
        for(int i=0;i<n;i++) {
            temp+=arr[i];
            if(temp>max)
                max=temp;
            if(temp<0)
                temp=0;
        }
        return max;
    }
};

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}