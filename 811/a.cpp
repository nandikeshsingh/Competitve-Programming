#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
bool check(int a,int b,int x,int y)
{
    if(a<x)return 1;
    else if(a==x)
    {
        if(b<=y)return 1;
        else return 0;
    }
    else return 0;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,H,M;
        cin>>n>>H>>M;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            int h,m;
            cin>>h>>m;
            vec.push_back({h,m}); 
        }
        sort(all(vec));
        // cout<<"Printing vec"<<endl;
        // for(auto& u : vec)cout<<u.first<<" "<<u.second<<endl;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(check(H,M,vec[i].first,vec[i].second))
            {
                ans=i;
                break;
            }
            
        }
        // cout<<"index="<<ans<<endl;
        if(ans==-1)ans=0;
        int tot=vec[ans].first*60;
        tot+=vec[ans].second;
        int cur=H*60;
        cur+=M;
        int rim=-1;
        if(tot>=cur)
         rim=tot-cur;
        else 
        {
            rim=H*60;
            rim+=M;
            int up=24*60;
            up-=rim;
            rim=0;
            rim=up+tot;
        }
        // cout<<"Printing ans"<<endl;
        cout<<rim/60<<" "<<rim%60<<endl;
    }
    return 0;
}