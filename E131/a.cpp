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

        int arr[2][2];
        int cnt=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j])cnt++;
            }
        }
        if(cnt==0)cout<<0<<endl;
        else if(cnt==1)cout<<1<<endl;
        else if(cnt==4)cout<<2<<endl;
        else if (cnt==3)cout<<1<<endl;
        else 
        {
            cout<<1<<endl;
        }

    }
    return 0;
}

