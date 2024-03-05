/* BISMILLAHIR RAHMANIR RAHIM
  -> How to DFS in a Tree
*/

#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
vector <int> g[N];
int height[N], depth[N];

void dfs(int vertex, int par){  // recursion function Q: TC of these 4 section
    /**
     section 1: Take action on vertex after entering the vertex
    **/

   for (int child : g[vertex]){
    /**
      section 2: Take action on child before entering the child node
    **/

       if (child == par) continue;   // logic
       depth[child] = depth[vertex] + 1;   // logic  ~ depth of child is depth of vertex + 1

       dfs(child,vertex);  // basic logic [vertex ~ parent]

       height[vertex] = max(height[vertex], height[child]+1);  // logic


    /**
      section 3: Take action on child after exiting child node i.e. when u reach the end (leaf node)
    **/

   }

    /**
       section 4: Take action on vertex before exiting the vertex
    **/

}

int main(){
   int n; cin >> n;

   for (int i=0; i<n-1; i++){
    int v1, v2; cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
   }

   dfs(1,0);

   for (int i=1; i<=n; i++){
     cout << depth[i] << " " << height[i] << endl;
   }

}

/*
input:

13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

ouput:
0 4
1 3
1 3
2 2
2 2
3 0
3 0
3 1
3 0
3 1
4 0
4 0
1 0
*/


