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
        int n,k;
        cin>>n>>k;
        string s;cin>>s;
        vi a(n+1,0),ss(n+1);
        rep(i,1,n)
        {
            ss[i]=s[i-1]-'0';
            if(s[i-1]=='1')a[i]=a[i-1]+1;
            else a[i]=a[i-1];
        }
        int ans=-1;
        for(int p=1;p<=n;)
        {
            // cout<<"p="<<p<<endl;
            if(p<=n-k+1)
            {
                if(a[p+k-1]-a[p-1]==0 || a[p+k-1]-a[p-1]==k)
                {
                    bool ok=1;
                    int last=-1;
                    rep(j,p,p+k-1)
                    {
                        int val=ss[j];
                        bool f=1;
                        int jj=j;
                        while(jj>=1)
                        {
                            // cout<<"j="<<j<<endl;
                            if(ss[jj]!=val)
                            {
                                f=0;
                                last=jj;
                                break;
                            }
                            else 
                            {
                                if(jj>=p)jj+=k;
                                else jj-=k;
                                if(jj>n)
                                {
                                    // cout<<"jj before="<<jj<<endl;
                                    int ex=jj-n;
                                    jj=p-ex;
                                    // cout<<"jj after="<<jj<<endl;
                                }
                                val=1-val;
                            }
                        }
                        // cout<<"out jj="<<jj<<endl;
                        // cout<<"last = "<<last<<endl;
                        if(!f)
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(ok)
                    {
                        ans=p;
                        break;
                    }
                    if(p+k<=n && ss[p+k]!=ss[p])
                    {
                        if(last>p)
                        {
                            if((last-p)%k==0)
                            p=last-k+1;
                            else p=last;
                        }
                        else 
                        {
                            p++;

                        }

                    }
                    else p++;
                }
                else p++;
            }
            else p++;
        }
        if(ans!=-1)
        {
            ans--;
            if(ans==0)ans=n;
        }
        cout<<ans<<endl;
    }
    return 0;
}


