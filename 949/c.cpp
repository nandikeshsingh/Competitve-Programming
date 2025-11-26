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
        int n;
        cin>>n;
        vi a(n),pos,ans(n,0);
        bool all=1;
        rep(i,0,n-1)
        {
            cin>>a[i];
            if(a[i]!=-1)pos.pb(i),all=0;
            ans[i]=a[i];
        }
        if(all)
        {
            int cur=1e9;
            bool f=1;
            rep(i,0,n-1)
            {
                if(f)
                {
                    ans[i]=cur;
                    cur/=2;
                }
                else 
                {
                    ans[i]=cur;
                    cur*=2;
                }
                if(cur>1)f=1;
                else f=0,cur*=2;
            }
            rep(i,0,n-1)cout<<ans[i]<<" ";
            cout<<endl;
            continue;
        }
        bool ok=1;
        int len=sz(pos);
        cout<<"Priting pos"<<endl;
        rep(i,0,n-1)cout<<ans[i]<<" ";
        cout<<endl;
       
        rep(i,1,len-1)
        {
            int mx=max(a[pos[i]],a[pos[i-1]]);
            int mn=min(a[pos[i]],a[pos[i-1]]);
            int need=0;
            while(mx>mn)
            {
                mx/=2;
                need++;
            }
            if(mx!=mn)
            {
                ok=0;
                break;
            }
            int have=pos[i]-pos[i-1]+1;
            if(need>have)
            {
                ok=0;
                break;
            }
            else if((have-need)%2==0 && have!=need)
            {
                ok=0;
                break;
            }
            else 
            {
                int r=a[pos[i]];
                int l=a[pos[i-1]];
                if(r>=l)
                {
                    int p=pos[i];
                    while(r!=l)
                    {
                        p--;
                        ans[p]=r/2;
                        r/=2;
                    }
                    if(p!=pos[i-1])
                    {
                        p--;
                        bool f=1;
                        while(p!=pos[i-1])
                        {
                            if(f)
                            {
                                ans[p]=2*l;
                                f=1-f;
                            }
                            else 
                            {
                                ans[p]=l;
                                f=1-f;
                            }
                            p--;
                        }
                    }
                }
                else //r<l
                {
                    int p=pos[i-1];
                    // cout<<"p="<<p<<" l="<<l<<" r="<<r<<endl;
                    while(l!=r)
                    {
                        p++;
                        ans[p]=l/2;
                        l/=2;
                    }
                    if(p!=pos[i])
                    {
                        p++;
                        bool f=1;
                        while(p!=pos[i])
                        {
                            if(f)
                            {
                                ans[p]=2*r;
                                f=1-f;
                            }
                            else 
                            {
                                ans[p]=r;
                                f=1-f;
                            }
                            p++;
                        }
                    }
                }
            }
        }
        if(!ok)cout<<-1<<endl;
        else 
        {
            int fidx=-1,lidx=-1;
            rep(i,0,n-1)
            {
                if(a[i]!=-1)
                {
                    fidx=i;
                    break;
                }
            }
            per(i,n-1,0)
            {
                if(a[i]!=-1)
                {
                    lidx=i;
                    break;
                }
            }
            int cur=a[fidx];
            bool f=1;
            if(cur>1)f=1;
            else f=0;
            per(i,fidx-1,0)
            {
                if(f)
                {
                    ans[i]=cur/2;
                    cur/=2;
                }
                else 
                {
                    ans[i]=2*cur;
                    cur*=2;
                }
                if(cur>1)f=1;
                else if(cur<=1)f=0;
            }
            cur=a[lidx];
            rep(i,lidx+1,n-1)
            {
                if(f)
                {
                    ans[i]=cur/2;
                    cur/=2;
                }
                else 
                {
                    ans[i]=2*cur;
                    cur*=2;
                }
                if(cur>1)f=1;
                else f=0;
            }
            rep(i,0,n-1)cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}


