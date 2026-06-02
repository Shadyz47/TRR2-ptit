#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,m;
vector<ii> ke[1005];
vector<vector<int>> res;
vector<ii> res1;
int a[1005][1005];
int vis[1005];
int parent[1005];
int sz[1005];

struct Edge {
    int u,v,w;
};

vector<Edge> dscanh;

void nhap() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;

        dscanh.push_back({u,v,w});
    }
}

void init() {
    for (int i=1;i<=n;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u ,int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u,v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void Kruskal() {
    vector<Edge> mst;
    ll d = 0;

    stable_sort(dscanh.begin(),dscanh.end(), cmp);

    for (Edge e : dscanh) {
        if (mst.size() == n-1) break;
        if (Union(e.u,e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }

    if (mst.size() < n - 1) {
        cout << 0 << endl;
    }
    else {
        cout << d << endl;
        for (Edge e : mst) {
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
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

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    nhap();
    init();
    Kruskal();
}

