#include <bits/stdc++.h>
#define ll long long
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
const int MOD = 1e9 + 7;
using namespace std;

int n;
int a[1005][1005];
vector<int> ke[1005];
vector<iii> ans;
int bac[1005];

void nhap() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j] && a[i][j] != 10000) {
                bac[i]++;
            }
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if (a[i][j] && a[i][j] != 10000) {
                ans.push_back({i,{j,a[i][j]}});
            }
        }
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
        for (int i=1;i<=n;i++) {
            cout << bac[i] << " ";
        }
        cout << endl;
    }
    else if (t==2) {
        cout << n << " " << ans.size() << endl;
        for (auto it : ans) {
            cout << it.first << " " << it.second.first << " " << it.second.second << endl;
        }
    }

    return 0;
}

