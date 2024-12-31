#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 3

typedef struct {
    int board[N][N];
    int emptyX, emptyY;
    int g, h, f;
    struct Node* parent;
} Node;

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool isEqual(Node* node1, Node* node2) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (node1->board[i][j] != node2->board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int calculateH(Node* current, Node* target) {
    int h = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (current->board[i][j] != 0) {
                int targetX = (current->board[i][j] - 1) / N;
                int targetY = (current->board[i][j] - 1) % N;
                h += manhattanDistance(i, j, targetX, targetY);
            }
        }
    }
    return h;
}

Node* createChildNode(Node* current, int newX, int newY) {
    Node* child = (Node*)malloc(sizeof(Node));
    *child = *current;
    child->board[current->emptyX][current->emptyY] = child->board[newX][newY];
    child->board[newX][newY] = 0;
    child->emptyX = newX;
    child->emptyY = newY;
    child->g += 1;
    child->h = calculateH(child, current);
    child->f = child->g + child->h;
    child->parent = current;
    return child;
}

Node** generateChildNodes(Node* current, Node* target, int* numChildren) {
    Node** children = (Node**)malloc(4 * sizeof(Node*));
    *numChildren = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int newX = current->emptyX + dx[i];
        int newY = current->emptyY + dy[i];

        if (isValid(newX, newY)) {
            Node* child = createChildNode(current, newX, newY);
            if (!isEqual(child, current)) {
                children[*numChildren] = child;
                (*numChildren)++;
            } else {
                free(child);
            }
        }
    }

    return children;
}

void printBoard(Node* node) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", node->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool solvePuzzle(Node* initial, Node* target) {
    Node* openList[100000];
    int openListSize = 0;
    bool closedList[100000] = {false};
    
    openList[openListSize++] = initial;

    while (openListSize > 0) {
        Node* current = openList[0];
        openListSize--;

        for (int i = 0; i < openListSize; i++) {
            openList[i] = openList[i + 1];
        }

        if (isEqual(current, target)) {
            printf("Solution found in %d steps:\n", current->g);
            Node* path = current;

            while (path != NULL) {
                printf("Step %d:\n", path->g);
                printBoard(path);
                path = path->parent;
            }

            return true;
        }

        int stateCode = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                stateCode = stateCode * N * N + current->board[i][j];
            }
        }
        closedList[stateCode] = true;

        int numChildren;
        Node** children = generateChildNodes(current, target, &numChildren);

        for (int i = 0; i < numChildren; i++) {
            int childStateCode = 0;
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    childStateCode = childStateCode * N * N + children[i]->board[x][y];
                }
            }

            if (!closedList[childStateCode]) {
                openList[openListSize++] = children[i];
                for (int j = openListSize - 1; j > 0; j--) {
                    if (openList[j]->f < openList[j - 1]->f) {
                        Node* temp = openList[j];
                        openList[j] = openList[j - 1];
                        openList[j - 1] = temp;
                    }
                }
            } else {
                free(children[i]);
            }
        }
        free(children);
    }

    printf("No solution found.\n");
    return false;
}

int main() {
    Node* initial = (Node*)malloc(sizeof(Node));
    Node* target = (Node*)malloc(sizeof(Node));

    // Initial state
    initial->board[0][0] = 1;
    initial->board[0][1] = 2;
    initial->board[0][2] = 3;
    initial->board[1][0] = 4;
    initial->board[1][1] = 5;
    initial->board[1][2] = 0;
    initial->board[2][0] = 7;
    initial->board[2][1] = 8;
    initial->board[2][2] = 6;
    initial->emptyX = 1;
    initial->emptyY = 2;
    initial->g = 0;
    initial->h = 0;
    initial->f = 0;
    initial->parent = NULL;

    // Target state
    target->board[0][0] = 1;
    target->board[0][1] = 2;
    target->board[0][2] = 3;
    target->board[1][0] = 4;
    target->board[1][1] = 5;
    target->board[1][2] = 6;
    target->board[2][0] = 7;
    target->board[2][1] = 8;
    target->board[2][2] = 0;
    target->emptyX = 2;
    target->emptyY = 2;
    target->g = 0;
    target->h = 0;
    target->f = 0;
    target->parent = NULL;

    solvePuzzle(initial, target);

    free(initial);
    free(target);

    return 0;
}

