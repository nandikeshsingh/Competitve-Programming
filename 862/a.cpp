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
        int cur=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cur^=a[i];
        }
        if(n%2)
        {
            cout<<cur<<endl;
        }
        else 
        {
            if(cur==0)cout<<0<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}


