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
        int nn;
        cin>>nn;
        string str;
        cin>>str;
        int n=0,e=0,w=0,s=0;
        vector<int>np,ep,wp,sp;
        rep(i,0,nn-1)
        {
            if(str[i]=='N')n++,np.pb(i);
            if(str[i]=='E')e++,ep.pb(i);
            if(str[i]=='W')w++,wp.pb(i);
            if(str[i]=='S')s++,sp.pb(i);
        }
        if((n==1&&s==1 && w==0&&e==0) || (w==1&&e==1&&n==0&&s==0))cout<<"NO"<<endl;
        else if((n%2==0&&s%2==1)||(n%2==1&&s%2==0)||(w%2==1&&e%2==0)||(e%2==1&&w%2==0))cout<<"NO"<<endl;
        else if(n==1 && s==1 && w==1 && e==1)
        {
            vector<char>ans(nn);
            rep(i,0,nn-1)
            {
                if(str[i]=='N' || str[i]=='S')ans[i]='R';
                else ans[i]='H';
            }
            rep(i,0,nn-1)cout<<ans[i];
            cout<<endl;
        }
        else
        {
            vector<char>ans(nn);
            if((n%2==0)&&(s%2==0))
            {
                int cnt=n;
                cnt/=2;
                for(auto& p : np)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
                cnt=s/2;
                for(auto& p : sp)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
            }
            if((w%2==0)&&(e%2==0))
            {
                int cnt=w/2;
                for(auto& p : wp)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
                cnt=e/2;
                for(auto& p : ep)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
            }
            if((n%2==1)&&(s%2==1))
            {
                int cnt=(n+1)/2;
                for(auto& p : np)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
                cnt=(s+1)/2;
                for(auto& p : sp)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
            }
            if((w%2==1)&&(e%2==1))
            {
                int cnt=(w+1)/2;
                for(auto& p : wp)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
                cnt=(e+1)/2;
                for(auto& p : ep)
                {
                    if(cnt)
                    {
                        ans[p]='R';
                        cnt--;
                    }
                    else 
                    {
                        ans[p]='H';
                    }
                }
            }
            int r=0,h=0;
            rep(i,0,nn-1)
            {
                cout<<ans[i];
                if(ans[i]=='R')r++;
                else h++;
            }
            cout<<endl;
            assert(r>=1 && h>=1);
        }
    }
    return 0;
}


