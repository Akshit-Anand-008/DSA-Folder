#include "number-of-enclaves.h"

int flood(const vector<vector<int>>& grid, int i, int j) {
    // I need to maintain another fatass grid containing if I have visited that vector or not
}

int numEnclaves(const vector<vector<int>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    if(height == 0 || width == 0){ return 0; }
    int i, j;
    i = 0;
    for(int j = 0; j < width; j++){
        if(grid[i][j] == 1){
            flood(grid, i, j);
        }
    }
    i = height - 1;
    for(int j = 0; j < width; j++){
        if(grid[i][j] == 1){
            flood(grid, i, j);
        }
    }
    j = 0;
    for(int i = 1; i < height - 1; i++){
        if(grid[i][j] == 1){
            flood(grid, i, j);
        }
    }
    j = width - 1;
    for(int i = 1; i < height - 1; i++){
        if(grid[i][j] == 1){
            flood(grid, i, j);
        }
    }
}
