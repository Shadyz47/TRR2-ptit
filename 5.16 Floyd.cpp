#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n;
vector<ii> ke[1005];
vector<vector<int>> res;
vector<ii> res1;
int a[1005][1005];
int vis[1005];
int d[1005][1005];
int parent[1005][1005];
vector<int> path;

void nhap() {
    cin >> n;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            else {
                d[i][j] = 1e9;
            }
            parent[i][j] = j;
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j] != 0 && a[i][j] != 10000) {
                d[i][j] = a[i][j];
            }
        }
    }
}

void Floyd() {
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (d[i][k] < 1e9 && d[k][j] < 1e9 && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    parent[i][j] = parent[i][k];
                }
            }
        }
    }
}

void solve(int u,int v) {
    if (u == -1 || v == -1 || d[u][v] == 1e9) {
        cout << "0\n";
        return;
    }

    cout << d[u][v] << "\n";
    int cur = u;
    cout << cur << " ";
    while (cur != v) {
        cur = parent[cur][v];
        cout << cur << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    nhap();
    Floyd();

    int best_u = -1, best_v = -1;
    int max_dist = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && d[i][j] != 1e9) {
                if (d[i][j] > max_dist) {
                    max_dist = d[i][j];
                    best_u = i;
                    best_v = j;
                }
            }
        }
    }

    cout << best_u << " " << best_v << " ";
    solve(best_u,best_v);
}

