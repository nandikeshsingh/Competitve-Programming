#include<bits/stdc++.h>
// #define int long long
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
        string s;
        cin>>s;
        int n=(int)s.length();
        multiset<pair<int,int>>ms;
        for(int i=0;i<n;i++)
        {
            int num=int(s[i])-48;
            ms.insert({num,i});
        }
        vector<int>vec,ex;
        int last=-1;
        for(auto& u : ms)
        {
            if(u.second>last)
            {
                vec.push_back(u.first);
                last=u.second;
            }
            else vec.push_back(min(u.first+1,9));
        }
        sort(all(vec));
        // cout<<"vec"<<endl;
        // for(auto& u : vec)cout<<u<<" ";
        // cout<<endl;
        //  cout<<"ex"<<endl;
        // for(auto& u : ex)cout<<u<<" ";
        // cout<<endl;       
        string str;
        for(auto& u : vec)str+=to_string(u);
        cout<<str<<endl;
        // sort(all(ex));
        // for(auto& u : ex)str+=char(u);
        // cout<<str<<endl;
    }
    return 0;
}


