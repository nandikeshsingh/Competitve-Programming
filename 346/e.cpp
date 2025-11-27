#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int h,w,m;
    cin>>h>>w>>m;
    set<int>row,col;
    map<int,int>mp;
    vector<int>t(m),a(m),x(m);
    for(int i=0;i<m;i++)cin>>t[i]>>a[i]>>x[i];
    for(int i=m-1;i>=0;i--)
    {
        if(t[i]==1)
        {
            int r=a[i];
            int c=x[i];
            if(row.count(r))continue;
            mp[c]+=(w-sz(col));
            row.insert(r);
        }
        else 
        {
            int cl=a[i];
            int c=x[i];
            if(col.count(cl))continue;
            mp[c]+=(h-sz(row));
            col.insert(cl);
        }
    }
    int tot=0;
    for(auto& u : mp)tot+=u.second;
    mp[0]+=(h*w-tot);
    int cnt=0;
    for(auto& u : mp)
    {
        if(u.second>0)cnt++;
    }
    cout<<cnt<<endl;
    for(auto & u : mp)
    {
        if(u.second>0)
        cout<<u.first<<" "<<u.second<<endl;
    }
    return 0;
}


