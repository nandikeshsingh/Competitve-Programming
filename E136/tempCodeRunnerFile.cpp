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
        int n,m;
        cin>>n>>m;
        if(n==1 || m==1)cout<<1<<" "<<1<<endl;
        else if (n==2)
        {
            cout<<1" "<<2<<endl;
        }
        else if(m==2)
        {
            cout<<2" "<<1<<endl; 
        }
        else cout<<3<<" "<<3<<endl;
    }
    return 0;
}


