#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    vector<vector<char>>b(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>b[i][j];
    }
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                cout<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    return 0;
}


