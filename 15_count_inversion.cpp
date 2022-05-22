#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int mergesort1(long long arr[],int l,int h) {
       long long temp[h];
       return mergesort(arr,temp,l,h);
    }
    long long merge(long long arr[],long long temp[],int l,int m,int h) {
       long long invcount=0;
       int i=l;
       int j=m;
       int k=l;
       while((i<=m-1) && (j<=h)) {
           if(arr[i]<=arr[j])
           temp[k++]=arr[i++];
           else {
           temp[k++]=arr[j++];
           invcount+=(m-i);
           }
       }
       while(i<=m-1)
        temp[k++]=arr[i++];
       while(j<=h)
        temp[k++]=arr[j++];
       for(i=l;i<=h;i++)
        arr[i]=temp[i];
       return invcount;
    }
    long long mergesort(long long arr[],long long temp[],int l,int h) {
        long long  invcount=0;
        if(l<h) {
            int m=(l+h)/2;
            invcount+=mergesort(arr,temp,l,m);
            invcount+=mergesort(arr,temp,m+1,h);
            invcount+=merge(arr,temp,l,m+1,h);
        }
            return invcount;
    }
    long long int inversionCount(long long arr[], long long N) {
        return mergesort1(arr,0,N-1);
    }
};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}