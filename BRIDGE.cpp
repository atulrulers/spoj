// https://www.spoj.com/problems/BRIDGE/
// Dynamic Programming
// Longest increasing subsequence

#include <bits/stdc++.h>

using namespace std;

struct coords{
    int a;
    int b;
};

bool comp(coords l, coords r){
    if ( l.b == r.b ){
        return l.a < r.a ;
    }
    return l.b < r.b;
}

int maxBridge(coords *x,int n){
    int dp[n];

    // base case
    for(int i=0;i<n;i++)
        dp[i] = 1;

    int ans = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){  // if j th element can be included or not
            if( x[j].a <= x[i].a ){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i],ans);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;  // number of bridges
        cin>>n;
        coords x[n];
        for(int i=0;i<n;i++)
            cin>>x[i].a;
        for(int i=0;i<n;i++)
            cin>>x[i].b;

        sort(x,x+n,comp);

        cout<<maxBridge(x,n)<<endl;  // find longest increasing subsequence from first points
    }
    return 0;
}
