// https://www.spoj.com/problems/BUSYMAN/
/*
    Simple activity selection problem. Apply greedy approach on end time .
*/

#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> a,pair<int,int> b){
    return a.second < b.second ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int s,e;  // start and end time
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }

        sort(v.begin(),v.end(),comparator);

        int totalActivity = 1;
        int finishTime = v[0].second;

        for(int i=1;i<n;i++){
            if(v[i].first >= finishTime){
                finishTime = v[i].second;
                totalActivity = totalActivity + 1;
            }
        }

        cout<<totalActivity<<endl;
    }

    return 0;
}
