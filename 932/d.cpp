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
        int n,c;
        cin>>n>>c;
        vector<int>s;
        vector<int>p(2,0);
        int tot=(c+1)*(c+2);
        tot/=2;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            p[x%2]++;
            tot-=(c-x);
            tot-=(x+1-(x+1)/2);
        }
        tot+=(p[0]*(p[0]-1))/2;
        tot+=(p[1]*(p[1]-1))/2;
        cout<<tot<<endl;
    }
    return 0;
}


