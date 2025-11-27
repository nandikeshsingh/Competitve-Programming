#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
void print(vector<int>&vec)
{
    for(auto& u : vec)cout<<u<<" ";
    cout<<endl;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>c(n+1,0);
    for(int i=1;i<=n;i++)cin>>c[i];
    vector<int>pc1(n+1,0),pc0(n+1,0),sc1(n+2,0),sc0(n+2,0);
    char cur='1';
    for(int i=1;i<=n;i++)
    {
        if(cur!=s[i-1])
        {
            pc1[i]=pc1[i-1]+c[i];
        }
        else pc1[i]=pc1[i-1];
        if(cur=='1')cur='0';
        else cur='1';
    }
    cur='0';
    for(int i=1;i<=n;i++)
    {
        if(cur!=s[i-1])
        {
            pc0[i]=pc0[i-1]+c[i];
        }
        else pc0[i]=pc0[i-1];
        if(cur=='1')cur='0';
        else cur='1';
    }
    cur='1';
    for(int i=n;i>=1;i--)
    {
        if(cur!=s[i-1])
        {
            sc1[i]=sc1[i+1]+c[i];
        }
        else sc1[i]=sc1[i+1];
        if(cur=='1')cur='0';
        else cur='1';
    }
    cur='0';
    for(int i=n;i>=1;i--)
    {
        if(cur!=s[i-1])
        {
            sc0[i]=sc0[i+1]+c[i];
        }
        else sc0[i]=sc0[i+1];
        if(cur=='1')cur='0';
        else cur='1';
    }  
    int ans=1e18;
    for(int i=1;i<n;i++)
    {
        int left_1=0,right_1=0;
        if(i&1)
            left_1=pc1[i];
        else left_1=pc0[i];
        if((n-i)&1)right_1=sc1[i+1];
        else right_1=sc0[i+1];
        ans=min(ans,left_1+right_1);
                int left_0=0,right_0=0;
        if(i&1)
            left_0=pc0[i];
        else left_0=pc1[i];
        if((n-i)&1)right_0=sc0[i+1];
        else right_0=sc1[i+1];
        ans=min(ans,left_0+right_0);
    }
    cout<<ans<<endl;
    return 0;
}


