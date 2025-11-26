#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,r,c;
        cin>>n>>k>>r>>c;
        vector<vector<char>>vec(n,vector<char>(n));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        vec[i][j]='.';
        vec[r-1][c-1]='X';
        int col=c-1;
        int row=r-1;
        int cnt=0;
        for(int i=row;cnt!=n;i++)
        {
            if(i==n)i=0;
            int col_cnt=0;
            for(int j=col;;j+=k)
            {
                
                if(j>=n)j-=n;
                vec[i][j]='X';
                col_cnt++;
                if(col_cnt==(n/k))break;
            }
            col++;cnt++;
            if(col==n)col=0;
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<vec[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}


