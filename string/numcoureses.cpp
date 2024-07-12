#include <iostream>
#include <unordered_map>
#include <vector>

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites){

    std::unordered_map<int,std::vector<int>> umap;

    for(int i=0;i<prerequisites.size();++i){
        for(int j=1;j<prerequisites[0].size();++j){
            umap[prerequisites[i][0]].push_back(prerequisites[i][j]);
        }
    }
    

    for(int i=0;i<prerequisites.size();++i){
        for(int j=1;j<prerequisites[0].size();++j){
            if(umap.find(prerequisites[i][j]) != umap.end()){
                return false;
            }
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}};
    if(canFinish(2,prerequisites)){
        std::cout << "Valid\n"; 
    }
    else{
        std::cout << "Not Valid\n";
    }
    return 0;
}
