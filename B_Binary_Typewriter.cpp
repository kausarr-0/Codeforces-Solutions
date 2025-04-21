/* In the Name of ALLAH, the most gracious, the most merciful  */
/* Watch the solve video on -> youtube.com/@MythologicalCoding */
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
const int Big = 2e5 + 5;

string rev(string s)
{

    ll f = -1;
    for (ll i = 0; i < si(s); i++)
    {
        if (s[i] == '1')
        {
            f = i;
            break;
        }
    }

    if (f == -1)
        return s;

    ll mx = 0, cur = 0;
    ll st = -1, e = -1;

    for (ll i = f; i < si(s); i++)
    {
        if(s[i]=='0'){
            
            while(i<si(s) && s[i]=='0')i++;
            e=i;
            break;
        }

    }

    if (f <= e)
    {
        reverse(s.begin() + f, s.begin() + e);
    }
    // dis(s);
    return s;
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll one = count(all(s), '1'), ze = count(all(s), '0');

    if (ze == n)
    {
        cout << n << nl;
        return;
    }
    if (one == n)
    {
        cout << n + 1 << nl;
        return;
    }

    string ss = rev(s);
    ll cnt = 0;
    for (ll i = 1; i < n; i++)
    {
        if (ss[i] != ss[i - 1])
            cnt++;
    }
    cout << n + cnt << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
