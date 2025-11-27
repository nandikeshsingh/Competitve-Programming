#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int a,m,l,r;
    cin>>a>>m>>l>>r;
    int k=ceil((long double)(l-a)/(long double)m);
    int p=a+k*m;
    int rim=r-p;
    if(rim<0)
    {
        cout<<0<<endl;
    }
    else 
    {
        int ans=rim/m;
        cout<<ans+1<<endl;
    }

    return 0;
}


