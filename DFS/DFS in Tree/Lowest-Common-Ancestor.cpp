/** BISMILLAHIR RAHMANIR RAHIM
   Author: Hamed Hasan/PUC
  -> How to find lowest common ancestor (LCA)
  -> Time Complexity of this approach: O(n)
  -> Learn Binary Lifting (Kth ancestor of a tree node)
**/

#include <bits/stdc++.h>
using namespace std;
int const N = 1e5+10;
vector <int> v[N];
int parent[N];  // new lgc

void dfs (int vertex, int par){   // why this section is necessary for finding path??
     parent[vertex] = par;  // each index storing a value, index=child. value = parent

     for (int child : v[vertex]){
        if (child == par) continue; // basic tree logic

        dfs(child, vertex);  // basic tree logic
    }
}

vector <int> path(int vertex){   // this function takes an int value as input and return a vector
      vector <int> ans;  // storing the path in ans
      while (vertex != 0){
         ans.push_back(vertex);
         vertex = parent[vertex];  // updating the vertex
      }
      reverse(ans.begin(),ans.end());
      return ans;  // return a vector ans
}

int main(){
   int n; cin >> n;
   for (int i=0; i<n-1; i++){
        int v1,v2; cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
   }
   dfs(1,0);

   int x,y; cin >> x >> y;
   vector <int> path_x = path(x);
   vector <int> path_y = path(y);
   int mn_ln = min(path_x.size(),path_y.size());

   int lca = -1;
   for (int i=0; i<mn_ln; i++){
      if (path_x[i] == path_y[i])
         lca = path_x[i];
      else
         break;
   }

   cout << lca << endl;
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
6 12   // find LCA for node 6 and 12
output:
5

*/

/*
this approach is imp. for viva attempt
for C.P.: learn binary lifting
*/
