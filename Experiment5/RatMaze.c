#include <stdio.h>
#include <stdbool.h>

#define M 5
#define N 5


void printMaze(int maze[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}


bool isValid(int maze[M][N], int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1);
}


bool solveMazeUtil(int maze[M][N], int x, int y, int sol[M][N]) {
    
    if (x == M - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    
    if (isValid(maze, x, y)) {
    
        sol[x][y] = 1;

        
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        
        sol[x][y] = 0;
        return false;
    }

    return false;
}


bool solveMaze(int maze[M][N]) {
    int sol[M][N] = { {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0} };

    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        printf("Solution doesn't exist");
        return false;
    }

    printf("Solution path:\n");
    printMaze(sol);
    return true;
}


int main() {
    int maze[M][N] = { {1, 0, 1, 0, 1},
                       {1, 1, 1, 1, 1},
                       {0, 1, 0, 0, 0},
                       {1, 1, 1, 1, 1},
                       {0, 1, 1, 0, 1} };

    solveMaze(maze);

    return 0;
}
