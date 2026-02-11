#include <bits/stdc++.h>

using namespace std;
#define f(n) for (int i = 0; i < n; i++)
#define f1(n) for (int i = 1; i < n; i++)
#define fj(n) for (int j = 0; j < n; j++)
#define s(x) sort(x.begin(), x.end());
#define ll long long
vector<vector<int>> v(10004);
bool vis[10004];
void bfs(int scr)
{
    queue<int> q;
    q.push(scr);
    vis[scr] = true;
    while (!q.empty())
    {
        /* code */
        int par = q.front();
        q.pop();
        for (auto x : v[par])
        {
            if (vis[x] == false)
            {
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

int main()

{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        /* code */
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int scr, dest;
    cin >> scr >> dest;
    memset(vis, false, sizeof(vis));
    bfs(scr);
    if (vis[dest])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}