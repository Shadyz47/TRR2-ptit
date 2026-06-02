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

void DFS(int u) {
    vis[u] = 1;
    for (int v : ke[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

int tplt() {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

void dinhtru() {
    int cc = tplt();
    for (int i=1;i<=n;i++) {
        memset(vis,0,sizeof(vis));
        vis[i] = 1;
        if (cc < tplt()) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
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
    dinhtru();
}

