/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
vector <int> g[N];
bool vis[N];

void dfs(int vertex){  // recursion function Q: TC of these 4 section
   /** Take action on vertex after entering
      the vertex
   **/
   if (vis[vertex]) return;
   cout << vertex << endl;
   vis[vertex] = true;
   for (int child : g[vertex]){
       cout << "parent " << vertex << ", child " << child << endl;
        if (vis[child]) continue;
        /** Take action on child before
           entering the child node
        **/
       dfs(child);
       /** Take action on child
         after exiting child node
         i.e. when u reach the end (leaf node)
        **/
   }
   /** Take action on vertex before
      exiting the vertex
    **/
}

int main(){
   int n,m; cin >> n >> m;
   int t;
   for (int i=0; i<m; i++){
    int v1, v2; cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
    t = v1;
   }
   dfs(t);
}

/*
input:
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
output:
5
parent 5, child 1
1
parent 1, child 3
3
parent 3, child 1
parent 3, child 5
parent 3, child 4
4
parent 4, child 3
parent 4, child 6
6
parent 6, child 3
parent 6, child 2
2
parent 2, child 3
parent 2, child 6
parent 6, child 4
parent 6, child 5
parent 3, child 6
parent 3, child 2
parent 1, child 5
parent 5, child 3
parent 5, child 6
*/

/* DS Explanation
 ### v.push_back() adds an element to the end of the vector v.
     v[i].push_back() adds an element to the end of the ith vector inside the vector v.
 ### v[i].push_back() suggests you're accessing the element at index i in the vector v,
 which contains other vectors. This usage would only make sense if v is a vector of vectors,
 where each element of v is itself a vector. In that case, v[i] gives you access to the ith vector in v,
 and then push_back() is called on that inner vector.

 */

