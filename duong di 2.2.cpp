#include <bits/stdc++.h>
#define ll long long
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

const int MOD = 1e9 + 7;
using namespace std;

int n,u,v;
vector<int> ke[1005];
int a[1005][1005];
int b[1005][1005];
int bacRa[1005];
int bacVao[1005];
vector<iii> ans;
vector<pair<int,int>> res;
vector<vector<int>> res2;
vector<int> path;
int vis[1005];
int parent[1005];
bool found;
int cnt = 0;

void nhap() {
    cin >> n >> u >> v;
    for (int i =1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back(j);
            }
        }
    }
}

// void DFS(int u,int target) {
//     vis[u] = 1;
//     if (u == target) {
//         found = true;
//         return;
//     }
//     for (int v : ke[u]) {
//         if (!vis[v]) {
//             parent[v] = u;
//             DFS(v,target);
//         }
//     }
// }

void BFS(int u, int target) {
    queue<int> qe;
    qe.push(u);
    vis[u] = 1;

    while (!qe.empty()) {
        int x = qe.front(); qe.pop();

        if (x == target) {
            found = true;
            return;
        }

        for (int y : ke[x]) {
            if (!vis[y]) {
                parent[y] = x;
                qe.push(y);
                vis[y] = 1;
            }
        }
    }
}

//do dai duong di = 2
void solve1() {
    for (int x : ke[u]) {
        for (int y : ke[x]) {
            if (y == v) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

void solve2() {
    BFS(u,v);

    if (!found) {
        cout << 0 << endl;
    }
    else {
        int cur = v;
        while (u != cur) {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(u);
        reverse(path.begin(), path.end());
    }

    for (auto it : path) {
        cout << it << " ";
    }
    cout << endl;
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
    int t; cin >> t;
    nhap();
    if (t==1) {
       solve1();
    }
    else if (t==2) {
        solve2();
    }

}

