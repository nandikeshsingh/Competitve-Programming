#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        map<int,vector<int>>a;
        for(int i=0;i<n;i++)
        {
            int q;cin>>q;
            a[q%y].push_back(q%x);
        }
        int cnt=0;
        for(auto& y : a)
        {
            vector<int>vec=y.second;
            map<int,int>mp;
            for(int i=0;i<sz(vec);i++)
            {
                if(i==0)mp[vec[i]]++;
                else 
                {
                    cnt+=mp[(x-vec[i])%x];
                    mp[vec[i]]++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


