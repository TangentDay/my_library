int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

struct dice{
    int top, front, right;
    void set(int t, int f){
        top = t;
        front = f;
        int a[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 3, 5, 2, 4, 0},
                       {0, 4, 0, 1, 6, 0, 3},
                       {0, 2, 6, 0, 0, 1, 5},
                       {0, 5, 1, 0, 0, 6, 2},
                       {0, 3, 0, 6, 1, 0, 4},
                       {0, 0, 4, 2, 5, 3, 0}};
        right = a[top][front];
    }
    void rotate(int dir){
        switch (dir){
            case 0:
                swap(right, top);
                top = 7 - top;
                break;
            case 1:
                swap(right, top);
                right = 7 - right;
                break;
            case 2:
                swap(front, top);
                front = 7 - front;
                break;
            case 3:
                swap(front, top);
                top = 7 - top;
                break;
        }
    }
    int find(int i){
        if (right == i) return 0;
        if (7 - right == i) return 1;
        if (7 - front == i) return 2;
        if (front == i) return 3;
        return -1;
    }
};