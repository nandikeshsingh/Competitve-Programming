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
    vector<int>b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    vector<vector<int>>a(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        a[i][j]=(i*j)%n;
    for(int i=0;i<n;i++)
    {
        int add=((b[i]-a[i][i]+n)%n);
        for(int j=0;j<n;j++)
        {
            a[i][j]+=add;
            a[i][j]%=n;
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }   
    return 0;
}


