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
        string a,b;
        cin>>a>>b;
        vector<pair<int,int>>ans;
        int cnt=0;
        bool s=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])s=0;
        }
        bool c=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])c=0;
        }
        if(c)
        {
            ans.push_back({1,n});
            cnt++;
            for(int i=0;i<n;i++)
            {
                if(a[i]=='1')a[i]='0';
                else a[i]='1';
            }
            s=1;
        }
        if(s)
        {
            cout<<"YES"<<endl;
            int pos=-1;
            for(int i=0;i<n;i++)
            {
                if(a[i]=='0' && b[i]=='0')
                {
                    pos=i;
                    break;
                }
            }
            if(pos==-1)
            {
                cout<<2<<endl;
                cout<<1<<" "<<1<<endl;
                cout<<2<<" "<<n<<endl;
            }
            else 
            {
                int l=pos,r=pos;
                bool f=0;
                int tot=0;
                for(int i=r+1;i<n;i++)
                {
                    if(a[i]!=a[i-1])
                    {
                        if(!f)
                        {
                            ans.push_back({l+1,i});
                            // ans.push_back({1,n});
                            cnt++;
                            f=1;
                        }
                        else 
                        {
                            ans.push_back({1,i});
                            // ans.push_back({1,n});
                            cnt++;          
                        }
                        tot++;
                    }
                }
                bool done=0;
                if(!f && l>0)
                {
                    cnt++;
                    ans.push_back({l+1,r+1});
                    tot++;
                    // done=1;
                    // ans.push_back({1,n});
                }
                if(tot%2)
                {
                    ans.push_back({1,n});
                    cnt++;
                }
                assert(cnt<=n+5);
                cout<<cnt<<endl;
                for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
            }
        }
        else 
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

