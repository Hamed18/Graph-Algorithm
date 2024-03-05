#include <bits/stdc++.h>
using namespace std;

int const N=1e5+10;
vector <int> v[N];
bool vis[N];

void dfs(int vertex){
     if (vis[vertex]) return;
     vis[vertex] = true;
     for (int child : v[vertex]){
        dfs(child);
     }
}

int main(){
    int n,e,cnt=0;
    cin >> n >> e;

    for (int i=0; i<e; i++){
        int v1,v2; cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        else
            dfs(i);
        cnt++;
    }
    cout << cnt << endl;

}

/*
8 5
1 2
2 3
2 4
3 5
6 7
output:
3
*/

/*
 -> TC: O(V+E)

*/

