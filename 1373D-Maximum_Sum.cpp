#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

auto dp(int i, int j, int n, vl &vs, vector<vl> &memo)
{
    if(i >= n)
        return 0LL;

    if(memo[i][j] != -1LL)
        return memo[i][j];

    auto &ans = memo[i][j] = 0LL;
    ll even = (~i&1) * vs[i], odd = (i&1) * vs[i];

    if(j == 0)
    {
        ans = max(ans, dp(i + 1, j, n, vs, memo) + even);

        if(i + 1 < n)
        {
            ans = max(ans, dp(i + 2, 1, n, vs, memo) + odd + (odd ? 0LL : vs[i + 1]));
        }
    }
    else if(j == 1)
    {
        // Eu posso continuar invertendo, ou eu paro
        ans = max(ans, dp(i + 1, 2, n, vs, memo) + even);

        if(i + 1 < n)
        {
            ans = max(ans, dp(i + 2, j, n, vs, memo) + odd + (odd ? 0LL : vs[i + 1]));
        }
    }
    else
        ans = max(ans, dp(i + 1, 2, n, vs, memo) + even);

    return ans;
}

auto solve()
{
    int n;
    cin >> n;

    vl vs(n);
    for(auto &x : vs)
        cin >> x;

    vector<vl> memo(n, vl(3, -1LL));
    auto ans = max(dp(0, 0, n, vs, memo), dp(0, 1, n, vs, memo));

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}
