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
        bool x=0,y=0,z=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1] && a[i]==-1)x=1;
            else if(a[i]==a[i-1] && a[i]==1)z=1;
            else y=1;
        }
        if(x==1)s+=4;
        else if(y==1)s+=0;
        else s-=4;
        cout<<s<<endl;

    }
    return 0;
}


