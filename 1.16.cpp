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
vector<vector<int>> res2;

void nhap() {
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;

        bacRa[x]++;
        bacVao[y]++;
        a[x][y] = 1;
    }
}

void solve() {

    for (int i = 1; i <= n; i++) {
        vector<int> tmp;
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                tmp.push_back(j);
            }
        }
        res2.push_back(tmp);
    }

    cout << res2.size() << endl;
    for (auto it : res2) {
        cout << it.size() << " ";
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
     freopen("DT.INP", "r", stdin);
     freopen("DT.OUT", "w", stdout);
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

