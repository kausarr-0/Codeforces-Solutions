// In the Name of ALLAH, the most gracious, the most merciful
// Watch the solve video on -> youtube.com/@CodeConnectt 
// Created : 2025-10-28 20:54:45
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

const ll N = 1e7;
vector<bool> prime(N + 1, true);
vector<ll>pv;
void sieve()
{
    prime[0] = prime[1] = false;

    for (ll i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            pv.pb(i);
            for (ll j = i * i; j <= N; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void solve() {
    ll n;cin>>n;
    vl v(n);
    ll od=0;
    for(auto &i:v)
    {
        cin>>i;
        if(i&1)
        od++;
    }
    if(od)
    {
        cout<<2<<nl;
        return;
    }
    // set<ll>st;
    // bool ok=1;
    // for(ll i=0;i<n;i++)
    // {
    //     set<ll>p;
    //     for(ll j=2;j*j<=v[i];j++)
    //     {
    //         if(v[i]%j==0)
    //         {
    //             p.insert(j);
    //             while(v[i]%j==0)
    //             v[i]/=j;
    //         }
    //     }
    //     if(v[i]>1)
    //     p.insert(v[i]);

    //     if(ok)
    //     {
    //         st=p;
    //         ok=0;
    //     }
    //     else{
    //         set<ll>stt;
    //         for(auto it:st)
    //         if(p.count(it))
    //         stt.insert(it);

    //         st=stt;

    //     }
    // }
    
    // for(auto &i:pv)
    // {
    //     if(!st.count(i))
    //     {
    //         cout<<i<<nl;
    //         return;
    //     }
    // }


    ll fg=v[0];
    for(ll i=1;i<n;i++)
    {
        fg=gcd(fg,v[i]);

    }
    // dis(fg);
    for(auto &i:pv)
    {
        if(fg%i!=0)
        {
            cout<<i<<nl;
            return;
        }
    }
    if(fg>1)
    cout<<fg<<nl;
    else 
    cout<<-1<<nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    sieve();
    for (int tc = 1; tc <= T; tc++) {
        //cout << "Case " << tc << ": ";
        solve();
    }
 return 0;
}