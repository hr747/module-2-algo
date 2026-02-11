#include <bits/stdc++.h>
using namespace std;

#define f(n) for (int i = 0; i < n; i++)
#define f1(n) for (int i = 1; i < n; i++)
#define fj(n) for (int j = 0; j < n; j++)
#define s(x) sort(x.begin(), x.end());
#define ll long long

vector<vector<int>> l(1005);
bool vis[1005];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int par = q.front();
        q.pop();
        cout << par << " ";

        for (auto car : l[par]) {
            if (vis[car] == false) {
                q.push(car);
                vis[car] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a); // undirected graph
    }

    memset(vis, false, sizeof(vis));

    bfs(1); // BFS শুরু হবে node 0 থেকে

    return 0;
}