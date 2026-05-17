// In the Name of ALLAH, the most gracious, the most merciful
// Watch the solve video on -> youtube.com/@CodeConnectt 
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long
#define vl vector<ll>
#define cy cout<<"YES"<<nl
#define cn cout<<"NO"<<nl
#define all(v) (v).begin(),(v).end()
#define si(v) int((v).size())
#define pb push_back
const ll inf = 1e9;
const ll AVIR = 1e18;
const ll mod = 998244353;
const ll Big = 2e5 + 5;
#ifndef ONLINE_JUDGE
#define dis(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _dbg(const char* n, T&& v) {cerr<<n<<" = "<<v<<'\n';}
template <typename T, typename... A>
void _dbg(const char*n,T&& v,A&&... a){const char*c=strchr(n+1,',');
    cerr.write(n,c-n)<<" = "<<v<<" | ";_dbg(c+1, a...); }
#else
#define dis(...)
#endif
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    size_t operator()(long long x)const{static const uint64_t FIXED_RANDOM=
        chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
//..................................................................................................

void solve() {
    ll n,a,b,k;cin>>n>>a>>b>>k;

    if(n<=3)
    {
        cout<<1<<nl;
        return;
    }
    
    ll f=abs(a-b);
    ll cir;
    if(f<n-f)
    {
        cir=f;
    }
    else{
        cir=n-f;
    }

    cout<<cir+k<<nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        //cout << "Case " << tc << ": ";
        solve();
    }
 return 0;
}
