#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,s;
vector<int> ke[1005];
vector<vector<int>> res;
int a[1005][1005];
int vis[1005];
int path[1005];
bool ok = false;

void nhap() {
    cin >> n >> s;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j] == 1) {
                ke[i].push_back(j);
            }
        }
    }
}

void DFS(int u,int cnt) {
    if (cnt == n) {

        // for (int i=1;i<=n;i++) {            //duong di
        //     tmp.push_back(path[i]);
        // }

        if (a[u][s] == 1) {                 // chu trinh
            vector<int> tmp;
            for (int i=1;i<=n;i++) tmp.push_back(path[i]);
            tmp.push_back(s);

            res.push_back(tmp);
            ok = true;
        }
        return;
    }

    for (int v : ke[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            path[cnt+1] = v;
            DFS(v,cnt+1);
            vis[v] = 0;
        }
    }
}

void Hamilton() {
    memset(vis,0,sizeof(vis));
    path[1] = s;
    vis[s] = 1;
    DFS(s, 1);
}

int main() {
    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    nhap();
    Hamilton();

    if (!ok) {
        cout << 0 << endl;
    }
    else {
        for (auto it : res) {
            for (int x : it) {
                cout << x << " ";
            }
            cout << endl;
        }

        cout << res.size() << endl;
    }
}

