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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        map<int,int>mp;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
            if(mp[a[i]]>=3)ok=0;
        }
        if(!ok)cout<<"NO"<<endl;
        else 
        {
            vector<int>mis;
            set<int>st;
            for(int i=0;i<n;i++)st.insert(a[i]);
            for(int i=1;i<=n;i++)
            {
                if(st.count(i)==0)mis.push_back(i);
            }
            if(sz(mis)==0)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<n;i++)cout<<a[i]<<" ";
                cout<<endl;
                for(int i=0;i<n;i++)cout<<a[i]<<" ";
                cout<<endl;
            }
            else 
            {
                sort(all(mis));
                vector<int>x(n),y(n);
                vector<vector<int>>vec(n+1,vector<int>(0));
                for(int i=0;i<n;i++)
                {
                    vec[a[i]].push_back(i);
                }
                bool ok=1;
                for(int i=n;i>=1;i--)
                {
                    if(sz(vec[i])==2)
                    {
                        if(mis.back()>i)
                        {
                            ok=0;
                            break;
                        }
                        else 
                        {
                            x[vec[i][0]]=mis.back();
                            y[vec[i][0]]=i;
                            x[vec[i][1]]=i;
                            y[vec[i][1]]=mis.back();
                            mis.pop_back();
                        }
                    }
                    else if(sz(vec[i])==0)continue;
                    else 
                    {
                        x[vec[i][0]]=i;
                        y[vec[i][0]]=i;
                    }
                }
                if(!ok)cout<<"NO"<<endl;
                else 
                {
                    cout<<"YES"<<endl;
                    for(auto& u : x)cout<<u<<" ";
                    cout<<endl;
                    for(auto& u : y)cout<<u<<" ";
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}


