#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,s;
vector<int> ke[1005];
vector<vector<int>> res;
vector<ii> res1;
int a[1005][1005];
int vis[1005];
int path[1005];
bool ok = false;

void nhap() {
    cin >> n >> s;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back(j);
            }
        }
    }
}

void DFS(int u) {
    vis[u] = 1;
    for (int v : ke[u]) {
        if (!vis[v]) {
            res1.push_back({u,v});
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> qe;
    qe.push(u);
    vis[u] = 1;

    while (!qe.empty()) {
        int x = qe.front(); qe.pop();

        for (int y : ke[x]) {
            if (!vis[y]) {
                res1.push_back({x,y});
                vis[y] = 1;
                qe.push(y);
            }
        }
    }
}

void solve1() {
    DFS(s);

    bool ok = true;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            ok = false;
            break;
        }
    }

    if (!ok) cout << 0 << endl;
    else {
        cout << res1.size() << endl;

        int cnt = 0;
        for (auto it : res1) {
            cout << min(it.first, it.second) << " " << max(it.first, it.second) << endl;// chu y 
            cnt++;

            if (cnt == n-1) {
                break;
            }
        }
    }
}

void solve2() {
    BFS(s);

    bool ok = true;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            ok = false;
            break;
        }
    }

    if (!ok) cout << 0 << endl;
    else {
        cout << res1.size() << endl;

        int cnt = 0;
        for (auto it : res1) {
            cout << min(it.first, it.second) << " " << max(it.first, it.second)  << endl;   //chu y
            cnt++;

            if (cnt == n-1) {
                break;
            }
        }
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
    
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    int t; cin >> t;
    nhap();
    if (t==1) {
        solve1();
    }
    else if (t==2) {
        solve2();
    }
}

