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
        int k;
        cin>>k;
        string god="FBFFBFFB";
        string s;cin>>s;
        int ok=isSubstring(s,god+god+god);
        if(ok==-1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}


