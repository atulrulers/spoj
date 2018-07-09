// https://www.spoj.com/problems/AGGRCOW/
/*
    Binary Search on answer i.e, take maximum possible value as end point and minimum possible value
    as starting point and apply binary search for that range.
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool canPlace(int cows,int stalls[],int n,int mid){
    int c = 1;
    int pos = stalls[0];  // first cow

    for(int i=1;i<n;i++){
        if(abs(stalls[i]-pos) >= mid){
            c++;
            pos = stalls[i];
            if( c == cows)
                return true;
        }
    }

    return false;
}

int minDist(int stalls[],int cows,int n){
    int s=0, e = stalls[n-1] - stalls[0];
    int mid, ans = -1;

    while(s<=e){
        mid = (s+e)/2;
        if(canPlace(cows,stalls,n,mid)){  // if it is possible then look for larger distance as we have to maximize it
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }

    return ans;
}

int main(){
   int t;
   cin>>t;
   while(t--){
         int n,c;
        cin>>n>>c;
        int stalls[n];

        for(int i=0;i<n;i++)
            cin>>stalls[i];

        sort(stalls,stalls+n);

        cout<<minDist(stalls,c,n)<<endl;
   }

    return 0;
}
