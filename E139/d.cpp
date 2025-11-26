#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int MAXN=1e7+10;
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        int cur=spf[x];
        while(x%cur==0)x/=cur;
    }
    return ret;
}
 
signed main()
{
    speed;
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(__gcd(x,y)!=1)cout<<0<<endl;
        else 
        {
            if(y-x==1)cout<<-1<<endl;
            else 
            {
                // while(y>x)y-=x;
                y-=x;
                vector<int>vec=getFactorization(y);
                int ans=1e18;
                for(auto& p : vec)
                {
                    int div=(x/p)+1;
                    int up=div*p;
                    ans=min(ans,up-x);
                }
                cout<<ans<<endl;
            }
        }
    }   
    return 0;
}


