#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s,t;
    cin>>s>>t;
    transform(t.begin(), t.end(), t.begin(), ::tolower); 
    if(t.back()=='x')t.pop_back();
    bool ok=0;
    int j=0;
    for(int i=0;i<s.length();i++)
    {
        if(j>=t.length())break;
        if(s[i]==t[j])j++;
    }
    if(j==t.length())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


