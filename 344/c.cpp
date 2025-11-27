#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int m;cin>>m;
    vector<int>b(m);
    for(int i=0;i<m;i++)cin>>b[i];
    int l;cin>>l;
    vector<int>c(l);
    for(int i=0;i<l;i++)cin>>c[i];
    set<int>st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<l;k++)
            {
                st.insert(a[i]+b[j]+c[k]);
            }
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int x;cin>>x;
        if(st.count(x))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


