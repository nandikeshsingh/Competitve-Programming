//M is the max length of the string to be inserted.
//A is the total number of distinct charaters.
struct Trie {
    int G = 0;
    int t[M][A] = {};
    int f[M] = {};
 
    void add(const string& s) {
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
 
            if (!t[x][c]) {
                t[x][c] = ++G;
            }
 
            x = t[x][c];
            f[x] += 1;
        }
    }
 
    int get(const string& s) {
        int x = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
 
            if (!t[x][c]) {
                break;
            }
 
            x = t[x][c];
            res += f[x];
        }
        return res;
    }
};
