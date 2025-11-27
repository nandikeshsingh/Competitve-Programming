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
    vector<int>p(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
    }
    p[1]=-1;
    vector<vector<int>>anc(19,vector<int>(n+1));
    for(int i=0;i<=18;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==0)anc[i][j]=p[j];
            else 
            {
                if(anc[i-1][j]>=1)
                anc[i][j]=anc[i-1][anc[i-1][j]];
                else anc[i][j]=-1;
            }
        }
    }
    while(q--)
    {
        int x,k;
        cin>>x>>k;
        while(k)
        {
            int last=k&(-k);
            k-=last;
            x=anc[log2(last)][x];
            if(x==-1)break;
        }
        cout<<x<<endl;
    }
    return 0;
}


