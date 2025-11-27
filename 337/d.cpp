#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int h,w,k;
    cin>>h>>w>>k;
    vector<string>grid;
    vector<vector<int>>x,d;
    for(int i=0;i<h;i++)
    {
        string s;cin>>s;
        grid.push_back(s);
        vector<int>temp1,temp2;
        temp1.push_back(0);
        temp2.push_back(0);
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='x')
            {
                temp1.push_back(1);
                temp2.push_back(0);
            }
            else if(s[j]=='.')
            {
                temp1.push_back(0);
                temp2.push_back(1);
            }
            else 
            {
                temp1.push_back(0);
                temp2.push_back(0);
            }
        }
        for(int j=1;j<=s.length();j++)
        {
            temp1[j]+=temp1[j-1];
            temp2[j]+=temp2[j-1];
        }
        x.push_back(temp1);
        d.push_back(temp2);
    }
    int ans=1e18;
    for(int i=0;i<h;i++)
    {
        for(int j=k;j<=w;j++)
        {
            if(x[i][j]-x[i][j-k]>0)continue;
            ans=min(ans,d[i][j]-d[i][j-k]);
        }
    }
    vector<vector<int>>xx(h+1,vector<int>(w,0));
    vector<vector<int>>dd(h+1,vector<int>(w,0));
    for(int j=0;j<w;j++)
    {
        for(int i=0;i<h;i++)
        {

            if(grid[i][j]=='x')
            {
                xx[i+1][j]=1;
                dd[i+1][j]=0;
            }
            else if(grid[i][j]=='.')
            {
                xx[i+1][j]=0;
                dd[i+1][j]=1;
            }
            else 
            {
                xx[i+1][j]=0;
                dd[i+1][j]=0;
            }
        }
        for(int i=1;i<=h;i++)
        {
            xx[i][j]+=xx[i-1][j];
            dd[i][j]+=dd[i-1][j];
        }
    }
    for(int j=0;j<w;j++)
    {
        for(int i=k;i<=h;i++)
        {
            if(xx[i][j]-xx[i-k][j]>0)continue;
            ans=min(ans,dd[i][j]-dd[i-k][j]);
        }
    }
    if(ans==1e18)ans=-1;
    cout<<ans<<endl;
    return 0;
}


