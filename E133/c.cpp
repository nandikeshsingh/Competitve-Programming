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
        int m;
        cin>>m;
        int arr[2][m];
        int dp[2][m];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                dp[i][j]=0;
                arr[i][j]++;
            }
        }
        dp[0][m-1]=max(arr[0][m-1]+1,arr[1][m-1]);
        dp[1][m-1]=max(arr[1][m-1]+1,arr[0][m-1]);
        for(int j=m-2;j>=0;j--)
        {
            for(int i=0;i<2;i++)
            {
                if(j%2)
                {
                    if(i==1)
                    {
                        int val=dp[i][j+1]+1;
                        val=max(val,arr[i-1][j]);
                        dp[i][j]=max(val,arr[i][j]+1);

                        int cur=max(dp[i-1][j],arr[i][j]+1);
                        dp[i][j]=min(dp[i][j],cur);
                    }
                    else {
                        int val=dp[i][j+1];
                        dp[i][j]=max(val,arr[i][j]+2*(m-1-j)+1);
                    }
                }
                else
                {
                    if(i%2==0)
                    {
                        int val=dp[i][j+1]+1;
                        val=max(val,arr[i+1][j]);
                        dp[i][j]=max(val,arr[i][j]+1);

                        int cur=max(arr[i][j]+1,arr[i+1][j]);
                        cur=max(dp[i+1][j+1],cur);
                        dp[i][j]=min(dp[i][j],cur);

                    }
                    else{
                            int val=dp[i][j+1];
                            dp[i][j]=max(val,arr[i][j]+1);
                    }   
                }
            }

        }
        cout<<"Printing dp"<<endl;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}


