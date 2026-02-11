#include <bits/stdc++.h>

using namespace std;
#define f for (int i = 0; i < n; i++)
#define f1 for (int i = 1; i < n; i++)
#define fj for (int j = 0; j < n; j++)
#define s(x) sort(x.begin(),x.end());
#define ll long long

 vector<vector<int>>v(10005);
 bool vis[10005];
 int lavel[10005];
 int parent[10005];
 void bfs(int scr){
    queue<int>q;
    q.push(scr);
    vis[scr]=true;
    lavel[scr]=0;
    while (!q.empty())
    {
        /* code */
        int par=q.front();
        q.pop();
        for(auto x:v[par])
        {
            if(vis[x]==false)
            {
                q.push(x);
                vis[x]=true;
                lavel[x]=lavel[par]+1;
                parent[x]=par;
            }

        }
    }
    
 }


 int main()

{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        /* code */
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    memset(vis,false,sizeof(vis));
    memset(lavel,-1,sizeof(lavel));
    memset(parent,-1,sizeof(parent));
    int scr,dest;
    cin>>scr>>dest;
    bfs(scr);
    vector<int>s;
    int node=dest;
    while (node!=-1)
    {
        /* code */
        s.push_back(node);
        node=parent[node];

    
    }

    reverse(s.begin(),s.end());
    for(auto x:s)
    {
        cout<<x<<" ";
    }
    
    


    return 0;
}