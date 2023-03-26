#pragma once
class Canvas
{
    char mat[22][22];
    int width, height;
public:
    Canvas(int w, int h) {

        width = w;
        height = h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                mat[i][j] = ' ';
            }
        }
    }

    void DrawCircle(int x, int y, int ray, char ch);

    void FillCircle(int x, int y, int ray, char ch);

    void DrawRect(int left, int top, int right, int bottom, char ch);

    void FillRect(int left, int top, int right, int bottom, char ch);

    void SetPoint(int x, int y, char ch);

    void DrawLine(int x1, int y1, int x2, int y2, char ch);

    void Print(); // shows what was printed

    void Clear(); // clears the canvas

};

