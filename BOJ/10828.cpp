#include <bits/stdc++.h>
namespace ran = std::ranges;
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    stack<int> s;
    cin.ignore();

    while (N--) {
        string tmp;
        getline(cin, tmp);
        if (tmp.size() >= 6) {
            string sub = tmp.substr(5);
            s.push(stoi(sub));
        } else if (tmp == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (tmp == "size") {
            cout << s.size() << '\n';
        } else if (tmp == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        } else cout << s.empty() << '\n';
    }
}
