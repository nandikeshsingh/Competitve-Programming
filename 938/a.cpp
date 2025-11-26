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
        int n,a,b; 
        cin>>n>>a>>b;
        if(b>2*a)
        {
            cout<<n*a<<endl;
        }
        else if(b<=2*a)
        {
            if(n%2)cout<<(n/2)*b+a<<endl;
            else cout<<(n/2)*b<<endl;
        }
    }
    return 0;
}

