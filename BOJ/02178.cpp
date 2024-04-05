#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;

int arr[102][102];
int vst[102][102];

int dy[]{1, 0, -1, 0};
int dx[]{0, 1, 0, -1};

int main() {
    cin >> N >> M;
    cin.ignore(); // buffer flush before getline(), after using cin

    string str;
    for(int i=0; i<N; i++){
        getline(cin, str);
        for(int j=0; j<M; j++) arr[i][j] = str[j] - '0';
    }

    queue<pair<int, int>> q;
    vst[0][0] = 1;

    q.push({0, 0}); // brace init instead of make_pair() (C++11)
    while(q.size()){
        auto [y, x] = q.front(); // structural binding (C++17)
        q.pop();

        for(int i: {3, 1, 0, 2}){ // range based for with init_list (C++11)
            int nx = x + dx[i];
            int ny = y + dy[i];

            // `&& == and`, `|| == or` (since C++98) 왜 아무도 안쓰는거지?
            if(nx < 0 or ny < 0 or N < ny or M < nx or !arr[ny][nx]) continue;

            if(vst[ny][nx]) continue;
            vst[ny][nx] = vst[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << vst[N-1][M-1];
}
