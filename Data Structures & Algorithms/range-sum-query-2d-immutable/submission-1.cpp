class NumMatrix {

    vector<vector<int>> matricaSuma;
    vector<int> redovi;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        matricaSuma = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(i - 1 >= 0 && j - 1 >= 0) {
                    matricaSuma[i][j] = matricaSuma[i-1][j] + matricaSuma[i][j-1] + matrix[i][j] - matricaSuma[i-1][j-1];
                } else if(i - 1 >= 0) {
                    matricaSuma[i][j] = matricaSuma[i-1][j] + matrix[i][j];
                } else if(j - 1 >= 0) {
                    matricaSuma[i][j] = matricaSuma[i][j-1] + matrix[i][j];
                } else {
                    matricaSuma[i][j] = matrix[i][j];
                }
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        if(row1 == 0 && col1 == 0) {
            return matricaSuma[row2][col2];
        } else if(row1 == 0) {
            return matricaSuma[row2][col2] - matricaSuma[row2][col2 - (col2 - col1) - 1];
        } else if(col1 == 0) {
            return matricaSuma[row2][col2] - matricaSuma[row2 - (row2 - row1) - 1][col2];
        } else {
            return matricaSuma[row2][col2] - matricaSuma[row2 - (row2 - row1) - 1][col2] - matricaSuma[row2][col2 - (col2 - col1) - 1] + matricaSuma[row1 - 1][col1 - 1];
        }
        //ovo je slucaj da nismo priljubljeni na gornju ili donju ivicu 
        //matrice, nasom manjom matricom

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */