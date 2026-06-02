#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,s;
vector<ii> ke[1005];
vector<vector<int>> res;
vector<ii> res1;
int a[1005][1005];
int vis[1005];

// ii -- {dinh ke, trong so}
// iii -- {trong so, {dinh nho hon, dinh lon hon}}

struct Edge {
    int u,v,w;
};

void nhap() {
    cin >> n >> s;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back({j,a[i][j]});
            }
        }
    }
}

void Prim(int s) {
    vis[s] = 1;
    priority_queue<iii, vector<iii>,greater<>> pq;

    for (ii it : ke[s]) {
        if (!vis[it.first]) {
            pq.push({it.second, {min(s,it.first), max(s,it.first)}});
        }
    }

    ll d = 0;
    vector<Edge> mst;

    while (!pq.empty()) {
        iii top = pq.top(); pq.pop();

        int w = top.first;
        int u = top.second.first;
        int v = top.second.second;

        if (vis[u] && vis[v]) continue;

        int next = vis[u] ? v : u;
        vis[next] = 1;
        d += w;
        mst.push_back({u,v,w});

        for (ii it : ke[next]) {
            if (!vis[it.first]) {
                pq.push({it.second, {min(next,it.first), max(next,it.first)}});
            }
        }
    }

    if (mst.size() < n - 1) {
        cout << 0 << endl;
    }
    else {
        cout << d << endl;
        for (int i=0;i<mst.size();i++) {
            cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);
//
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    nhap();
    Prim(s);
}

