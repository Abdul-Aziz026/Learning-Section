// All pair sortest path...
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int inf = 1e14 ; 

int ar[505][505] ; 

void Min(int &a, int b) {
    if (b<a) a = b ; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int n, m ; 
    cin >> n >> m ; 
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            ar[i][j] = inf ; 
            if (i==j) ar[i][j] = 0 ; 
        }
    }
    int x, y, c ; 
    for (int i=1;i<=m;++i) {
        cin >> x >> y >> c ; 
        ar[x][y] = c ; 
    }
    // algorithm main part
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                Min(ar[i][j], ar[i][k] + ar[k][j]) ; 
            }
        }
    }
    //query section
    int q; cin >> q ; 
    while (q--) {
        int u, v; cin >> u >> v ; 
        cout << ar[u][v] << endl ; 
    }
    return 0;
}

