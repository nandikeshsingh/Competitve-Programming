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
        vector<int>od,ev;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2)od.push_back(i+1);
            else ev.push_back(i+1);
        }
        if(sz(od)>=3)
        {
            cout<<"YES"<<endl;
            cout<<od[0]<<" "<<od[1]<<" "<<od[2]<<endl;
        }
        else if(sz(od)>=1 && sz(ev)>=2)
        {
            cout<<"YES"<<endl;
            cout<<od[0]<<" "<<ev[0]<<" "<<ev[1]<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}


