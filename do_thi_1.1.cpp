#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;

int n;
vector<int> ke[1005];
int a[1005][1005];
int bacRa[1005];
int bacVao[1005];

void nhap() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].push_back(j);
                bacRa[i]++;
            }
        }
    }
}

vector<pair<int,int>> vv;
void solve() {
    for (int i=1;i<=n;i++) {
        pair<int,int> p;
        for (int j =i;j<=n;j++) {
            if (a[i][j]) {
                vv.push_back({i,j});
            }
        }
    }

    cout << n << " " << vv.size() << endl;
    for (auto it : vv) {
        cout << it.first << " " << it.second << endl;
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

