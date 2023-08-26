#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool sortBy(pair<int,int> p1,pair<int,int> p2){
  if(float(p1.first)/p1.second > float(p2.first)/p2.second ){
    return true;
  }
  return false;
}

class Knapsack
{
  public:
  Knapsack(){
  }

  int findMaxProfit(int C,vector<pair<int,int>> &v){
    int i=0;
    int ans=0;
    int U=C;
    for(;i<v.size();i++){
      cout<<v[i].first<<" "<<v[i].second<<" "<<endl;
      if(v[i].second > U){
        break;
      }
      ans+=v[i].first;
      U=U-v[i].second;
    }
    if(i<v.size()){
      ans+=(v[i].first)*(float(U)/v[i].second);
    }

    return ans;
  }

};

int main() {
    vector<int> p{30,40,45,77,90};
    vector<int> w{5,10,15,22,25};
    int capacity=60;

    vector<pair<int,int>> v;

    for(int i=0;i<p.size();i++){
        v.emplace_back(make_pair(p[i],w[i]));
      }
    sort(v.begin(),v.end(),sortBy);

    Knapsack k1;
    cout<<k1.findMaxProfit(capacity,v)<<endl;
  
}
