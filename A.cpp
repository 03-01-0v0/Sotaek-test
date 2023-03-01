#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; // N - N is the length of the input array
    cin >> N;
    vector<int> v(N);
    int sum = 0; // choose data type as int, can change depending on requirements
    for (auto &e: v) {
        cin >> e;
        sum += e;
    }

    vector<int> res; // Result
    for (auto e: v) {
        res.push_back(sum - e);
    }

    for (auto e : res)
        cout << e << " ";


    return 0;
}