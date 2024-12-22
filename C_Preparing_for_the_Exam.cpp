/* In the Name of ALLAH, the most gracious, the most merciful  */
#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define ll long long
#define cy cout << "YES" << nl
#define cn cout << "NO" << nl
#define dis(x) cerr << #x << " = " << x << nl
#define all(v) (v).begin(), (v).end()
#define si(v) int((v).size())
#define pb push_back
const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
// Formula X:
ll findIndex(const vector<ll> &v, ll e)
{
    auto it = find(all(v), e);
    if (it != v.end())
    {
        return distance(v.begin(), it);
    }
    return -1;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (1LL * a * b) / __gcd(a, b); }
ll sumFrom_IToJ(ll i, ll j) { return ((j - i + 1LL) * (i + j)) / 2; }
bool sorta_2nd(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second); /* Use : sort(all(vec),sorta_2nd);*/
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(ll n) { return (n > 0) && (n & (n - 1)) == 0; }

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(n), q(m), a(k);
    iota(all(v), 1);
    for (auto &I : q)
    {
        cin >> I;
    }
    unordered_set<ll> s;
    for (auto &I : a)
    {
        cin >> I;
        s.insert(I);
    }

    if (n - k > 1)
    {
        for (ll i = 0; i < m; i++)
            cout << 0;
        cout << nl;
        return;
    }
    if (n == k)
    {
        for (ll i = 0; i < m; i++)
            cout << 1;
        cout << nl;
        return;
    }

    string ans = "";

    ll ptr = 1;
    for (auto i : a)
    {
        if (i == ptr)
        {
            ptr++;
        }
        else
        {
            break;
        }
    }
    if (ptr > n)
        ptr = n;

    for (auto i : q)
    {
        if (i == ptr)
            ans += '1';
        else
            ans += '0';
    }
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
