/* Kruskal's algorithm to find shortest path or minimum cost.
Author: Hamed Hasan / Premier University.
MST:
1) minimum weight
2) no cycle in the tree.
3) no of edges = no of vertex -1
4) T.C. in each step i.e. sorting
5) Pair soritng: based on first value, then sc
6) theory Q: DSU- Initialization (make), Find Operation, Union Operation
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;  // 1e5: scientific notation for 1*10^5, which equals 100000. + 10: Adds 10 to the value, resulting in 100010.
int parent[N], sz[N];   // declare array.

void make(int v){  // initially call make() for each node
     parent[v] = v;  // initially, each node is independent. and its own parent
     sz[v] = 1;   // initially, size of each node (if only a node forming a tree) is 1.
}

int find(int v){   // to find the main root of vertax v
   if (parent[v] == v)
       return parent[v];
   else
       return parent[v] = find (parent[v]);
}

void Union(int a, int b){  // this steps add two diff nodes or tree together.
     a = find(a);  // find root of vertex a.
     b = find(b);
     if (a != b){  // if root of vertex a and b is not same then..
        if (sz[a] < sz[b])  // if vertex a is smaller in size, swap a and b and make b smaller.
            swap(a,b);    // we have to make sure size b tree is smaller.
        parent[b] = a;   // size of tree b is smaller than tree a. so tree b is added under tree a.
        sz[a] += sz[b];  // as vertex b is added on vertex a. now size of vertex a increased.
     }
}

int main(){
      int n,m; cin >> n >> m;
      vector < pair <int, pair<int,int> > > edges;
      for (int i=0; i<m; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});  // 3D container
      }
      sort(edges.begin(), edges.end());  // step 1

      for (int i=0; i<n; i++)   // step 2
          make(i);   // call make() func for each node.

      int total_cost = 0;

      for (auto &edge : edges){  // step 3
          int wt = edge.first;
          int u = edge.second.first;
          int v = edge.second.second;

          if (find(u) == find(v)) continue;  // skip if it's making a cycle
          Union(u,v);  // add both vertex.   // step 4
          total_cost += wt;
          cout << u << " - " << v << " : " << wt << endl;
      }
     cout << "total cost: " << total_cost << endl;
}

/*  here input taken and stored as adjacency list. Space Complexity: O(V^2) vs O(V + E)
Input:
6 9
 5 4 9
 1 4 1
 5 1 4
 4 3 5
 4 2 3
 1 2 2
 3 2 3
 3 6 8
 2 6 7
output:
1 4
1 2
3 2
5 1
2 6
total cost: 17
*/
