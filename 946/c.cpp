#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1,0);
        rep(i,1,n)cin>>a[i];
        vector<vector<int>>vec(n-3+1,vector<int>(3,0));
        int j=0;
        rep(i,3,n)
        {
            vec[j][0]=a[i-2];
            vec[j][1]=a[i-1];
            vec[j][2]=a[i];
            j++;
        }
        map<pair<int,int>,multiset<int>>mp;
        int ans=0;
        rep(i,0,2)
        {
            mp.clear();
            for(auto& u : vec)
            {
                mp[{u[i%3],u[(i+1)%3]}].insert(u[(i+2)%3]);
            } 
            
            int tot=0;
            for(auto& v : mp)
            {
                map<int,int>cnt;
                int cur=0;
                tot=sz(v.S);
                for(auto& uu : v.S)
                {
                    cnt[uu]++;
                    
                }
                for(auto& u : cnt)
                {
                    cur+=(u.S)*(tot-u.S);
                }
                ans+=cur;
            }

        }
        cout<<ans/2<<endl;

    }
    return 0;
}


