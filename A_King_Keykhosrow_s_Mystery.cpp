/* In the Name of ALLAH, the most gracious, the most merciful  */
#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define ll long long
#define cy cout<<"YES"<<nl
#define cn cout<<"NO"<<nl
#define dis(x) cerr<<#x<<" = "<<x<<nl
#define all(v) (v).begin(),(v).end()
#define si(v) int((v).size())
#define pb push_back
const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
/* Formula X:
 * Sum of 'i to j' = ((j-i+1)*(i+j))/2;
 * LCM = (a*b)/__gcd(a,b);      
 * 
 *  --*/

void solve() {
    ll a,b;cin>>a>>b;
    if(a>b)
    swap(a,b);

    ll ans=(a*b)/__gcd(a,b);
    cout<<ans<<nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
 return 0;
}