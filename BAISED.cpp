// https://www.spoj.com/problems/BAISED/ 
/*
    Greedy approach will work in O(n) time.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll minBadness(vector < ll > v){
    ll s = v.size();

    sort(v.begin(),v.end()); // sort the rank value

    ll ans = 0;
    for(ll i=0;i<s;i++){ // start assigning rank to each one
        ans = ans + abs(v[i] - i - 1); // calculate absolute difference between the possible rank and desired rank
    }

    return ans;
}

int main(){
    ll t;
    cin>>t; // number of test cases

    while(t--){
        vector< ll > v;
        ll n ;
        cin >> n ;
        string s;
        ll temp;
        for(ll i=0;i<n;i++){
            cin>>s>>temp;
            v.push_back(temp);
        }
        cout<<minBadness(v)<<endl;
    }

    return 0;

}
