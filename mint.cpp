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
