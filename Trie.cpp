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


//for numbers

const int M=(2e5+1)*30;//as per the problem
const int A=2;
struct Trie
{
    int n=0;
    int t[M][A]={};
    int pre[M]={};
    void init()
    {
        for(int i=0;i<M;i++)
        for(int j=0;j<A;j++)
        t[i][j]=-1;
        
    }
    void add(int x)
    {
        int p=0;
        pre[p]++;
        for(int i=29;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(t[p][b]==-1)
            {
                t[p][b]=++n;
            }
            p=t[p][b];
            pre[p]++;
        }
    }
    void remove(int x)
    {
        int p=0;
        for(int i=29;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(pre[t[p][b]]>1)
            {
                p=t[p][b];
                pre[p]--;
            }
            else 
            {
                pre[t[p][b]]--;
                int nn=t[p][b];
                t[p][b]=-1;
                p=nn;
            }
        }
    }
    int getmax_xor(int x)
    {
        int p=0;
        int ret=0;
        for(int i=29;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(t[p][b]!=-1 && t[p][b^1]!=-1)
            {
                ret|=(1<<i);
                p=t[p][b^1];
            }
            else if(t[p][b]==-1 && t[p][b^1]==-1)
                break;
            else if(t[p][b]==-1 && t[p][b^1]!=-1)
            {
                p=t[p][b^1];
                ret|=(1<<i);
            }
            else 
            {
                p=t[p][b];
            }
        }
        return ret;
    }
};
