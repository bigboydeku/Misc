#include <stdio.h>
#include <stdbool.h>

#define WIDTH 12
#define HEIGHT 12

// Prototypes
bool isValid(char m[][WIDTH]);						// Checks if the provided maze is valid
void findStart(char m[][WIDTH]);					// Find start coord of maze
void mazeTraversal(char m[][WIDTH], int x, int y);	// Recursively traverse maze
void printMaze(char m[][WIDTH]);					// Display maze
bool isEdge(char m[][WIDTH], int x, int y);			// Check move validity

int main() {
	char maze[HEIGHT][WIDTH] = { {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
								 {'1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
								 {'0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
								 {'1', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
								 {'1', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
								 {'1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
								 {'1', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
								 {'1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
								 {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
								 {'1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
								 {'1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
								 {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
								};

	if (!isValid(maze)) {
		printf("Not valid maze\n");
		return 0;
	}

	findStart(maze);
	mazeTraversal(maze, -1, -1);

	return 0;
}

/*
 * Description:	Checks if the provided maze has an entrance and exit
 * Parameters:	Array of chars - m: the maze to validate
 * Returns:		True if m is valid
 *				False if not
**/
bool isValid(char m[][WIDTH]) {
	int hole_count = 0;

	for (int i = 1; i < WIDTH - 1; i++) {
		if (m[0][i] == '0' || m[HEIGHT - 1][i] == '0') {
			hole_count++;
		}
	}

	for (int i = 1; i < HEIGHT - 1; i++) {
		if (m[i][0] == '0' || m[i][WIDTH - 1] == '0') {
			hole_count++;
		}
	}

	if (hole_count == 2) {
		return true;
	}
	return false;
}

/*
 * Description:	Determine the start coordinates and
 *				sets that spot to 'X'
 * Parameters:	Array of chars - m: the maze
 * Returns:		void
**/
void findStart(char m[][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		if (m[i][0] == '0') {
			m[i][0] = 'X';
			return;
		}
	}
}

/*
 * Description:	Recursively traverses the maze and finds
 *				a path to the end.
 * Parameters:	Array of chars - m: the maze
 *				Integer - x: x coord of current position in traversal
 *				Integer - y: y coord of current position in traversal
 * Returns:		void
**/
void mazeTraversal(char m[][WIDTH], int x, int y) {
	//printMaze(m);

	if (x == -1 && y == -1) {  // First call of function
		for (int i = 0; i < HEIGHT; i++) {
			if (m[i][0] == 'X') {
				x = 0;
				y = i;
			}
		}
	}
	else if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {  // Maze end
		m[y][x] = 'X';
		printMaze(m);
		return;
	}

	m[y][x] = 'X';  // Mark spot

	if (!isEdge(m, x + 1, y)) {
		mazeTraversal(m, x + 1, y);
	}
	if (!isEdge(m, x - 1, y)) {
		mazeTraversal(m, x - 1, y);
	}
	if (!isEdge(m, x, y + 1)) {
		mazeTraversal(m, x, y + 1);
	}
	if (!isEdge(m, x, y - 1)) {
		mazeTraversal(m, x, y - 1);
	}
}

/*
 * Description:	Display maze to user
 * Parameters:	Array of chars - m: the maze
 * Returns:		void
**/
void printMaze(char m[][WIDTH]) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			printf("%c ", m[y][x]);
		}
		printf("\n");
	}
}

/*
 * Description:	Determine if the provided coords are a valid spot to move to
 * Parameters:	Array of chars - m: the maze
 *				Integer - x: x coord of spot to check
 *				Integer - y: y coord of spot to check
 * Returns:		True if valid move
 *				False if not
**/
bool isEdge(char m[][WIDTH], int x, int y) {
	if (m[y][x] != '0') {
		return true;
	}

	return false;
}