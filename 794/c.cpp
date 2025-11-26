#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        if(n%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(vec.begin(),vec.end());
        vector<int>has;
        int s=0,e=n-1;
        bool turn=0;
        while(s<=e)
        {
            if(turn==0)
            {
                has.push_back(vec[s]);
                s++;
                turn=1;
            }
            else
            {
                has.push_back(vec[e]);
                e--;
                turn=0;
            }
        }
        // cout<<"Printing has before"<<endl;
        // for(auto& u : has)cout<<u<<" ";
        // cout<<endl;
        int last=has[n-1];
        int first=has[0];
        has.push_back(first);
        reverse(has.begin(),has.end());
        has.push_back(last);
        reverse(has.begin(),has.end());
        // cout<<"Printing has"<<endl;
        // for(auto& u : has)cout<<u<<" ";
        // cout<<endl;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(has[i]>has[i-1] && has[i]>has[i+1])continue;
            if(has[i]<has[i-1] && has[i]<has[i+1])continue;
            ok=0;
        }
        if(ok)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<has[i]<<" ";
            cout<<endl;
        }
        else 
        {
            has.clear();
            assert(has.size()==0);
            int s=0,e=n-1;
            bool turn=0;
            while(s<=e)
            {
                if(turn==1)
                {
                    has.push_back(vec[s]);
                    s++;
                    turn=0;
                }
                else
                {
                    has.push_back(vec[e]);
                    e--;
                    turn=1;
                }
            }
            int last=has[n-1];
            int first=has[0];
            has.push_back(first);
            reverse(has.begin(),has.end());
            has.push_back(last);
            reverse(has.begin(),has.end());
            bool ok=1;
            for(int i=1;i<=n;i++)
            {
                if(has[i]>has[i-1] && has[i]>has[i+1])continue;
                if(has[i]<has[i-1] && has[i]<has[i+1])continue;
                ok=0;
            }
            if(ok)
            {
                cout<<"YES"<<endl;
                for(int i=1;i<=n;i++)cout<<has[i]<<" ";
                cout<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

