#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    // cin>>t;
    // while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        vector<int>pre(n,0),suf(n,0);
        for(int i=1;i<n;i++)
        {
            if(vec[i]<vec[i-1])pre[i]=pre[i-1]+vec[i-1]-vec[i];
            else pre[i]=pre[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(vec[i]<vec[i+1])suf[i]=suf[i+1]+vec[i+1]-vec[i];
            else suf[i]=suf[i+1];
        }
        while(m--)
        {
            int s,t;
            cin>>s>>t;
            s--;
            t--;
            if(s<t)cout<<pre[t]-pre[s]<<endl;
            else cout<<suf[t]-suf[s]<<endl;
        }
    }
    return 0;
}