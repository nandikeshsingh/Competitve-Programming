#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,s,k;
    cin>>n>>s>>k;
    vector<int>p(n),q(n);
    for(int i=0;i<n;i++)cin>>p[i]>>q[i];
    int tot=0;
    for(int i=0;i<n;i++)tot+=(p[i]*q[i]);
    if(tot<s)tot+=k;
    cout<<tot<<endl;
    return 0;
}


 cout<<"Printing har"<<endl;
    for(int i=0;i<h;i++)
    {
        cout<<har[i]<<" ";
    }
    cout<<endl;
        cout<<"Printing hbr"<<endl;
    for(int i=0;i<h;i++)
    {
        cout<<hbr[i]<<" ";
    }
    cout<<endl;
        cout<<"Printing hac"<<endl;
    for(int i=0;i<w;i++)
    {
        cout<<hac[i]<<" ";
    }
    cout<<endl;
            cout<<"Printing hbc"<<endl;
    for(int i=0;i<w;i++)
    {
        cout<<hbc[i]<<" ";
    }
    cout<<endl;