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
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=n;
        int i=1,j=1;
        cout<<1<<" "<<1<<endl;
        cout<<2<<" "<<1<<endl;
        cnt-=2;
        if(cnt>0)
        {
            cout<<n<<" "<<n<<endl;
            cnt--;
            while(j+2<=n && cnt>0)
            {
                j+=2;
                cout<<i<<" "<<j<<endl;
                cnt--;
                if(cnt==0)break;
            }
            if(cnt>0)
            {
                i=n-1;
                while(cnt>0)
                {
                    cout<<i<<" "<<n<<endl;
                    cnt--;
                    i--;
                }
            }
        }
 

    }
    return 0;
}


