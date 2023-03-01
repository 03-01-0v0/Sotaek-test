#include <bits/stdc++.h>
using namespace std;

// Coi như có thể thực hiện nhiều giao dịch trong ngày, miễn đảm bảo thực hiện lệnh bán rồi mới thực hiện lệnh mua tiếp theo

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; // N - N is the length of the input array
    cin >> N;
    vector<int> v(N);
    for (auto &e: v)
        cin >> e;
    int res = 0; // choose data type as int, can change depending on requirements
    for (int i = 0; i < N - 1; i++) {
        if (v[i] < v[i + 1])
            res += (v[i + 1] - v[i]);
    }
    cout << res << "\n";


    return 0;
}