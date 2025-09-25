// In the Name of ALLAH, the most gracious, the most merciful
// Watch the solve video on -> youtube.com/@CodeConnectt 
// Created : 2025-09-24 19:30:09
#include <bits/stdc++.h>
using namespace std;
#define nl endl
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
// Formula X:
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
#define lbval(v, val) ((lower_bound(all(v),val)!=(v).end())?*lower_bound(all(v),val):-1)
#define lbinx(v, val) (lower_bound(all(v), val) - (v).begin())
ll findIndex(const vector<ll>& v, ll e) { auto it =find(all(v),e);
    if(it!=v.end()){return distance(v.begin(),it);}return -1; }
ll lcm(ll a,ll b) { return(1LL*a*b)/__gcd(a, b); }
ll total_digit(ll x) { return (x == 0 ? 1 : (ll)log10l(x) + 1); }
ll sumFrom_IToJ(ll i,ll j) { return((j - i + 1LL)*(i + j))/2; }
bool sorta_2nd(const pair<int,int>&a,const pair<int,int>&b)
    { return(a.second<b.second); /* Use : sort(all(vec),sorta_2nd);*/ }
bool isPrime(ll n) { if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;
    for(ll i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0)return false;return true; }
bool isPowerOfTwo(ll n) { return(n>0) && (n&(n-1))==0; }

void solve() {
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    vector<ll>v(m);
    unordered_set<ll,custom_hash>bl;
    for(auto &i:v)
    {
        cin>>i;
        bl.insert(i);
    }


    unordered_set<ll,custom_hash>ans;
    
    ll cur=1,blck=1;
    for (ll i = 0; i < n; i++)
    {
        if(s[i]=='A'){
            cur=blck+1;
            blck++;
        }
        else{
            cur=blck;
            while(1){
                cur++;
                if(bl.count(cur))
                continue;
                else {
                    ll next=cur;
                    while(1){
                        next++;
                        if(bl.count(next))
                        continue;
                        else{
                            blck=next;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        bl.insert(cur);
    }
    
    vector<ll>ff(all(bl));
    sort(all(ff));
    cout<<si(ff)<<nl;
    for(auto &i:ff)
    cout<<i<<' ';
    cout<<nl;

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
