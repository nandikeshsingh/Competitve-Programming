#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,s;
    cin>>n>>s;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>mk(n,0);
    int cur=0;
    for(int i=0;i<n;i++)
    {
        if(cur+a[i]<=s)cur+=a[i];
        else 
        {
            cur=a[i];
            mk[i-1]=1;
        }
    }
    mk[n-1]=1;
    int ans=0;
    vector<int>pre(n,0);
    for(int i=0;i<n;i++)
    {
        if(i==0)pre[i]=mk[i];
        else pre[i]=pre[i-1]+mk[i];
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(mk[i]==0)
    //     pre[i]++;
    // }
    vector<int>dpre(n,0);
    for(int i=0;i<n;i++)
    {
        if(i==0)dpre[i]=pre[i];
        else dpre[i]=dpre[i-1]+pre[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)ans++;
        else 
        {
            int cur=(pre[i]+1)*(i+1);
            cur-=(dpre[i-1]);
            cout<<"cur="<<cur<<endl;
            ans+=cur;
        }
    }
    cout<<ans<<endl;
    return 0;
}


