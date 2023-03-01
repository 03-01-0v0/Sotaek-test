#include <bits/stdc++.h>
using namespace std;


bool sameSuit(vector<int> cards) { // đồng chất
    int suit = cards[0] / 13;
    for (int i = 1; i < (int) cards.size(); i++)
        if (suit != (cards[i] / 13))
            return false;
    return true;
}

bool consecutively(vector<int> cards) { // liên tiếp
    // have card A
    for (auto e: cards)
        e %= 13;
    if (cards[0] % 13 == 0) {
        for (int i = 1; i < (int) cards.size(); i++) {
            if (cards[i] + 1 != cards[i + 1])
                return false;
        }
        if (cards[cards.size() - 1] == 13)
            return true;
    }
    for (int i = 0; i < (int) cards.size() - 1; i++) {
        if (cards[i] + 1 != cards[i + 1])
            return false;
    }
    return true;
}

int sameNumber(vector<int> cards, int exp = 0) {  // cùng số
    for (auto e: cards)
        e %= 13;
    int cnt = 0;
    for (int i = 0; i < (int) cards.size() - 1; i++) {
        if (cards[i] != cards[i + 1]) {
            if (cnt >= exp)
                return true;
            cnt = 0;
        }
        ++cnt;
    }
    if (cnt >= exp)
        return true;
    return false;
}

int check(vector<int> cards) {
    set<int> st;
    for (auto e: cards)
        st.insert(e);
    return (int)st.size();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; // N - N is the length of the input array
    cin >> N;
    vector<int> v(N); // input number cards
    for (auto &e: v)
        cin >> e;
    sort(v.begin(), v.end());
    if (sameSuit(v) && consecutively(v)) {
        cout << 1;
        return 0;
    }
    if (sameNumber(v, 4)) {
        cout << 2;
        return 0;
    }
    if (check(v) == 2) {
        cout << 3;
        return 0;
    }

    if (sameSuit(v) && !consecutively(v)) {
        cout << 4;
        return 0;
    }

    if (!sameSuit(v) && consecutively(v)) {
        cout << 5;
        return 0;
    }
    if (sameNumber(v, 3)) {
        cout << 6;
        return 0;
    }

    if (check(v) == 3) {
        cout << 7;
        return 0;
    }

    if (sameNumber(v, 2)) {
        cout << 8;
        return 0;
    }

    cout << 9;

    return 0;
}