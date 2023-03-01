#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> preP(n); // pre_p[i] = max of X, X = a[r] - a[l] && 0 <= l <= r <= i && a[r] - a[l] > 0 ;
    vector<int> preMin(n); // pre_min[i] = min(a[0]...a[i])

    vector<int> suffP(n); // suff_p[i] = max of X, X = a[r] - a[l] && i <= l <= r <= n-1 && a[r] - a[l] > 0 ;
    vector<int> suffMax(n) ; // suff_max[i] = max(a[i]...a[n-1]);

    // pre-cal pre_p(n)
    int result = 0;

    preMin[0] = a[0];
    for (int i = 1 ; i < n ; i++) {

        int new_pair = a[i] - preMin[i - 1];
        preP[i] = max(preP[i - 1], new_pair);

        preMin[i] = min(preMin[i - 1], a[i]);

        result = preP[i]; // in case the optimal result only has 1 pair
    }

    suffMax[n - 1] = a[n - 1];
    for (int i = n - 2 ; i >= 2 ; i--) {
        int new_pair = suffMax[i + 1] - a[i];
        suffP[i] = max(suffP[i + 1], new_pair);

        suffMax[i] = max(suffMax[i + 1], a[i]);

        result = max(result, preP[i] + suffP[i]);
    }

    cout << result;
    return 0;
}