#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int setBitNumber(int n)
{
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int nn=setBitNumber(n);
        nn*=2;
        nn--;
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)a[i]^=a[i-1];
        vector<int>mp(nn+1);
        int tot=(n*(n+1))/2;
        int cnt=0;
        mp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int cur=a[i];
            int j=0;
            while((cur^(j*j))<=nn)
            {
                if(mp[((cur^(j*j)))])cnt+=mp[(cur^(j*j))];
                j++;
                
            }
            mp[a[i]]++;
        }
        cout<<tot-cnt<<endl;
    }
    return 0;
}
 