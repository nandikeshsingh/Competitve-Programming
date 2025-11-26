#include<bits/stdc++.h>
#define int long long
using namespace std;
string leftrotate(string s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
    return s;
}
int gcd( int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)cin>>p[i];
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='#')continue;
            else 
            {
                int st=i+1;
                int again=st;
                string cur;
                while(1)
                {
                    // cout<<"inside"<<endl;
                    cur+=s[st-1];
                    s[st-1]='#';
                    st=p[st];
                    if(st==again)break;
                }
                // cout<<"cur="<<cur<<endl;
                string god=cur;
                
                int cnt=0;
                while(1)
                {
                    cur=leftrotate(cur,1);
                    cnt++;
                    if(cur==god)break;
                }
                ans=lcm(ans,cnt);
                // cout<<"now = "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
