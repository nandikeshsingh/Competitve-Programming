#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int MOD = 998244353;

// Function to calculate (x ^ p) % MOD in O(log p)
// Limits: x -> [INT64_MIN, INT64_MAX], p -> [0, INT64_MAX]

int mod_expo(int x, int p, int mod = MOD) {
    int res = 1;
    x = ((x % mod) + mod) % mod;
    while (p > 0) {
        if (p & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
}

// Function to calculate y such that (x * y) % MOD = 1
// Requirements: MOD is prime
// Limits: x -> [INT64_MIN, INT64_MAX]

int mod_inv(int x, int mod = MOD) {
    return mod_expo(x, mod - 2, mod);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < w; j++) {
            grid[i][j] = (row[j] == '#');
        }
    }
    vector<vector<int>> component(h, vector<int>(w, 0));

    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w;
    };

    vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    function<void(int, int, int)> dfs;
    dfs = [&](int x, int y, int curcol) {
        component[x][y] = curcol;
        for(auto ne : dirs) {
            int nex = x + ne.first;
            int ney = y + ne.second;
            if(is_valid(nex, ney) && grid[nex][ney] && !component[nex][ney]) {
                dfs(nex, ney, curcol);
            }
        }
    };

    int cur_component_count = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] && !component[i][j]) {
                dfs(i, j, ++cur_component_count);
            }
        }
    }

    auto get_idx = [&](int x, int y) {
        return x * w + y;
    };

    vector<vector<int>> adj(h * w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j]) {
                for(auto ne : dirs) {
                    int nex = i + ne.first;
                    int ney = j + ne.second;
                    if(is_valid(nex, ney) && grid[nex][ney]) {
                        adj[get_idx(i, j)].push_back(get_idx(nex, ney));
                        adj[get_idx(nex, ney)].push_back(get_idx(i, j));
                    }
                }
            }
        }
    }

    // Articulation point code for cp-algo
    auto calc_articulation = [](int n, vector<vector<int>>& adj) {
        vector<bool> visited;
        vector<int> tin, low;
        int timer;

        map<int, int> articulation_cnt;

        function<void(int, int)> dfs;
        dfs = [&](int v, int p) {
            visited[v] = true;
            tin[v] = low[v] = timer++;
            int children=0;
            for (int to : adj[v]) {
                if (to == p) continue;
                if (visited[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    dfs(to, v);
                    low[v] = min(low[v], low[to]);
                    if (low[to] >= tin[v] && p!=-1)
                        articulation_cnt[v]++;
                    ++children;
                }
            }
            if(p == -1)
                articulation_cnt[v] = children - 1;
        };

        timer = 0;
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs (i, -1);
        }
        return articulation_cnt;
    };

    map<int, int> articulation_cnt = calc_articulation(h * w, adj);


    int sum = 0, cell_cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j]) {
                sum += (cur_component_count + articulation_cnt[get_idx(i, j)]);
                sum %= MOD;
                cell_cnt++;
            }
        }
    }
    cout<<"sum="<<sum<<" cell_cnt="<<cell_cnt<<" cur_component_count="<<cur_component_count<<endl;
    cout << (sum * mod_inv(cell_cnt)) % MOD << "\n";
}