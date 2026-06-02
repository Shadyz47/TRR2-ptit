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
int bac[1005];
vector<iii> ans;

void nhap() {
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        int x,y,w; cin >> x >> y >> w;
        bac[x]++;
        bac[y]++;
        ans.push_back({x,{y,w}});

        a[x][y] = w;
        a[y][x] = w;
    }
}

void solve() {
    cout << n << endl;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i == j) cout << 0 << " ";
            else if (a[i][j]) {
                cout << a[i][j] << " ";
            }
            else cout << 10000 << " ";
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
            cout << bac[i] << " ";
        }
        cout << endl;
    }
    else if (t==2) {
        solve();
    }

}

