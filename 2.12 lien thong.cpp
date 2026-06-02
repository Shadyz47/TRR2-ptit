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
int bacRa[1005];
int bacVao[1005];
int vis[1005];
vector<iii> ans;
vector<pair<int,int>> res;
vector<vector<int>> res2;

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

void BFS(int u,vector<int> &tmp) {
    queue<int> qe;
    qe.push(u);
    vis[u] = 1;
    tmp.push_back(u);

    while (!qe.empty()) {
        int x = qe.front();
        qe.pop();

        for (int y : ke[x]) {
            if (!vis[y]) {
                tmp.push_back(y);
                vis[y] = 1;
                qe.push(y);
            }
        }
    }
}

void tplt() {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            vector<int> tmp;
            BFS(i,tmp);
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

