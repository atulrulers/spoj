// https://www.spoj.com/problems/EKO/
// #Binary-Search
// Problem Name - EKO - Eko

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool isPossible(ll *a,ll n,ll m,ll mid){
    ll temp = 0 ;
    for(ll i=0;i<n;i++){
        if(a[i] > mid){
            temp = temp + a[i] - mid;
            if(temp >= m)
                return true;
        }
    }
    return false;
}

ll maxHeight(ll *a, ll n, ll m){
    ll s=0, e = LONG_MAX, ans = 0;
    while(s<=e){
        ll mid = (s+e)/2;
        if(isPossible(a,n,m,mid)){
            ans =  mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];

    cout<<maxHeight(a,n,m)<<endl;

    return 0;
}
