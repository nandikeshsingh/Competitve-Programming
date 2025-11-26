#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,k;
vector<int>a;
vector<pair<int,int>>vec;
pair<int,int>dp[205][205];
pair<int,int>get(int i,int k)
{
    if(k==0 && i<=n) return {0,0};
    if(i>=n && k>=1)return {-1e18,-1e18};
    if(dp[i][k].first!=-1 && dp[i][k].second!=-1)return dp[i][k];
    pair<int,int>p1,p0,ret;
    p1={0,0};p0={0,0};
    // if(i+1<n)
    {
        p1=get(i+1,k-1);
        p0=get(i+1,k);
        if(min(p1.first+vec[i].first,p1.second+vec[i].second)>min(p0.first,p0.second))
        {
            ret.first=p1.first+vec[i].first;
            ret.second=p1.second+vec[i].second;
        }
        else if(min(p1.first+vec[i].first,p1.second+vec[i].second)<min(p0.first,p0.second))
        {
            ret=p0;
        }
        else 
        {
            if(p1.first+p1.second+vec[i].first+vec[i].second>p0.first+p0.second)
            {
                        ret.first=p1.first+vec[i].first;
                ret.second=p1.second+vec[i].second;
            }
            else 
            {
                ret=p0;        
            }
        }
    }

    return dp[i][k]=ret;
}
signed main()
{
    speed;
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int c5=0;
        while(a[i]%5==0)c5++,a[i]/=5;
        int c2=0;
        while(a[i]%2==0)c2++,a[i]/=2;
        vec.push_back({c5,c2});
    }
    cout<<"Printing vec"<<endl;
    for(auto& u : vec)cout<<u.first<<" "<<u.second<<endl;
    for(int i=0;i<=204;i++)
    {
        for(int j=0;j<=204;j++)
        dp[i][j]={-1,-1};
    }
    pair<int,int>ans=get(0,k);
    cout<<min(ans.first,ans.second)<<endl;
    return 0;
}


