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
        int n,m,k;
        cin>>n>>m>>k;
        int d=n/m;
        if(n%m==0)
        {
            int rim=n-d;
            if(k>=rim)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else 
        {
            int rim=n-d-1;
            if(k>=rim)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }

    }
    return 0;
}


