/* In the Name of ALLAH, the most gracious, the most merciful  */
/* Watch the solve video on -> youtube.com/@MythologicalCoding */
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
const int Big = 2e5 + 5;
// Formula X:
ll findIndex(const vector<ll>& v, ll e) { auto it =find(all(v),e);
    if(it!=v.end()){return distance(v.begin(),it);}return -1; }
ll gcd(ll a,ll b) { if(b==0)return a;return gcd(b,a%b); }//__gcd 
ll lcm(ll a,ll b) { return(1LL*a*b)/__gcd(a, b); }
ll total_digit(ll i) { ll m = log10(i) + 1; return m; }
ll sumFrom_IToJ(ll i,ll j) { return((j - i + 1LL)*(i + j))/2; }
bool sorta_2nd(const pair<int,int>&a,const pair<int,int>&b)
    { return(a.second<b.second); /* Use : sort(all(vec),sorta_2nd);*/ }
bool isPrime(ll n) { if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;
    for(ll i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0)return false;return true; }
bool isPowerOfTwo(ll n) { return(n>0) && (n&(n-1))==0; }

void solve() {
    ll n,k;cin>>n>>k;
    vector<ll>v(n),vv(n);
    vector<pair<ll,ll>>p(n);

    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        p[i].first=v[i];
        
    }
    ll o=0;
    for(ll i=0;i<n;i++)
    {
        cin>>vv[i];
        if(vv[i]==-1)
        o++;
        p[i].second=vv[i];
        
    }
    if(o==n)
    {
        ll mx=*max_element(all(v));
        ll mf=LLONG_MAX;
        for(ll i=0;i<n;i++)
        {
            mf=min(mf,v[i]+k);
            // dis(mf);
        }
        ll ans=max(0ll,mf-mx+1);
        cout<<ans<<nl;
        return;
    }
    ll cur=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        if(p[i].second!=-1)
        {
            ll s=p[i].first +p[i].second;
            if(cur==INT_MIN)
            {
                cur=s;
                continue;
            }
            if(cur!=s)
            {
                cout<<0<<nl;
                return;
            }
            
        }
    }
    if(cur!=INT_MIN)
    {
        for(ll i=0;i<n;i++)
        {
            ll d=cur-v[i];
            if(d>=0 && d<=k)
            continue;
            cout<<0<<nl;
            return;
        }
        cout<<1<<nl;
        return;
    }
    

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
 return 0;
}
