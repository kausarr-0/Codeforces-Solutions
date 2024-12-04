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
/* Formula X:
 * Sum of 'i to j' = ((j-i+1)*(i+j))/2;
 * LCM = (a*b)/__gcd(a,b);
 *
 *  --*/

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s1(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s1[i];
    }

    vector<vector<int>> bad(n, vector<int>(m, 0));
    queue<pair<int, int>> pq;

    for (int i = 0; i < n; ++i)
    {
        if (s1[i][0] == 'L')
        {
            bad[i][0] = 1;
            pq.push({i, 0});
        }
        if (s1[i][m - 1] == 'R')
        {
            bad[i][m - 1] = 1;
            pq.push({i, m - 1});
        }
    }

    for (int i = 0; i < m; ++i)
    {
        if (s1[0][i] == 'U')
        {
            bad[0][i] = 1;
            pq.push({0, i});
        }
        if (s1[n - 1][i] == 'D')
        {
            bad[n - 1][i] = 1;
            pq.push({n - 1, i});
        }
    }

    while (!pq.empty())
    {
        pair<int, int> cur = pq.front();
        int ix = cur.first;
        int iy = cur.second;
        pq.pop();

        // dis(ix);
        // dis(iy);

        if (ix > 0 && bad[ix - 1][iy] == 0 && s1[ix - 1][iy] == 'D')
        {
            bad[ix - 1][iy] = 1;
            pq.push({ix - 1, iy});
        }

        if (ix < n - 1 && bad[ix + 1][iy] == 0 && s1[ix + 1][iy] == 'U')
        {
            bad[ix + 1][iy] = 1;
            pq.push({ix + 1, iy});
        }

        if (iy > 0 && bad[ix][iy - 1] == 0 && s1[ix][iy - 1] == 'R')
        {
            bad[ix][iy - 1] = 1;
            pq.push({ix, iy - 1});
        }

        if (iy < m - 1 && bad[ix][iy + 1] == 0 && s1[ix][iy + 1] == 'L')
        {
            bad[ix][iy + 1] = 1;
            pq.push({ix, iy + 1});
        }
    }

    ll sum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (bad[i][j] == 0 && s1[i][j] != '?')
            {
                ++sum;
                //dis(sum);
            }
            else if (bad[i][j] == 0)
            {
                ll num = 1;
            

                if (i > 0)
                    num &= bad[i - 1][j];
                if (j > 0)
                    num &= bad[i][j - 1];
                if (i < n - 1)
                    num &= bad[i + 1][j];
                if (j < m - 1)
                    num &= bad[i][j + 1];

                if (num == 0)
                    ++sum;
            }
        }
    }

    cout << sum << nl;
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