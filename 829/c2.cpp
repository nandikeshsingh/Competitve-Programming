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
        int x=0,y=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==1)x++;
            else if(a[i]==-1) y++;
        }
        if(x==y)
        {
            cout<<n<<endl;
            for(int i=1;i<=n;i++)cout<<i<<" "<<i<<endl;
        }
        else if((abs(x-y))%2)cout<<"-1"<<endl;
        else if(x>y)
        {
            int k=y+y+(x-y)/2;
            int pr=(x-y)/2;
            cout<<k<<endl;
            int l=1,r=1;
            vector<pair<int,int>>ans;
            while(r<=n)
            {
                if(a[l]==-1)
                {
                    ans.push_back({l,l});
                    l++;
                    if(r<l)r=l;
                }
                else if(a[l]==1)
                {
                    if(r==l && r==n)
                    {
                        ans.push_back({l,l});
                        r++;
                    }
                    else if(r==l && pr>0)
                    {
                        r++;
                    }
                    else if(r==l && pr==0)
                    {
                        ans.push_back({l,l});
                        l++;
                        if(l>r)r=l;
                    }
                    else 
                    {
                        if(a[r]==1)
                        {
                            ans.push_back({l,r});
                            pr--;
                            r++;
                            l=r;
                        }
                        else if(a[r]==-1)
                        {
                            ans.push_back({l,l});
                            l++;
                        }
                    }
                }
            }
            if(pr==0)
            {
                for(auto&u : ans)cout<<u.first<<" "<<u.second<<endl;
            }
            else cout<<-1<<endl;
        }
        else 
        {
            for(int i=1;i<=n;i++)a[i]*=-1;
            int k=x+x+(y-x)/2;
            int pr=(y-x)/2;
            cout<<k<<endl;
            int l=1,r=1;
            vector<pair<int,int>>ans;
            while(r<=n)
            {
                if(a[l]==-1)
                {
                    ans.push_back({l,l});
                    l++;
                    if(r<l)r=l;
                }
                else if(a[l]==1)
                {
                    if(r==l && r==n)
                    {
                        ans.push_back({l,l});
                        r++;
                    }
                    else if(r==l && pr>0)
                    {
                        r++;
                    }
                    else if(r==l && pr==0)
                    {
                        ans.push_back({l,l});
                        l++;
                        if(l>r)r=l;
                    }
                    else 
                    {
                        if(a[r]==1)
                        {
                            ans.push_back({l,r});
                            pr--;
                            r++;
                            l=r;
                        }
                        else if(a[r]==-1)
                        {
                            ans.push_back({l,l});
                            l++;
                        }
                    }
                }
            }
            if(pr==0)
            {
                for(auto&u : ans)cout<<u.first<<" "<<u.second<<endl;
            }
            else cout<<-1<<endl;
        }
    }
    return 0;
}


