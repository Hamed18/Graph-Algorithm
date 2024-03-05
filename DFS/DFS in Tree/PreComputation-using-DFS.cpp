/* BISMILLAHIR RAHMANIR RAHIM
  -> Pre Computation using DFS

  *given Q Queries, Q <= 10^5
  *In each query given V,
  *Print subtree sum of V & Number of even numbers
  *in subtree of V
*/

#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
vector <int> g[N];
int subtree_sum[N];
// int val[N];
int even_ct[N];

void dfs(int vertex, int par){  // recursion function Q: TC of these 4 section
    /**
     section 1: Take action on vertex after entering the vertex
    **/
//    subtree_sum[vertex] += val[vertex];
    subtree_sum[vertex] += vertex;   // subtree_sum[vertex] += val[vertex];
    if (vertex % 2 == 0) even_ct[vertex]++;

   for (int child : g[vertex]){
    /**
      section 2: Take action on child before entering the child node
    **/

       if (child == par) continue;   // basic logic for Tree
       dfs(child,vertex);  // basic logic [vertex ~ parent]
    /**
      section 3: Take action on child after exiting child node i.e. when u reach the end (leaf node)
    **/
       subtree_sum[vertex] += subtree_sum[child];
       even_ct[vertex] += even_ct[child];
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
     cout << subtree_sum[i] << " " << even_ct[i] << endl;
   }

//    int q; cin >> q;
//    while(q--){
//        int v; cin >> v;
//        cout << subtree_sum[v] << " " << even_ct[v] << endl;
//    }

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
91 6
40 4
37 2
34 2
38 3
6 1
7 0
20 2
9 0
21 1
11 0
12 1
13 0

*/



