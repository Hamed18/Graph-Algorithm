// find cycle in graph using dfs
#include <bits/stdc++.h>
using namespace std;

int const N=1e5+10;
vector <int> v[N];
bool vis[N];

vector <vector <int> > cc;
vector <int> current_cc;

bool dfs(int vertex, int par){
     vis[vertex] = true;
     bool isLoopExists = false;
     for (int child : v[vertex]){
        if (vis[child] && child == par) continue;
        if (vis[child]) return true;
        isLoopExists |= dfs(child,vertex);  // if any one child is already visited, then it will be true
     }
     return isLoopExists;
}

int main(){
    int n,e;
    cin >> n >> e;

    for (int i=0; i<e; i++){
        int v1,v2; cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    bool isLoopExists = false;
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        if (dfs(i,0)){
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists;
}

/*
8 6
1 2
2 3
2 4
3 5
6 7
1 5
output:
1   -> means loop exists
*/

/* Explaination;
 -> TC: O(V+E)

*/



