
// sorting method
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int ptr1 = 0, ptr2 = 0;
        
        while(ptr1 < nums1.size() and ptr2 < nums2.size())
        {
            if(nums1[ptr1] == nums2[ptr2])
            {
                ans.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if(nums1[ptr1] < nums2[ptr2])
                ptr1++;
            else
                ptr2++;
        }
        
        return ans;
    }
};

// hashmap method

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> mp1, mp2;
        vector<int> ans;
        
        for(int i=0; i<nums1.size(); i++)
            mp1[nums1[i]]++;
        
        for(int i=0; i<nums2.size(); i++)
            mp2[nums2[i]]++;
        
        for(auto it=mp1.begin(); it!=mp1.end(); it++)
        {
            if(mp2.find(it->first) != mp2.end())
            {
                for(int i=0; i<min(mp2[it->first], it->second); i++)
                    ans.push_back(it->first);
            }
        }
        
        return ans;
    }
};
