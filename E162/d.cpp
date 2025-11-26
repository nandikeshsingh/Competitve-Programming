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
        vector<int>a(n+1);
        vector<int>ans(n+1);
        vector<int>lnxt(n+1),rnxt(n+1);
        map<int,int>lmp,rmp;
        int lsum=0,rsum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            rmp[a[i]]++;
            rsum+=a[i];
        }
        for(int i=n;i>=1;i--)
        {
            if(i==n)lnxt[i]=-1;
            else
            {
                if(a[i]!=a[i+1])lnxt[i]=i+1;
                else lnxt[i]=lnxt[i+1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i==1)rnxt[i]=-1;
            else 
            {
                if(a[i]!=a[i-1])rnxt[i]=i-1;
                else rnxt[i]=rnxt[i-1];
            }
        }
        vector<int>l(n+1,0),r(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i>1 && i<n)
            {
                rsum-=a[i];
                rmp[a[i]]--;
                if(rmp[a[i]]==0)rmp.erase(rmp.find(a[i]));
                if(lsum<=a[i])l[i]=-1;
                else 
                {
                    if(sz(lmp)==1 && lmp.begin()->first<=a[i])l[i]=-1;
                }
                if(rsum<=a[i])r[i]=-1;
                else 
                {
                    if(sz(rmp)==1 && rmp.begin()->first<=a[i])r[i]=-1;
                }
                if(l[i]==-1 && r[i]==-1)ans[i]=-1;
                lsum+=a[i];
                lmp[a[i]]++;
            }
            else if(i==1)
            {
                rsum-=a[i];
                rmp[a[i]]--;
                if(rmp[a[i]]==0)rmp.erase(rmp.find(a[i]));
                if(rsum<=a[i])ans[i]=-1;
                else if(sz(rmp)==1 && rmp.begin()->first<=a[i])ans[i]=-1;
                lsum+=a[i];
                lmp[a[i]]++;
            }
            else if(i==n)
            {
                rsum-=a[i];
                rmp[a[i]]--;
                if(rmp[a[i]]==0)rmp.erase(rmp.find(a[i]));
                if(lsum<=a[i])ans[i]=-1;
                else if(sz(lmp)==1 && lmp.begin()->first<=a[i])ans[i]=-1;
                lsum+=a[i];
                lmp[a[i]]++;  
            }
        }
        // cout<<"Printing ans"<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<i<<" "<<ans[i]<<endl;
        // }
        vector<int>ll(n+1,0),rr(n+1,0);
        for(int i=1;i<=n;i++)ll[i]=ll[i-1]+a[i];
        for(int i=n;i>=1;i--)
        {
            if(i==n)rr[i]=a[i];
            else rr[i]=rr[i+1]+a[i];
        }
        reverse(all(rr));
        rr.pop_back();
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==-1)continue;
            // cout<<a[i]<<" "<<l[i]<<" "<<r[i]<<endl;
            int left=upper_bound(all(ll),ll[i]+a[i])-ll.begin();
            if(i<n)
            {
                int l_nxt_ok=lnxt[i+1];
                if(l_nxt_ok>left && left-i!=1)left=l_nxt_ok;
            }

            int right=upper_bound(all(rr),rr[n-i]+a[i])-rr.begin();
            int r_nxt_ok=n-rnxt[i-1];
            if(r_nxt_ok>right && right-(n-i)!=1)right=r_nxt_ok;
            // cout<<"right="<<right<<endl;
            if(i==n)ans[i]=right-(n-i);
            else if(i==1)ans[i]=left-i;
            else 
            {
                if(l[i]==0 && r[i]==0)
                ans[i]=min(left-i,right-(n-i));
                else if(l[i]==0 && r[i]==-1)ans[i]=right-(n-i);
                else if(r[i]==0 && l[i]==-1)ans[i]=left-i;
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}


