/// Author: Hamed Hasan
/// Disjoint Set Union (DSU) : Node Initialization. Finding Root. Adding two nodes
/// cp

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N]; // array. when we do Union, we make a parent of newly added vertex.
int sz[N];
// what make() does?
void make(int v){
   parent[v] = v; // initially each vertex is independent. Each vertex is a parent itself that means it's not anyone's child
}
// fint the core root of the any sub-child
int find(int v){  // path compression
   if (v == parent[v])  // if a vertex is a parent, then we don't need to find its parent anymore.
      return v;
   else
      return parent[v]=find(parent[v]);
}
// add two group or simply add two vertex.
// when we do union. parent changes. here's come make() func.
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){  // Union by rank // if root of a and b vertex is not same means we can add them.
        if (sz[a] < sz[b])  // if vertex a is smaller in size, swap a and b and make b smaller.
            swap(a,b);    // we have to make sure size b tree is smaller.
        parent[b] = a;   // size of tree b is smaller than tree a. so tree b is added under tree a.
        sz[a] += sz[b];  // as vertex b is added on vertex a. now size of vertex a increased.
    }
}

int main(){
    int n,k; cin >> n >> k;
    for (int i=1; i<=n; i++)
        make(i);   // create n numbers of nodes
    while (k--){
        int u,v;
        cin >> u >> v;
        Union(u,v);   // add u and v vertex
    }
    int connected_ct = 0;
    for (int i=1; i<=n; i++){
        if (find(i) == i) connected_ct++;  // no of root = no of connected componant.
    }
}

/*
   if we add small tree under a big tree, time complexity decrease!
   #Adding two tree: on based of size. size of small tree added under size of big depth tree.
*/
