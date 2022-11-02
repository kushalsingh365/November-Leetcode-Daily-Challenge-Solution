class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int n = bank.size();
        
        set<string> set;
        
        for(auto x : bank){
            set.insert(x);
        }
        
        if(set.find(end)==set.end()) return -1;
        
        queue<string> q;
        q.push(start);
        
        vector<char> v = {'A','C','G','T'};
        
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                string curr = q.front();
                q.pop();
                
                if(curr==end) return ans;
                
                
                for(int i=0;i<curr.size();i++){
                    for(int j=0;j<4;j++){
                        string t = curr; 
                        if(v[j]!=curr[i]){
                            t[i] = v[j];
                            if(set.find(t)!=set.end()){
                                q.push(t);
                                set.erase(t);
                            }
                        }
                    }
                }
                
            }
            
            
            ans++;
        }
        
        return -1;
        
        
    }
};
