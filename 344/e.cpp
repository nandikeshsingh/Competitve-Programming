#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;

signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mp,rmp;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            int x;cin>>x;
            a[i]=x;
            mp[-1]=x;
            rmp[x]=-1;
        }
        else 
        {
            int x;cin>>x;
            a[i]=x;
            mp[a[i-1]]=x;
            rmp[x]=a[i-1];
        }

    }
    mp[a[n-1]]=0;
    rmp[0]=a[n-1];
    int q;cin>>q;
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int x,y;cin>>x>>y;
            int n=mp[x];
            mp.erase(mp.find(x));
            rmp.erase(n);
            mp[x]=y;
            mp[y]=n;
            rmp[n]=y;
            rmp[y]=x;
        }
        else 
        {
            int x;cin>>x;
            int b=rmp[x];
            int n=mp[x];
            mp[b]=n;
            rmp[n]=b;
        }
    }
    int cur=-1;
    while(mp[cur]!=0)
    {
        cout<<mp[cur]<<" ";
        cur=mp[cur];
    }
    cout<<endl;
    return 0;
}


