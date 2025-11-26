#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int get(int cur,int x)
{
    int d=cur/x;
    return (d+1)*x;
}
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
        int cur=a[0];
        for(int i=1;i<n;i++)
        {
            cur=get(cur,a[i]);
        }
        cout<<cur<<endl;
    }
    return 0;
}


