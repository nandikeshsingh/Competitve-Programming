#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
        }
        if((n+m-1)%2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int mn[n][m],mx[n][m];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    mx[i][j]=arr[i][j];
                    mn[i][j]=arr[i][j];
                }
                else if(i==n-1 && j!=m-1)
                {
                    mx[i][j]=arr[i][j]+mx[i][j+1];
                    mn[i][j]=arr[i][j]+mn[i][j+1];
                }
                else if(i!=n-1 && j==m-1)
                {
                    mx[i][j]=arr[i][j]+mx[i+1][j];
                    mn[i][j]=arr[i][j]+mn[i+1][j];
                }
                else 
                {
                    mx[i][j]=arr[i][j]+max(mx[i+1][j],mx[i][j+1]);
                    mn[i][j]=arr[i][j]+min(mn[i+1][j],mn[i][j+1]);
                }
            }
        }
        if(mn[0][0]<=0 && mx[0][0]>=0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

