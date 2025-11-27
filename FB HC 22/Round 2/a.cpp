#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int mod=1e9+7;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        ordered_set st[1000001];
        int n;
        cin>>n;
        vector<int>s(n);
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<n;i++)
        st[s[i]].insert(i);
        int q;
        cin>>q;
        int ans=0;
        while(q--)
        {
            int t, l,r;
            cin>>t>>l>>r;
            l--;r--;
            if(t==1)
            {
                st[r].insert(l);
                st[s[l]].erase(l);
                continue;
            }
            cout<<"1"<<endl;
            if((r-l+1)%2==0)continue;
            int mid=(l+r)/2;
            int cnt=0;
            int c;
            for(int i=1;i<=1e6;i++)
            {
                int cur=st[i].order_of_key(r+1)-st[i].order_of_key(l);
                if(cur%2)c=i,cnt++;
            }
            if(cnt!=1)continue;
            cout<<2<<endl;
            if(s[mid]==c)
            {
                int left=st[c].order_of_key(mid)-st[c].order_of_key(l);
                int right=st[c].order_of_key(r+1)-st[c].order_of_key(l)-left-1;
                if(left!=right)continue;
                bool ok=1;
                for(int i=1;i<=1e6;i++)
                {
                    if(i==c)continue;
                    int left=st[i].order_of_key(mid)-st[i].order_of_key(l);
                    int right=st[i].order_of_key(r+1)-st[i].order_of_key(l)-left; 
                    if(left!=right)
                    {
                        ok=0;
                        break;
                    }                  
                }
                if(ok)ans++;
            }
            else 
            {
                int left=st[c].order_of_key(mid)-st[c].order_of_key(l);
                int right=st[c].order_of_key(r+1)-st[c].order_of_key(l)-left;
                if(right-left==1)//l to mid-1, mid to r
                {
                    bool ok=1;
                    for(int i=1;i<=1e6;i++)
                    {
                        if(i==c)continue;
                        int left=st[i].order_of_key(mid)-st[i].order_of_key(l);
                        int right=st[i].order_of_key(r+1)-st[i].order_of_key(l)-left; 
                        if(left!=right)
                        {
                            ok=0;
                            break;
                        }                  
                    }
                    if(ok)ans++;                
                }     
                else if(left-right==1)
                {
                    bool ok=1;
                    for(int i=1;i<=1e6;i++)
                    {
                        if(i==c)continue;
                        int left=st[i].order_of_key(mid+1)-st[i].order_of_key(l);
                        int right=st[i].order_of_key(r+1)-st[i].order_of_key(l)-left; 
                        if(left!=right)
                        {
                            ok=0;
                            break;
                        }                  
                    }
                    if(ok)ans++;                         
                }              
            }
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}


