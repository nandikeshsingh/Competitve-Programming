#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,q;
vector<int>x,bit;
void update(int idx,int val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int query(int idx)
{
    int ret=0;
    while(idx)
    {
        ret+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ret;
}
signed main()
{
    speed;
    cin>>n>>q;
    x.resize(n+1);
    for(int i=1;i<=n;i++)cin>>x[i];
    bit.resize(n+1);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int a,b,u;
            cin>>a>>b>>u;
            update(a,u);
            update(b+1,-u);
        }
        else 
        {
            int k;
            cin>>k;
            cout<<x[k]+query(k)<<endl;
        }
    }
    return 0;
}


