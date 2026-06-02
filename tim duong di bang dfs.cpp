#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;

int n,m,u,v;
vector<int> ke[1001];
int visited[1001];
int a[1005][1005];
int res[1005][1005];

void nhap() {
    cin >> n >> m >> u >> v;
    memset(visited, 0, sizeof(visited));
    for (int i=0;i<1001;i++) ke[i].clear();
    for (int i=0;i<m;i++) {
        int x,y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

vector<int> ve;
bool found = false;
void dfs(int u) {
    ve.push_back(u);
    visited[u] = 1;

    if (u == v) {
        found = true;
        return;
    }
    for (int v : ke[u]) {
        if (!visited[v] && !found) {
            dfs(v);
        }
    }

    if (!found) {
        ve.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0),
            cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t ; cin >> t;
    if (t == 1) {
        cin >> n >> m >> u >> v;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }

        memset(res, 0, sizeof(res));
        for (int i=1;i<=n;i++) {
            for (int j =1;j<=n;j++) {
                for (int k =1;k<=n;k++) {
                    res[i][j] += a[i][k] * a[k][j];
                }
            }
        }

        int ans = 0;
        for (int i = 1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (res[i][j] != 0) {
                    ans += res[i][j];
                }
            }
        }

        cout << ans << endl;
    }
    else if (t == 2) {
        nhap();
        dfs(u);

        if (!found) {
            cout << 0 << endl;
        }
        else {
            for (int x : ve) {
                cout << x << " ";
            }
        }
    }

    return 0;
}

