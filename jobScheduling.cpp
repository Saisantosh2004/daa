#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortBy(tuple<int,int,char> p1,tuple<int,int,char> p2){
    if(get<1>(p1) < get<1>(p2)) return false;
    return true;
}

int jobScheduling(vector<int> &deadlines,vector<int> &profits,vector<char> &jobs){
    vector<tuple<int,int,char>> dp;
    
    for(int i=0;i<deadlines.size();i++){
        dp.push_back(make_tuple(deadlines[i],profits[i],jobs[i]));
    }
    
    int n=dp.size();
    sort(dp.begin(),dp.end(),sortBy);

    // for(int i=0;i<dp.size();i++){
    //   cout<<get<0>(dp[i])<<" "<<get<1>(dp[i])<<" "<<get<2>(dp[i])<<" "<<endl;
    // }
    
    int profit=0;
    
    int m=INT_MIN;
    for(int i:deadlines){
        if(i>m) m=i;
    }
    
    vector<char> arr(m+1,'#');
    
    for(int i=0;i<n;i++){
        int j=get<0>(dp[i]);
        while(j>0 && arr[j]!='#'){
            j--;
        }
        
        if(arr[j]=='#' && j>0){
            arr[j]=get<2>(dp[i]);
            profit+=get<1>(dp[i]);
        }
    }
    
    for(int i=1;i<=m;i++) {
        if(arr[i]!='#'){
          cout<<arr[i]<<endl;
        }
    }
    
    return profit;
}

int main() {
    
    vector<char> jobs={'a','b','c','d'};
    vector<int> deadlines={2,2,4,1};
    vector<int> profits={40,30,20,10};
  
    int ans=jobScheduling(deadlines,profits,jobs);
  
    cout<<"The maximum profit is: "<<ans<<endl;
  
}
