/**
 Author: Hamed Hasan/PUC
 -> Diameter of Tree
 -> TC: O(n). Brute Force is O(n^2)
**/

#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
vector <int> v[N];
int depth[N];

void dfs (int vertex, int parent){

   for (int child: v[vertex]){
        if (child == parent) continue;  // basic tree logic
        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
   }
}

int main(){
    int n; cin >> n;
    for (int i=0; i<n-1; i++){
        int v1,v2; cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    dfs(1,-1);  // assuming root is 1, we call dfs() and parent[i] will be stored for each node

    int mx_depth = -1;
    int mx_depth_node;
    for (int i=1; i<=n; i++){
        if (mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        depth[i]=0;
    }

    dfs(mx_depth_node,-1);  // if we change the root, depth[i] will also be changed

    mx_depth = -1;
    for (int i=1; i<=n; i++){
        if (mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }

    cout << mx_depth << endl;
}

/*
input:
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
output:
8   // path between root 12 and 11
*/

