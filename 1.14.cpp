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
vector<iii> ans;
vector<pair<int,int>> res;

void nhap() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                bacRa[i]++;
                bacVao[j]++;
                res.push_back({i,j});
            }
        }
    }
}

void solve() {
    cout << n << " " << res.size() << endl;

    for (int j = 1;j <= res.size();j++) {
        int u = res[j-1].first;
        int v = res[j-1].second;

        b[u][j] = 1;
        b[v][j] = -1;
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=res.size();j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
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
     // freopen("DT.INP", "r", stdin);
     // freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    nhap();
    if (t==1) {
        for (int i = 1; i <= n; i++) {
            cout << bacVao[i] << " " << bacRa[i] << endl;
        }
        cout << endl;
    }
    else if (t==2) {
        solve();
    }

}

