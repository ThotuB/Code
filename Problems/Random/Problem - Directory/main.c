#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIRS 100

typedef struct Directory {
    char *name;
    struct Directory *child;
    struct Directory *sibling;
} Dir;

Dir *createDir(char *name) {
    Dir *dir = (Dir *)malloc(sizeof(Dir));
    dir->name = name;
    dir->child = NULL;
    dir->sibling = NULL;

    return dir;
}

void addChild(Dir *dir, Dir *child) {
    Dir *curr = dir;
    while (curr->child != NULL) {
        curr = curr->child;
    }
    curr->child = child;
}

void addSibling(Dir *dir, Dir *sibling) {
    Dir *curr = dir;
    while (curr->sibling != NULL) {
        curr = curr->sibling;
    }
    curr->sibling = sibling;
}

bool printLevel(Dir *dir, int level) {
    if (dir == NULL) {
        return false;
    }

    if (level == 0) {
        Dir* curr = dir;
        while (curr != NULL) {
            printf("Dir %s\n", curr->name);
            curr = curr->sibling;
        }
        return true;
    }
    else if (level > 0) {
        Dir* curr = dir;
        bool flag = false;
        while (curr != NULL) {
            flag |= printLevel(curr->child, level - 1);
            curr = curr->sibling;
        }
        return flag;
    }
    return false;
}

void printLevels1(Dir *dir) {
    int level = 0;
    bool flag;
    do {
        flag = printLevel(dir, level);
        level++;
    }while (flag);
}

void printLevels2(Dir *dir) {
    Dir *queue[MAX_DIRS];
    int front = 0;
    int rear = 1;

    queue[0] = dir;
    while (front != rear) {
        Dir *curr = queue[front];
        front++;
        
        while (curr != NULL) {
            printf("Dir %s\n", curr->name);
            if (curr->child != NULL) {
                queue[rear] = curr->child;
                rear++;
            }
            curr = curr->sibling;
        }
    }
}

int main() {
    Dir *Dirs[MAX_DIRS];

    /* 
     *  0
     *  |
     *  1 - 2 - 3
     *  |   |
     *  4   5 - 6 - 7
     *  |   |   |
     *  8   9  10 - 11
    */

    for (int i = 0; i < 12; i++) {
        char *name = (char *)malloc(sizeof(char) * 3);
        sprintf(name, "%d", i);
        Dirs[i] = createDir(name);
    }

    addChild(Dirs[0], Dirs[1]);
    addChild(Dirs[0], Dirs[4]);
    addChild(Dirs[0], Dirs[8]);
    addChild(Dirs[2], Dirs[5]);
    addChild(Dirs[2], Dirs[9]);
    addChild(Dirs[6], Dirs[10]);
    addSibling(Dirs[1], Dirs[2]);
    addSibling(Dirs[1], Dirs[3]);
    addSibling(Dirs[5], Dirs[6]);
    addSibling(Dirs[5], Dirs[7]);
    addSibling(Dirs[10], Dirs[11]);

    printLevels1(Dirs[0]);
}