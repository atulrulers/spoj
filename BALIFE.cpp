// https://www.spoj.com/problems/BALIFE/
// Greedy Approach

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n && n != -1){
        int a[n];
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum = sum + a[i];
        }
        if(sum%n){
            cout<<"-1"<<endl;
            continue;
        }

        int avg = sum / n ;

        int cs[n] = {0}; // cumulative sum
        sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + a[i];
            cs[i] = sum ;
        }

        int minSteps = INT_MIN;  // maximum of  avg and cumulative sum at each point of break

        for(int i=0;i<n;i++){
            int moves = avg * (i+1) ;
            moves = abs(cs[i] - moves);
            minSteps = max(minSteps, moves);
        }
        cout<<minSteps<<endl;
    }

    return 0;
}
