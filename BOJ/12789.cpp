#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int N, curr;
    cin >> N;

    stack<int> stk;
    queue<int> q;
    while(N--){
        cin >> curr;
        q.push(curr);
    }
    int ord = 1;
    while(q.size()){
        if(q.front() == ord){
            ord++;
            q.pop();
        }
        else{
            if(stk.empty()){
                stk.push(q.front());
                q.pop();
                continue;
            }
            if(stk.top() == ord){
                stk.pop();
                ord++;
            }
            else if(stk.top() < q.front()){
                cout << "Sad";
                return 0;
            }
            else{
                stk.push(q.front());
                q.pop();
            }
        }
    }
    cout << "Nice";
}
