class Solution {
public:
    int majorityElement(vector<int>& a)
    {
    	// method 1 : brute force : count frequency of every element using nested loops
    	// method 2 : sorting : sorting will group the same elements together, so we can calculate frequencies now.
    	// method 3 : use of hashmaps to count frequencies of every element
    	
    	//moore's voting algorithm
        int me = a[0];
        int c = 1;
        
        int n = a.size();
        for(int i=1; i<n; i++)
        {
            if(c == 0)
            {
                me = a[i];
                c = 1;
            }
            else
            {
                if(a[i] == me)
                    c++;
                else
                    c--;
            }
        }
        
        // provided that, there always exists a majority element
        return me;
    }
};
