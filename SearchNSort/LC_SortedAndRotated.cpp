class Solution {
public:
    int search(vector<int> &a, int t, int st, int end)
    {
        while(st <= end)
        {
            int mid = st + (end - st)/2;
            
            if(a[mid] == t)
                return mid;
            if(t > a[mid])
                st = mid + 1;
            else
                end = mid - 1;
        }
        
        return -1;
    }
    
    int findmin(vector<int> &a)
    {
        int st = 0, end = a.size() - 1;
        
        //if one element is left, return it.
        while(st < end)
        {
            int mid = st + (end - st)/2;
            // only two elements left in the searching space
            if(mid == st)
            {
                if(a[mid] <= a[end])
                    return mid;
                
                return mid + 1;
            }
            
            if(a[mid] < a[mid + 1] and a[mid] < a[mid - 1])
                return mid;
            
            if(a[mid] < a[end])
                end = mid - 1;
            else
                st = mid + 1;
        }
        
        return st;
    }
    
    int search(vector<int>& a, int t)
    {
    	// this question can also be solved using linear search
    	
    	// using binary search
        int minIndex = findmin(a);
        
        int left, right;
        
        if(t <= a[a.size() - 1])
            return search(a, t, minIndex, a.size() - 1);
        else
            return search(a, t, 0, minIndex - 1);

        return 0;
    }
};
