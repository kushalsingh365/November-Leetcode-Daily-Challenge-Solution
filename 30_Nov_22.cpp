class Solution {
public:
   
   
   bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
	
	//Store frequencies in Freq map

    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];

        freq[curr]++;
    }

	//Size of Map

    int map_size = freq.size();

    // Itterate over frequencies and push them into set
    unordered_set<int> freq_set;

    for (auto x : freq)
    {
        freq_set.insert(x.second);
    }

    int freq_set_size = freq_set.size();



    //NOW IF SET and Map BOTH HAVE SAME SIZE, IT MEANS NO DUPLICACY 
        
        if(freq_set_size == map_size){
            return true;
        }
        
        else return false;
    }
};
