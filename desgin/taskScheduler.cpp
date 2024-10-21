#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <unordered_map>

// int leastInterval(std::vector<char>& tasks, int n) {
//     char current = tasks[0];
//     size_t p1 = 0;
//     size_t p2 = 1;

//     size_t size = tasks.size();
    
//     std::vector<char> mTasks;
//     while (p2 < size)
//     {
//         if(tasks[p1] == tasks[p2]){
//             ++p2;
//         }
//         else{
//             mTasks.push_back(tasks[p1]);
//             mTasks.push_back(tasks[p2]);

//             if((p2 - p1) !=1){
//                 ;
//             }
//             else{

//             }
//         }
//     }
//     return 0;
// }
int leastInterval(std::vector<char>& tasks, int n) {
    char current = tasks[0];
    std::vector<char> mTasks;
    int size = tasks.size();
    std::map<char,std::vector<std::vector<char>::iterator>> hashmap;

    for(size_t i = 0; i < size; ++i){
        hashmap[tasks[i]].push_back(tasks.begin() + i);
    }

    mTasks[0] = tasks[0];
    for (size_t i = 1; i < size; ++i)
    {
        if(tasks[i] == current){
            // Add next task to the output vector
            // Remove tasks added from the tasks vector
            // Update the size
            int k = 0;
            for(const auto& pair:hashmap){
                if(k < n){
                    if(pair.first == tasks[i]){
                        continue;
                    }
                else{
                   mTasks.push_back(pair.first);
                   tasks.erase(pair.second.front());
                   --size; 
                    }
                }
                ++k;
            }
        }
        mTasks.push_back(tasks[i]);
        current = tasks[i];
    }
    return 0; 
}

int main() {
    // Create a priority queue (max-heap by default)
    std::vector<char> tasks ={'A','A','A','B','B','B','C','C','D','D','D','D','D'};
    std::vector<int> freq(26);

    for(int i=0;i<tasks.size();++i){
        freq[tasks[i]-'A']++;
    }

    std::queue<int> pq;

    for(int i=0;i<freq.size();++i){
        if(freq[i] > 0){
            pq.push(freq[i]);
        }
    }



    int * p = &(pq.front());
    for (size_t i = 0; i < pq.size(); i++)
    {
        std::cout << p[i] << "\n"; 
    }
    
    // std::cout << "Queue size: " << pq.size() << "\n";
    // while(!pq.empty())
    // {
    //     std::cout << pq.top() << '\n';
    //     pq.pop();
    // }
    

    return 0;
}
