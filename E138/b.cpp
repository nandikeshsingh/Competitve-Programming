#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>a,b,c;
bool cmp(int x,int y)
{
    return b[x]<b[y];
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a.resize(n);
        b.resize(n);
        c.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int l=0,r=n-1;
        int ans=0;
        while(l<r)
        {
            if(b[l]<b[r])
            {
                ans+=a[l]+b[l];
                l++;
            }
            else 
            {
                ans+=a[r]+b[r];
                r--;
            }
        }
        if(l==r)
        ans+=a[l];
        // for(int i=0;i<n;i++)c[i]=i;
        // sort(all(c),cmp);
        // int ans=0;
        // cout<<"Printing c"<<endl;
        // for(int i=0;i<n;i++)cout<<c[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     ans+=a[c[i]];
        //     if(c[i]+1<n)
        //     {
        //         a[c[i]+1]+=b[c[i]];
        //     }
        //     if(c[i]-1>=0)
        //     {
        //         a[c[i]-1]+=b[c[i]];
        //     }
        // }
        cout<<ans<<endl;
    }
    return 0;
}


