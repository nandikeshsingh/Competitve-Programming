#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>bit;
void update(int idx,int k,int val)
{
    while(idx<=k)
    {
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int query(int idx,int k)
{
    int ret=0;
    while(idx>0)
    {
        ret+=bit[idx];
        idx-=(idx&(-idx));
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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(k+1),pos(k+1);
        bit.clear();
        bit.resize(k+1,0LL);
        for(int i=1;i<=k;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
            update(i,k,1);
        }
        int ex=n*m-4;
        bool ok=1;
        for(int cur=k;cur>=1;cur--)
        {
            int q=query(pos[cur]-1,k);
            if(q<=ex)
            {
                update(pos[cur],k,-1);
            }
            else 
            {
                ok=0;
                cout<<"TIDAK"<<endl;
                break;
            }
        }
        if(ok)cout<<"YA"<<endl;
        a.clear();
        pos.clear();
    }
    return 0;
}


