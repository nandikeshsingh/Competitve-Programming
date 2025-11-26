#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n+2][m+2];
        rep(i,0,n+1)
        {
            rep(j,0,m+1)arr[i][j]=0;
        }
        rep(i,1,n)
        {
            rep(j,1,m)
            cin>>arr[i][j];
        }
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                if(arr[i][j]>arr[i-1][j] &&arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i][j-1] && arr[i][j]>arr[i][j+1])
                {
                    int mx=max({arr[i-1][j],arr[i+1][j],arr[i][j-1],arr[i][j+1]});
                    arr[i][j]=mx;
                }
            }
        }
        // cout<<"out"<<endl;
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


