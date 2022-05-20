#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minJumps(int arr[], int n){
        int count=1;
        int jump=arr[0], maxJump=arr[0];
        if(jump==0) {
            if(n==1)
                return 0;
            return -1;
        }
        for(int i=1;i<n-1;i++) {
            maxJump--;
            maxJump=max(maxJump, arr[i]);
            jump--;
            if(jump==0) {
                jump=maxJump;
                count++;
            }
            if(jump<=0)
                return -1;
        }
        return count;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}