// https://www.spoj.com/problems/DEFKIN/
/*
    Sort x co-ordinate and y co-ordinate of tower and then find delta(x) and delta(y).
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        
        vector<int> x, y;  // vector of x and y coordinates
        x.push_back(0);
        y.push_back(0);
        
        for(int i=0;i<n;i++){
            int xcord, ycord;
            cin>>xcord>>ycord;
            x.push_back(xcord);
            y.push_back(ycord);
        }
        
        x.push_back(w+1);
        y.push_back(h+1);
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        int dx = INT_MIN, dy = INT_MIN ; // maximum delta x and delta y
        for(int i=1;i<=n+1;i++){
            dx = max(dx , x[i] - x[i-1]);
            dy = max(dy , y[i] - y[i-1]);
        }
        cout<<(dx-1)*(dy-1)<<endl;
    }    
    return 0;
}
