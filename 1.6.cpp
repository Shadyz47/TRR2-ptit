#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;

int n,m;
vector<int> ke[1005];
vector<pair<int,int>> ans;
int a[1005][1005];
int bacRa[1005];

void nhap() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int x,y; cin >> x >> y;

        ke[x].push_back(y);
        ke[y].push_back(x);
        bacRa[x]++;
        bacRa[y]++;

        ans.push_back({x,y});
    }
}


void solve() {
    cout << n << " " << ans.size() << endl;

    for (int j=1;j<=ans.size();j++) {
        int u = ans[j-1].first;
        int v = ans[j-1].second;
        a[u][j] = a[v][j] = 1;
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=ans.size();j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0),
            cin.tie(0), cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    nhap();
    if (t==1) {
        for (int i = 1; i <= n; i++) {
            cout << bacRa[i] << " ";
        }
        cout << endl;
    }
    else if (t==2) {
        solve();
    }


    return 0;
}

