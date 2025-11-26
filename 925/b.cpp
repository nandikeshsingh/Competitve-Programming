#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        int s=0;
        for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
        int x=s/n;
        if(a[n-1]>x)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int cur=(a[n-1]-x);
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<x)cur-=(x-a[i]);
            else cur+=(a[i]-x);
            if(cur>0)
            {
                cur=-1;
                break;
            }
        }
        if(cur==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


