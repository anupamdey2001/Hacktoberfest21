class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    map <int, int> m;
        vector<int> v1;
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]))
                m[nums[i]]++;
            else
                m[nums[i]]=1;
            
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>1)
                v1.push_back(it->first);
                
        }
       return v1;
    }
};
    
    
    