#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>bit;
void update(int v,int n,int val)
{
    for(int i=v;i<=n;i+=(i&(-i)))
    bit[i]+=val;
}
int query(int v,int n)
{
    int ret=0;
    for(int i=v;i>0;i-=(i&(-i)))
    ret+=bit[i];
    return ret;
}
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    bit.resize(n+1,0);
    for(int i=0;i<n;i++)
    {
        int u;cin>>u;
        update(u,n,1);
    }
    while(q--)
    {
        int k;cin>>k;
        if(k>0)update(k,n,1);
        else 
        {
            k*=-1;
            int lo=1,hi=n;
            while(lo<hi)
            {
                int mid=(lo+hi)>>1;
                if(query(mid,n)<k)lo=mid+1;
                else hi=mid;
            }
            update(lo,n,-1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(bit[i]>0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//Problem Solving(Advanced)
//September 2020
//CD0E99A26D76
//https://www.hackerrank.com/certificates/cd0e99a26d76