#include <bits/stdc++.h>
#define ll long long
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

const int MOD = 1e9 + 7;
using namespace std;

int n,m;
vector<int> ke[1005];
int a[1005][1005];
int b[1005][1005];
int vis[1005];
vector<int> ans;
vector<pair<int,int>> res;
vector<ii> dscanh;
vector<vector<int>> res2;

void nhap() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back(j);

                if (i < j) {
                    dscanh.push_back({i,j});
                }
            }
        }
    }
}

void DFS(int u,int x, int y) {
    vis[u] = 1;
    for (int v : ke[u]) {

        if ((u == x && v == y) || (u == y && v == x))
            continue;

        if (!vis[v]) {
            DFS(v,x,y);
        }
    }
}

void BFS(int u,int x,int y) {
    queue<int> qe;
    vis[u] = 1;
    qe.push(u);

    while (!qe.empty()) {
        int v = qe.front();
        qe.pop();

        for (int k : ke[v]) {

            if ((v == x && k == y) || (v == y && k == x))
                continue;

            if (!vis[k]) {
                qe.push(k);
                vis[k] = 1;
            }
        }
    }
}

void canhcau() {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cnt++;
            BFS(i,0,0);
        }
    }

    vector<ii> canhCau;
    for (auto it : dscanh) {
        int x = it.first;
        int y = it.second;

        memset(vis,0,sizeof(vis));

        int dem = 0;
        for (int i=1;i<=n;i++) {
            if (!vis[i]) {
                dem++;
                BFS(i,x,y);
            }
        }

        if (dem > cnt) canhCau.push_back({x,y});
    }

    if (canhCau.size() > 0) {
        cout << canhCau.size() << endl;
        sort(canhCau.begin(), canhCau.end());
        for (auto it : canhCau) {
            cout << it.first << " " << it.second << endl;
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
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    nhap();
    canhcau();
}

