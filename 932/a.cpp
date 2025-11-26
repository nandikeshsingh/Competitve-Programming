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
        int n;cin>>n;string s;cin>>s;
        string rev=s;
        reverse(all(rev));
        int l=-1;
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]<s[j])
            {
                l=1;
                break;
            }
            else if(s[i]==s[j])
            {
                i++,j--;
            }
            else 
            {
                l=0;
                break;
            }
        }
        if(l==-1)l=1;
        if(l)
        {
            if(n%2)
            {
                s+=rev;
                cout<<s<<endl;
            }
            else cout<<s<<endl;
        }
        else 
        {
            if(n%2)
            {
                cout<<rev<<endl;
            }
            else 
            {
                rev+=s;
                cout<<rev<<endl;
            }
        }
    }

    return 0;
}


