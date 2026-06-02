#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,pair<int,int>>
const int MOD = 1e9 + 7;
using namespace std;

int n,m;
multiset<int> ke[1005];
vector<int> ke_vo_huong[1005];
vector<int> res;
int a[1005][1005];
int bacRa[1005];
int bacVao[1005];
int vis[1005];

void nhap1() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].insert(j);

                bacRa[i]++;
                bacVao[j]++;

                ke_vo_huong[i].push_back(j);
                ke_vo_huong[j].push_back(i);
            }
        }
    }
}

void nhap2() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                ke[i].insert(j);
            }
        }
    }
}

void DFS(int u) {
    vis[u] = 1;
    for (int v : ke_vo_huong[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

bool tplt() {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cnt++;
            DFS(i);
        }
    }
    return cnt == 1;
}

bool check_bac1() {
    for (int i=1;i<=n;i++) {
        if (bacRa[i] != bacVao[i]) return false;
    }
    return true;
}

bool check_bac2() {
    int cnt = 0;
    int cnt2 = 0;
    for (int i=1;i<=n;i++) {
        if (abs(bacRa[i] - bacVao[i]) == 1) cnt++;
        else if (bacRa[i] == bacVao[i]) cnt2++;
    }
    return cnt == 2 && cnt + cnt2 == n;
}

void Euler(int u) {
    stack<int> st;
    vector<int> EC;
    st.push(u);

    while (!st.empty()) {
        int x = st.top();

        if (!ke[x].empty()) {
            int y = *ke[x].begin();
            st.push(y);

            ke[x].erase(ke[x].find(y));
            //ke[y].erase(ke[y].find(x));
        }
        else {
            st.pop();
            EC.push_back(x);
        }
    }

    reverse(EC.begin(),EC.end());
    for (int it : EC) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    int t; cin >> t;
    if (t == 1) {
        nhap1();
        bool ok = tplt();

        if (ok && check_bac1()) {
            cout << 1 << endl;
        }
        else if (ok && check_bac2()) {
            cout << 2 << endl;
        }
        else cout << 0 << endl;
    }
    else if (t==2) {
        nhap2();
        Euler(m);
    }

    return 0;
}

