#include "Canvas.h"
#include <iostream>
using namespace std;
void Canvas:: FillCircle(int x, int y, int ray, char ch) {
    for (int i = x - ray-1; i <= x + ray; ++i) {
        for (int j = y - ray-1; j <= y + ray; ++j) {
            if ((i - x) * (i - x) + (j - y) * (j - y) < ray * ray) {
                mat[i][j] = ch;
            }
            if (abs((i - x) * (i - x) + (j - y) * (j - y) - ray * ray) < ray) {
                mat[i][j] = ch;
            }
        }
    }
}
void Canvas:: DrawCircle(int x, int y, int ray, char ch) {
    for (int i = x - ray-1; i <= x + ray; ++i) {
        for (int j = y - ray-1; j <= y + ray; ++j) {
            if (abs((i - x) * (i - x) + (j - y) * (j - y) - ray * ray) < ray) {
                mat[i][j] = ch;
            }
        }
    }
}


void Canvas:: DrawRect(int left, int top, int right, int bottom, char ch) {
    int i;
    for (i = left; i <= right; i++) {
        mat[top][i] = mat[bottom][i] = ch;
    }
    for (i = top; i <= bottom; i++) {
        mat[i][right] = mat[i][left] = ch;
    }
}
void Canvas:: FillRect(int left, int top, int right, int bottom, char ch) {
    int i, j;
    for (i = top; i <= bottom; i++) {
        for (j = left; j <= right; j++) {
            mat[i][j] = ch;
        }
    }
}

void Canvas:: SetPoint(int x, int y, char ch) {
    mat[x][y] = ch;
}
void Canvas:: DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1); //delta x
    int dy = abs(y2 - y1); //delta y
    int sx = x1 < x2 ? 1 : -1; //sign x
    int sy = y1 < y2 ? 1 : -1; //sign y
    int err = dx - dy; //eroare 

    while (x1 != x2 || y1 != y2) {
        mat[x1][y1] = ch;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


void Canvas:: Print() { // shows what was printed
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}
void Canvas:: Clear() { // clears the canvas
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            mat[i][j] = ' ';
        }
    }
}