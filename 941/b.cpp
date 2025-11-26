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
        vector<vector<char>>a(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin>>a[i][j];
        }
        bool ok=1;
        set<char>all;
        set<char>st1,st2;
        for(int i=0;i<n;i++)
        {
            st1.insert(a[i][0]);
            st2.insert(a[i][m-1]);
        }
        if(sz(st1)==1)
        {
            all.insert(*st1.begin());
        }
        if(sz(st2)==1)
        {
            all.insert(*st2.begin());
        }
        st1.clear();
        st2.clear();
        for(int j=0;j<m;j++)
        {
            st1.insert(a[0][j]);
            st2.insert(a[n-1][j]);
        }
        if(sz(st1)==1)
        {
            all.insert(*st1.begin());
        }
        if(sz(st2)==1)
        {
            all.insert(*st2.begin());
        }
        if(sz(all)>1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}


