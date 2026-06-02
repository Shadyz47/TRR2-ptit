#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,s,t;
vector<ii> ke[1005];
vector<vector<int>> res;
vector<ii> res1;
int a[1005][1005];
int vis[1005];
int d[1005];
int parent[1005];
vector<int> path;

struct Edge {
    int u,v,w;
};

vector<Edge> dscanh;

void nhap() {
    cin >> n >> s >> t;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j] != 0 && a[i][j] != 10000) {
                dscanh.push_back({i,j,a[i][j]});
            }
        }
    }
}

bool BellmanFord() {
    for (int i=1;i<1005;i++) {
        d[i] = 1e9;
    }
    d[s] = 0;

    for (int i=1;i<=n-1;i++) {
        bool updated = false;
        for (Edge e : dscanh) {
            if (d[e.u] < 1e9 && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                parent[e.v] = e.u;
                updated = true;
            }
        }

        if (!updated) break;
    }

    //ktra chu trinh am
    for (Edge e : dscanh) {
        if (d[e.u] < 1e9 && d[e.v] > d[e.u] + e.w) {
            return false;
        }
    }

    return true;
}

void solve() {
    if (d[t] == 1e9) {
        cout << 0 << endl;
        return;
    }

    cout << d[t] << endl;
    int cur = t;
    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    for (int x : path) {
        cout << x << " ";
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

    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    nhap();
    if (BellmanFord()) {
        solve();
    } else {
        cout << -1 << endl;
    }
}

