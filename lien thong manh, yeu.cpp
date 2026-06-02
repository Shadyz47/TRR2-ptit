#include <bits/stdc++.h>
#define ll long long
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

const int MOD = 1e9 + 7;
using namespace std;

int n,m;
vector<int> ke[1005];
vector<int> ke2[1005];
vector<int> t_ke[1005];
int a[1005][1005];
int b[1005][1005];
int bacRa[1005];
int bacVao[1005];
int vis[1005];
vector<iii> ans;
vector<pair<int,int>> res;
vector<vector<int>> res2;
stack<int> st;

void nhap() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
             cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back(j);
                t_ke[j].push_back(i);
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

    st.push(u);
}

void DFS2(int u) {
    vis[u] = 1;
    for (int v : t_ke[u]) {
        if (!vis[v]) {
            DFS2(v);
        }
    }
}

void DFS3(int u) {
    vis[u] = 1;
    for (int v : ke2[u]) {
        if (!vis[v]) {
            DFS3(v);
        }
    }
}

bool tplt() {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cnt++;
        }
    }
    return cnt == 1;
}

bool lienthong_manh() {
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            DFS(i);
        }
    }

    memset(vis,0,sizeof(vis));

    int scc = 0;            //if scc == 1 thi la lien thong manh su dung kosaraju
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!vis[u]) {
            scc++;
            DFS2(u);
        }
    }

    if (scc == 1) return true;
    else return false;
}

bool lienthong_yeu() {
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]) {
                b[i][j] = b[j][i] = 1;
            }
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (b[i][j]) {
                ke2[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cnt++;
            DFS3(i);
        }
    }
    return cnt == 1;
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
    if (lienthong_manh()) {
        cout << "1\n";
    }
    else if (lienthong_yeu()) {
        cout << "2\n";
    }
    else {
        cout << "0\n";
    }
}

