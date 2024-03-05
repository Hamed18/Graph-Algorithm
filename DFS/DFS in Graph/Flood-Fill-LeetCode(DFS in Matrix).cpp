#include <bits/stdc++.h>
using namespace std;
// int const N=1e5+10;
// bool vis[N];

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image){
         int n=image.size();
         int m=image[0].size();
         if (i<0 || j<0) return;
         if (i>=n || j>=m) return;
         if (image[i][j] != initialColor) return;

         image[i][j] = newColor;

         dfs(i-1,j,initialColor,newColor,image);
         dfs(i+1,j,initialColor,newColor,image);
         dfs(i,j+1,initialColor,newColor,image);
         dfs(i,j-1,initialColor,newColor,image);

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int initialColor = image[sr][sc];
     int newColor= color;
     if (initialColor != newColor)
        dfs(sr,sc,initialColor,newColor,image);
     return image;
}

/*
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

https://leetcode.com/problems/flood-fill/description/

Q: why vis[] not been used?

P.S. Type:
DFS. Connected Component. Matrix. edge~4Directional(i.e. diagonal)
*/
