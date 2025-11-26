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
        int arr[n+1][m+1];
        int x=-1,y=-1;
        int mx=-1e18;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]>mx)
                {
                    mx=arr[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        // cout<<"Printing"<<endl;
        cout<<(int)max(x,n-x+1)*(int)max(y,m-y+1)<<endl;
    }
    return 0;
}

