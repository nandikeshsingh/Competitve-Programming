#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int get(int x)
{
    int ret=0;
    while((x%10)==0)
    {
        x/=10;
        ret++;
    }
    return ret;
}
int digit(int x)
{
    int ret=0;
    while(x)
    {
        x/=10;
        ret++;
    }
    return ret;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>a;
        int tot=0;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            tot+=digit(x);
            a.push_back({get(x),x});
        }
        sort(all(a));
        reverse(all(a));
        int d=0;
        for(int i=0;i<n;i+=2)
            d+=a[i].first;
        if(tot-d>=m+1)cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
    }
    return 0;
}


