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
        int dig=0;
        int cn=n;
        int f=0;
        while(n)
        {
            if(n<=9)f=n;
            n/=10;
            dig++;
            
        }
        cout<<f+9*(dig-1)<<endl;
    }
    return 0;
}


