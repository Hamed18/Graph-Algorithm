/**
  BISMILLAHIR RAHMANIR RAHIM
  Author: Hamed Hasan
  -> find how many connected component in graph and display
**/

#include <bits/stdc++.h>
using namespace std;

int const N=1e5+10;
vector <int> v[N];
bool vis[N];

vector <vector <int> > cc;
vector <int> current_cc;

void dfs(int vertex){
     if (vis[vertex]) return;
     vis[vertex] = true;
     current_cc.push_back(vertex); // operation after entering the vertex
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
        current_cc.clear();
            dfs(i);
        cc.push_back(current_cc);
    }
    cout << cc.size() << endl;

    for (auto c_cc : cc){
        for (int vertex : c_cc){
            cout << vertex << " ";
        }
        cout << endl;
    }

}

/*
8 5  // no of nodes = 8;  no of edges = 5
1 2
2 3
2 4
3 5
6 7  // no 8 in adj list means 8 is not connected to any other node
output:
3
1 2 3 5 4
6 7
8
*/

/*
 -> TC: O(V+E)

*/


