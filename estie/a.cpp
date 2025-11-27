#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>gp[250100];
vector<int>depth(250100);
void dfs(int n,int p,int h)
{
    depth[n]=h;
    for(auto& c : gp[n])
    {
        if(c==p)continue;
        else dfs(c,n,h+1);
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1),p(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)cin>>p[i];
    for(int i=2;i<=n;i++)
    {
        gp[p[i]].push_back(i);
        gp[i].push_back(p[i]);
    }
    dfs(1,-1,0);
    vector<int>tot(n+1);
    for(int i=1;i<=n;i++)
    tot[depth[i]]+=a[i];
    int ok=0;
    for(int i=n;i>=0;i--)
    {
        if(tot[i]>0)
        {
            ok=1;
            break;
        }
        else if(tot[i]<0)
        {
            ok=-1;
            break;
        }
    }
    if(ok==0)cout<<"0"<<endl;
    else if(ok>0)cout<<"+"<<endl;
    else cout<<"-"<<endl;
}


