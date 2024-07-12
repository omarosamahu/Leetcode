#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::unordered_set<int> rows;
        std::unordered_set<int> cols;

        for(int x=0;x<matrix.size();++x){
            for(int y=0;y<matrix[0].size();++y){
                if(matrix[x][y] == 0){
                    rows.insert(x);
                    cols.insert(y);
                }
            }
        }
        
        for(int i = 0;i<matrix.size();++i){
            for(int j = 0;j<matrix[0].size();++j){
                    if(rows.count(i) > 0 || cols.count(j) > 0){
                        matrix[i][j] = 0;
                    }
                }
            }
}

void printMatrix(std::vector<std::vector<int>>& matrix){
    for(int x=0;x<matrix.size();++x){
            for(int y=0;y<matrix[0].size();++y){
                std::cout << matrix[x][y] << ',';                   
            }
            std::cout << "\n";
        }
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> input = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(input);
    printMatrix(input);
    return 0;
}
