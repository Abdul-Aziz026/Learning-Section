// Total Coprime Pair Finding Code ... 
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e6+2 ; 
vector <int> di[N] ; 
bool vis[N] ; 

void devisors(int n) {
    for (int i=2;i<=n;++i) {
        if (!vis[i]) {
            for (int j=i;j<=n;j+=i) {
                di[j].push_back(i) ; 
                vis[j] = true ; 
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int l, r, gcd_greater_than_1 = 0 ; 
    cin >> l >> r ; 
    devisors(r) ; 
    for (int i=max(2LL, l);i<=r;++i) {
        vector <int> &cur = di[i] ; 
        int n = cur.size(), cnt = 0 ; 
        
        // Inclusion Exclusion part....
        for (int b=1;b<(1<<n);++b) {
            int c = 0, x = 1 ; 
            for (int j=0;j<n;++j) {
                if (b>>j&1) {
                    x *= cur[j] ; 
                    c++ ; 
                }
            }
            if (c&1) cnt += (r/x) - ((i-1)/x) ; 
            else cnt -= (r/x) - ((i-1)/x) ; 
        }
        cnt += cnt-1 ; 
        gcd_greater_than_1 += cnt ; 
    }
    int total_pair = (r-l+1) * (r-l+1) ; 
    int Coprime_pair = total_pair - gcd_greater_than_1 ; 
    //
    cout << Coprime_pair << endl ; 
    return 0;
}

