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
vector<vector<int>> permute(int n)
{
    vector<vector<int>>ret;
   int a[n];
   int i,j,k,store;
   for(i=0;i<n;i++)
    a[i]=i+1;
   for(i=1;i<=n;i++)
   {
    vector<int>cur(n+1);
      for(j=0;j<n-1;j++)
      {
         store=a[j+1];
         a[j+1]=a[j];
         a[j]=store;
         for(k=0;k<n;k++)cur[k+1]=a[k];
      }
      ret.pb(cur);
   }
    return ret;
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
        // vector<vector<int>>ret=permute(n);
        // for(auto& u : ret)
        {
                vector<int>a(n+1);
            rep(i,1,n)cin>>a[i];
            // rep(i,1,n)a[i]=u[i];
            // cout<<"cur vec="<<endl;
            // rep(i,1,n)cout<<u[i]<<" ";
            // cout<<endl;
            vector<pair<int,int>>mn,mx;
            bool f=0;
            for(int i=2;i<n;i+=2)
            {
                mx.pb({a[i],i});
                if(a[i]==1)f=1;
            }
            sort(all(mx));
            for(int i=1;i<=n;i+=2)
            {
                mn.pb({a[i],i});
            }
            sort(all(mn));
            if(f)
            {
                mx.clear();
                for(int i=3;i<n;i+=2)
                {
                    mx.pb({a[i],i});
                }
                sort(all(mx));
                mn.clear();
                for(int i=n;i>=1;i-=2)
                {
                    mn.pb({a[i],i});
                }
                sort(all(mn));
            }
            // cout<<"Printing mn"<<endl;
            // for(auto& u : mn)cout<<u.first<<" "<<u.second<<endl;
            int e=n,s=1;
            vector<int>q(n+1,0);
            while(sz(mn))
            {
                int idx=mn.back().second;
                mn.pop_back();
                q[idx]=s++;
            }
            for(int i=0;i<sz(mx);i++)
            {
                int idx=mx[i].second;
                q[idx]=e--;
            }
            for(int i=1;i<=n;i++)
            {
                if(q[i]==0)
                {
                    q[i]=s;
                    break;
                }
            }
            int cnt=0;
            vector<int>ss(n+1,0);
            rep(i,1,n)ss[i]=a[i]+q[i];
            for(int i=2;i<n;i++)
            {
                if((ss[i]>ss[i-1])&&(ss[i]>ss[i+1]))cnt++;
            }
            rep(i,1,n)cout<<q[i]<<" ";
            cout<<endl;
            // cout<<"cnt="<<cnt<<endl;
            assert(cnt==(n-2)/2);
        }
    }
    return 0;
}


