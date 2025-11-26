#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n;
vector<int>a;
int getmex(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  int N=sz(arr);
  int mex = 0;
  for (int idx = 0; idx < N; idx++)
  {
    if (arr[idx] == mex)
    {
      mex += 1;
    }
  }
  return mex;
}
pair<int,vector<pair<int,int>>> get(int cur)
{
    cout<<"cur="<<cur<<endl;
    if(cur==n)return {0,vector<pair<int,int>>()};
    int best=0;
    int sum=0;
    vector<int>temp;
    vector<pair<int,int>>pf;
    for(int i=cur;i<n;i++)
    {
        // for(int j=cur;j<=i;j++)
        {
            sum+=a[i];
            temp.push_back(a[i]);
            int mex=getmex(temp);
            pair<int,vector<pair<int,int>>>pp=get(cur+1);
            if(best<mex*(i-cur+1)+pp.first)
            {
                best=mex*(i-cur+1)+pp.first;
                pf=pp.second;
                pf.push_back({cur+1,i+1});
            }
        }
    }
    return {best,pf};
}
signed main()
{
    speed;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    pair<int,vector<pair<int,int>>>p=get(0);
    cout<<p.first<<" "<<sz(p.second)<<endl;
    for(auto& u : p.second)cout<<u.first<<" "<<u.second<<endl;
    return 0;
}


