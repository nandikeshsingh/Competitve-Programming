#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int q;
    cin>>q;
    vector<int>a;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;cin>>x;
            a.push_back(x);
        }
        else 
        {
            int k;cin>>k;
            cout<<a[sz(a)-k]<<endl;
        }
    }
    return 0;
}


