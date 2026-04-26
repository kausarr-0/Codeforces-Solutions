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
const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int Big = 2e5 + 5;
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

ll sum(vl &v,ll cnt)
{
    if(cnt==0 || v.empty())
    return 0;

    ll p=0;
    for(auto &i:v)
    {
        if(i>0)
        p++;
    }
    ll nibo=0;
    if(p>0)
    {
        nibo=min(p,cnt);
    }
    else nibo=1;

    ll s=0;
    for(ll i=0;i<nibo;i++)
    s+=v[i];

    return s;

}

void solve() {
    ll n,m;cin>>n>>m;
    vl a(n),x(m);
    for(auto &i:a)
    cin>>i;

    vl e,o;

    for(ll i=0;i<n;i++)
    {
        if(i&1)
        e.pb(a[i]);
        else o.pb(a[i]);
    }
    
    sort(all(e),greater<>());
    sort(all(o),greater<>());
    
    ll cnto=0,cnte=0;
    for(auto &i:x)
    {
        cin>>i;
        if(i&1)
        cnto++;
        else cnte++;
    }
    
    // dis(cnto,cnte);

    // for(auto &i:e)
    // cout<<i<<' ';
    // cout<<nl;
    ll t=accumulate(all(a),0LL);

    ll baad=sum(o,cnto)+sum(e,cnte);
    // dis(t,baad);

    cout<<t-baad<<nl;


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
