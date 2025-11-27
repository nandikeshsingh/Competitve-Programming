#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<string>g;
string t;
int h,w,n;
bool check(int i,int j,int p)
{
    // cout<<i<<" "<<j<<" "<<p<<endl;
    if(i<0 || i>=h || j<0 || j>=w)return false;
    if(g[i][j]=='#')return false;
    if(p>=n)return true;
    // cout<<"now"<<endl;
    if(t[p]=='L')return check(i,j-1,p+1);
    else if(t[p]=='U')return check(i-1,j,p+1);
    else if(t[p]=='R')return check(i,j+1,p+1);
    else return check(i+1,j,p+1);
}
signed main()
{
    speed;
    cin>>h>>w>>n;
    cin>>t;
    for(int i=1;i<=h;i++)
    {
        string s;cin>>s;
        g.push_back(s);
    }
    int ans=0;
    // cout<<check(1,3,0)<<endl;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(g[i][j]=='#')continue;
            if(check(i,j,0))
            {
                // cout<<"i="<<i<<" j="<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


