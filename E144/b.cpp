#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(a[0]==b[0])
        {
            cout<<"YES"<<endl;
            string ans;
            ans=a.substr(0,1);
            ans+="*";
            cout<<ans<<endl;
        }
        else if(a.back()==b.back())
        {
            cout<<"YES"<<endl;
                        string ans;
            ans=a.substr(sz(a)-1,1);
            reverse(all(ans));
            ans+="*";
            reverse(all(ans));
            cout<<ans<<endl;
        }
        else 
        {
            string ans;
            bool ok=0;
            for(int i=1;i<sz(a);i++)
            {
                string cur=a.substr(i-1,2);
                int ret=isSubstring(cur,b);
                if(ret!=-1)
                {
                    ok=1;
                    ans=cur;
                    break;
                }
            }
            if(ok)
            {
                cout<<"YES"<<endl;
                cout<<'*'+ans+'*'<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


