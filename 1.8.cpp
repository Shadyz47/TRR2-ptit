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
    cin >> m;
    for (int i=0;i<m;i++) {
        int x,y; cin >> x >> y;

        bacRa[x]++;
        bacRa[y]++;
    }
}

void nhap2() {
    for (int i=1;i<=n;i++) {
        int x; cin >> x;
        bacRa[i] = x;
        for (int j=1;j<=x;j++) {
            int y; cin >> y;
            a[i][y] = a[y][i] =  1;
        }
    }
}

void solve() {
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if (a[i][j]) {
                ans.push_back({i,j});
            }
        }
    }

    cout << n << " " << ans.size() << endl;

    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0),
            cin.tie(0), cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t >> n;
    if (t==1) {
        nhap2();
        for (int i = 1; i <= n; i++) {
            cout << bacRa[i] << " ";
        }
    }
    else if (t==2) {
        nhap2();
        solve();
    }
}

