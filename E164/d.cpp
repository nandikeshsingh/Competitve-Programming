#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod = (int) 998244353;
struct mint {
	int value;
	static const int MOD_value = mod;
 
	mint(long long v = 0) { value = v % mod; if (value < 0) value += mod;}
	mint(long long a, long long b) : value(0){ *this += a; *this /= b;}
 
	mint& operator+=(mint const& b) {value += b.value; if (value >= mod) value -= mod; return *this;}
	mint& operator-=(mint const& b) {value -= b.value; if (value < 0) value += mod; return *this;}
	mint& operator*=(mint const& b) {value = (long long)value * b.value % mod; return *this;}
 
	static mint mexp(mint a, long long e) {
		mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
	}
	static mint inverse(mint a) { return mexp(a, mod - 2); }
 
	mint& operator/=(mint const& b) { return *this *= inverse(b); }
	friend mint operator+(mint a, mint const b) { return a += b; }
	friend mint operator-(mint a, mint const b) { return a -= b; }
	friend mint operator-(mint const a) { return 0 - a; }
	friend mint operator*(mint a, mint const b) { return a *= b; }
	friend mint operator/(mint a, mint const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.value;}
	friend bool operator==(mint const& a, mint const& b) {return a.value == b.value;}
	friend bool operator!=(mint const& a, mint const& b) {return a.value != b.value;}
}; 
int n;
vector<int>a;
signed main()
{
    speed;
    cin>>n;
    a.resize(n+1,0);
    int tot=0;
    for(int i=1;i<=n;i++)cin>>a[i],tot+=a[i];
    sort(all(a));
    // cout<<get(0,0,0)<<endl;
    mint dp[n+1][tot+1];
    memset(dp,0,sizeof(dp));
   
    // for(int i=0;i<=n;i++)dp[i][0]=1;
    dp[0][0]=1;
    mint ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=tot;j>=0;j--)
        {
            dp[i][j]+=dp[i-1][j];
            if(j+a[i]<=tot)
            {
                ans+=dp[i][j]*(max((j+a[i]+1)/2,a[i]));
                dp[i][j+a[i]]+=dp[i][j];
            }
            // if(j>=a[i])
            // {
            //     dp[i][j]+=dp[i-1][j-a[i]];
            //     int val=max(a[i],(j+1)/2);
            //     ans+=val*dp[i][j];
            // }
            // dp[i][j]+=dp[i-1][j];
        }
    }
  
    cout<<ans<<endl;
    return 0;
}