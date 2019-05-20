template<typename T>
struct cumsum2D{
    int n, m;
    vector<vector<T>> dat;

    cumsum2D(){}
    cumsum2D(vector<vector<T>> &x){
        n = x.size();
        m = x[0].size();
        dat.assign(n+1, vector<T>(m+1));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
            dat[i+1][j+1] = dat[i+1][j] + dat[i][j+1] - dat[i][j] + x[i][j];
        }
    }

    // [0, x) * [0, y)
    T sum(int x, int y){
        return dat[x][y];
    }

    // [x0, x1) * [y0 * y1)
    T sum(int x0, int y0, int x1, int y1){
        return sum(x1, y1) - sum(x0, y1) - sum(x1, y0) + sum(x0, y0);
    }
};
