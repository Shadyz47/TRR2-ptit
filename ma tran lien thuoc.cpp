#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;

int n;
vector<int> ke[1005];
int a[1005][1005];
int b[1005][1005];
int bacRa[1005];

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

vector<pair<int,int>> ans;
void solve() {
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if (a[i][j])
                ans.push_back({i,j});
        }
    }

    cout << n << " " << ans.size() << endl;

    for (int j = 1;j<=ans.size();j++) {
        int u = ans[j-1].first;         //dinh dau
        int v = ans[j-1].second;        //dinh cuoi
        b[u][j] = b[v][j] = 1;
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=ans.size();j++) {
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

