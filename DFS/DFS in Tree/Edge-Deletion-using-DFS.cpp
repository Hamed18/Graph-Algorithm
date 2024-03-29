/**
 P.S.: https://www.interviewbit.com/problems/delete-edge/

 *subtree sum concept
 *for which edge deletion, we get maximum product of two subtree
**/

#include <bits/stdc++.h>
using namespace std;
int const N = 1e5+10;
vector <int> v[N];
int subtree_sum[N];
int val[N];  // store the given weight of each node
int const M=1e9+7;

void dfs(int vertex, int par){

    subtree_sum[vertex] = val[vertex];
    for (int child : v[vertex]){
        if (child == par) continue;
        dfs(child,vertex);
        subtree_sum[vertex] += subtree_sum[child];

    }
}

int main(){
   int n;
   for (int i=0; i<n-1; i++){
      int v1,v2; cin >> v1 >> v2;
      v[v1].push_back(v2);
      v[v2].push_back(v1);
   }
   for (int i=0; i<n; i++){
      cin >> val[i];
   }

   dfs(1,0);
   long long ans = 0;
   for (int i=2; i<=n; i++){
     int part1 = subtree_sum[i];  // using PreComputation method
     int part2 = subtree_sum[1] - part1;  // after edge deletion
     ans = max(ans,part1*1LL*part2) %M;
   }
   cout << ans;

}

/*
Problem Description

Given an undirected tree with N nodes labeled from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

You need to delete an edge in such a way that the Product between the sum of weights of nodes in one subtree with the sum of weights of nodes in other subtree is maximized.

Return this maximum possible product modulo 109 + 7.

NOTE:

The tree is rooted at a node labeled with 1.
You need to return the maximum possible product, then take its mod.


Problem Constraints
2 <= N <= 105

1 <= A[i] <= 103



Input Format
First argument is an integer array A of size N denoting the weight of each node.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



Example Input
Input 1:

 A = [10, 5, 12, 6]
 B = [

        [1, 2]
        [1, 4]
        [4, 3]
     ]
Input 2:

 A = [11, 12]
 B = [

        [1, 2]
     ]


Example Output
Output 1:

 270
Output 2:

 132


Example Explanation

Explanation 1:
 Removing edge (1, 4) created two subtrees.
 Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
 So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270

Explanation 2:
 Removing edge (1, 2) created two subtrees.
 Subtree-1 contains node (1) and Subtree-2 contains node (3)
 So product will be = (A[1]) * (A[2]) = 11 * 12 = 132


 https://www.youtube.com/watch?v=NzEzJ6Rmv2Q&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=11

 */
