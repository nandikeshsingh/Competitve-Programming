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
        for(int i=0;i<n;i++)cin>>a[i];
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        int cur=n;
        int s=a[0],e=a[n-1];
        if(s==e)
        {
            while(a.back()==e)a.pop_back();
            reverse(all(a));
            while(a.back()==e)a.pop_back();
            cout<<sz(a)<<endl;
        }
        else 
        {
            vector<int>aa=a;
            while(a.back()==e)a.pop_back();
            reverse(all(aa));
            while(aa.back()==s)aa.pop_back();
            cout<<min(sz(a),sz(aa))<<endl;
        }
    }
    return 0;
}


