// Prim's Algorithm in C++
// Author: Hamed

#include <cstring>
#include <iostream>
using namespace std;

#define High 9999999
#define V    5


int G[V][V] =
{
  {0, 4, 0, 5, 2},
  {4, 0, 1, 3, 0},
  {0, 1, 0, 8, 0},
  {5, 3, 8, 0, 2},
  {2, 0, 0, 2, 0}

};

int main() {
  int no_edge;  // number of edge

  int selected[V];  // track a vertex is visited or not.

  // set selected false initially
  memset(selected, false, sizeof(selected));  // memset() function.

  no_edge = 0;

  // choose 0th vertex and make it true. but why??
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  cout << "Edge" << " : " << "Weight";
  cout << endl;

    int sum=0;  // total amount of minimum weight

  while (no_edge < V - 1) {
    // For every vertex in the set S, find the all adjacent vertices
    // calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    // choose another vertex nearest to selected vertex  at step 1.

    int min = High;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
//    selected[x] = false;

    no_edge++;
    sum+=G[x][y]; // sum of total minimum weight.
  }
  cout << "total minimum weight " << sum << endl;

  return 0;
}

/* output:
0 - 1 :  9
1 - 3 :  19
3 - 4 :  31
3 - 2 :  51
*/

/*
Test 1:
  {0, 4, 0, 5, 2},
  {4, 0, 1, 3, 0},
  {0, 1, 0, 8, 0},
  {5, 3, 8, 0, 2},
  {2, 0, 0, 2, 0}};

Output:
Edge : Weight
0 - 4 :  2
4 - 3 :  2
3 - 1 :  3
1 - 2 :  1
total minimum weight 8

Test 2:
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};
Output:
Edge : Weight
0 - 1 :  9
1 - 3 :  19
3 - 4 :  31
3 - 2 :  51
total minimum weight 110
*/

/* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}

Edge : Weight
0 - 1 :  2
1 - 2 :  3
1 - 4 :  5
0 - 3 :  6
total minimum weight 16
*/
// ThinkxAca
