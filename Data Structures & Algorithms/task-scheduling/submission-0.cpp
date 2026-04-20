class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        int m = tasks.size();

        for(int i = 0;i<m;i++){
            freq[tasks[i]]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto it: freq){
            maxHeap.push({it.second, it.first});
        }

        int time = 0;

        queue<pair<int, char>> q;

        while(!q.empty() || !maxHeap.empty()){
            time++;

            if(maxHeap.empty()){
                time = q.front().first;
            } else {
                pair<int, char> currTask = maxHeap.top(); maxHeap.pop();
                freq[currTask.second]--;
                if(freq[currTask.second] > 0){
                    q.push({time+n,currTask.second});
                }
            }

            if(!q.empty() && q.front().first == time){
                pair<int, char> fr = q.front(); q.pop();
                maxHeap.push({freq[fr.second], fr.second});
            }
        }


        return time;
    }
};
