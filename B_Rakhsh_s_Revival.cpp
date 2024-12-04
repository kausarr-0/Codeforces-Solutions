#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    int cnt = 0,op=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') {
            cnt++;
            
            if (cnt == m) {
                
                for (int j = i; j < min(n,i + k); j++) {
                    s[j] = '1';
                }
                i+=k-1;
                op++;
                cnt=0;
            }
        }
        else cnt = 0;

    }
    cout<<op<<endl;

}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();

}