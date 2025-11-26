#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>a(n,vector<int>(n,0));
        vector<vector<int>>ans;
        int tot=0;
        for(int i=1;i<=n;i++)tot+=i*(i+i-1);
        cout<<tot<<" "<<2*n<<endl;
        for(int i=n-1;i>=0;i--)
        {
            for(int c=1;c<=2;c++)
            {
                cout<<c<<" "<<i+1<<" ";
                for(int j=1;j<=n;j++)cout<<j<<" ";
                cout<<endl;
            }
        }
    } 
    return 0;
}


