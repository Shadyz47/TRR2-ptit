#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,s,t;
vector<ii> ke[1005];
vector<vector<int>> res;
vector<ii> res1;
int a[1005][1005];
int vis[1005];
vector<int> path;

void nhap() {
    cin >> n >> s >> t;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j] != 0 && a[i][j] != 10000) {
                ke[i].push_back({j,a[i][j]});       // {ke, trong so}
            }
        }
    }
}

void Dijkstra() {
    priority_queue<ii,vector<ii>,greater<ii>> pq;   //first: duong di min, second : dinh
    pq.push({0,s});
    vector<int> d(n+1,1e9);
    vector<int> parent(n+1,-1);

    d[s] = 0;

    while (!pq.empty()) {
        ii top = pq.top(); pq.pop();

        int dis = top.first;
        int u = top.second;

        if (dis > d[u]) continue;

        for (ii e : ke[u]) {
            int v = e.first;        //dinh ke
            int w = e.second;       //trong so

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u;
                pq.push({d[v],v});
            }
        }
    }

    if (d[t] == 1e9) {
        cout << 0 << endl;
        return;
    }

    cout << d[t] << endl;
    int cur = t;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(),path.end());

    for (int x : path) {
        cout << x << " ";
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

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    nhap();
    Dijkstra();
}

