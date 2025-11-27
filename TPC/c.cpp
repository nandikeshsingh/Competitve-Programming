#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int>vec(n+1,0);
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]==s[i+1])vec[i+1]=1;
    }   
    for(int i=1;i<=n;i++)vec[i]+=vec[i-1];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<vec[r-1]-vec[l-1]<<endl;
    }
    return 0;
}


