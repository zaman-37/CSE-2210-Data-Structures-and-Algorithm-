#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> maz; // Maze input
vector<vector<int>> grd; // Solution grid
int c, r;                // Columns and rows
int sc, sr;              // Start coordinates
int dc, dr;              // Destination coordinates

int dx[] = {0, 0, +1, -1}; // Movement in x-direction
int dy[] = {+1, -1, 0, 0}; // Movement in y-direction

void backtrack(int i, int j) {
    grd[i][j] = 1; // Mark the current cell as part of the path

    // Base case: if we reach the destination
    if (i == dr && j == dc) {
        return;
    }

    // Explore all 4 possible directions
    for (int d = 0; d < 4; d++) {
        int x = i + dx[d];
        int y = j + dy[d];

        // Check if the next cell is within bounds, valid, and not already visited
        if (x >= 1 && x <= r && y >= 1 && y <= c && maz[x][y] == 1 && grd[x][y] == 0) {
            backtrack(x, y);

            // Stop further exploration if the destination is reached
            if (grd[dr][dc] == 1) {
                return;
            }

            // Backtrack: Unmark the current cell
            grd[x][y] = 0;
        }
    }
}

int main() {
    cin >> c >> r; // Input columns and rows
    maz.assign(r + 5, vector<int>(c + 5, 0));
    grd.assign(r + 5, vector<int>(c + 5, 0));

    // Input the maze
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> maz[i][j];
        }
    }

    cin >> sr >> sc; // Start coordinates
    cin >> dr >> dc; // Destination coordinates

    // Perform backtracking
    backtrack(sr, sc);

    // Output the solution grid
    cout << "output: " << endl;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << grd[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

4 4
1 0 0 0  
1 1 0 1  
0 1 0 0  
1 1 1 1 
1 1
4 4
*/