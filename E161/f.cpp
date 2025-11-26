#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>a;
int n,x;
int get(int s,int e)
{
    if(s==e)return 0;
    int ans=0;
    set<int>l,r;
    vector<int>vl(101,0),vr(101,0);
    for(int i=s+1;i<=e;i++)
    {
        for(int j=s;j<i;j++)l.insert(a[j]);
        for(int j=i;j<=e;j++)r.insert(a[j]);
        for(int lv=1;lv<=x;lv++)
        {
            if(l.count(lv))continue;
            for(int rv=1;rv<=x;rv++)
            {
                 if(r.count(rv))continue;
                vl[lv]=get(s,i-1);
                vr[rv]=get(i,e);
            }
        }
    }
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        a.clear();
        a.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<get(0,n-1)<<endl;
    }
    return 0;
}


