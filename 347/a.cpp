#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%k==0)
        {
            a[i]/=k;
            cout<<a[i]<<" ";

        }
    }
    cout<<endl;
    return 0;
}


