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
        int k,q;
        cin>>k>>q;
        vector<int>a(k,0),n(q,0);
        for(int i=0;i<k;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<q;i++)cin>>n[i];
        for(int i=0;i<q;i++)
        {
            cout<<min(n[i],a[0]-1)<<" ";
        }
        cout<<endl;

    }
    return 0;
}


