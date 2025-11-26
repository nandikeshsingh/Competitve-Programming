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
        int mn=1e18;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mn=min(mn,a[i]);
        }   
        if(a[0]!=mn)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}


