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
vector<int> res;
vector<vector<int>> res2;
vector<int> path;
int vis[1005];
int parent[1005];
bool found;
int cnt = 0;

void nhap() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back(j);
            }
        }
    }
}

void DFS(int u,vector<int> &tmp) {
    vis[u] = 1;
    tmp.push_back(u);
    for (int v: ke[u]) {
        if (!vis[v]) {
            DFS(v,tmp);
        }
    }
}

void tplt() {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            vector<int> tmp;
            DFS(i,tmp);
            res2.push_back(tmp);
            cnt++;
        }
    }

    cout << cnt << endl;
    for (auto it : res2) {
        sort(it.begin(),it.end());
        for (int x : it) {
            cout << x << " ";
        }
        cout << endl;
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
    tplt();

}

