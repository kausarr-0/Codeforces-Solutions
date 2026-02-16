//1. dp--->

// In the Name of ALLAH, the most gracious, the most merciful
// Watch the solve video on -> youtube.com/@CodeConnectt 
// #include <bits/stdc++.h>
// using namespace std;
// #define nl '\n'
// #define ll long long
// #define vl vector<ll>
// #define cy cout<<"YES"<<nl
// #define cn cout<<"NO"<<nl
// #define all(v) (v).begin(),(v).end()
// #define si(v) int((v).size())
// #define pb push_back
// const int inf = 1e9;
// const ll INF = 1e18;
// const int mod = 998244353;
// const int Big = 2e5 + 5;
// #ifndef ONLINE_JUDGE
// #define dis(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _dbg(const char* n, T&& v) {cerr<<n<<" = "<<v<<'\n';}
// template <typename T, typename... A>
// void _dbg(const char*n,T&& v,A&&... a){const char*c=strchr(n+1,',');
//     cerr.write(n,c-n)<<" = "<<v<<" | ";_dbg(c+1, a...); }
// #else
// #define dis(...)
// #endif
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;
//         x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
//     size_t operator()(long long x)const{static const uint64_t FIXED_RANDOM=
//         chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
// //..................................................................................................

// void solve() {
//     ll n;cin>>n;
//     vl v(n);
//     vector<vector<ll>>g(7);
//     for(auto &i:v)
//     cin>>i;

//     for(ll i=1;i<7;i++)
//     {
//         for(ll j=1;j<7;j++)
//         {
//             if(j!=i && j!=7-i)
//             {
//                 g[i].pb(j);
//             }
//         }
//     }

//     vl f(7,INT_MAX),c(7,INT_MAX);

//     for(ll i=1;i<7;i++)
//     {
//         if(v[0]!=i)
//         {
//             f[i]=1;
//         }
//         else {
//             f[i]=0;
//         }
//     }

//     for(ll i=1;i<n;i++)
//     {
//         for(ll i=0;i<7;i++)
//         {
//             c[i]=INT_MAX;
//         }

//         for(ll j=1;j<7;j++)
//         {
//             // dis(j);
//             for(ll k=1;k<7;k++)
//             {
//                 // dis(j+k);
//                 if(k!=j && j+k!=7)
//                 {
//                     // dis(c[j]);
//                     ll cost=f[k];
//                     // dis(j,v[i],cost);
                    
//                     if(v[i]!=j)
//                     cost++;
//                     c[j]=min(c[j],cost);   
//                     // dis(c[j]);
//                 }
//             }
//         }
//         f=c;

//     }

//     cout<<*min_element(f.begin()+1,f.end())<<nl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int T = 1;
//     cin >> T;
//     for (int tc = 1; tc <= T; tc++) {
//         //cout << "Case " << tc << ": ";
//         solve();
//     }
//  return 0;
// }



//2. Greedy--->>

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

void solve() {
    ll n;cin>>n;
    vl v(n);
    for(auto &i:v)
    cin>>i;

    ll cnt=0;

    for(ll i=0;i<n-1;i++)
    {
        if(v[i]==v[i+1] || v[i+1]==7-v[i])
        {
            cnt++;
            v[i+1]=-1;
        }
    }
    cout<<cnt<<nl;
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
