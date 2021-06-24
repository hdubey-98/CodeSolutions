    // merge sort algorithm 
    
    void merge(vector<int> &a ,int st, int end, int mid)
    {
        vector<int> left, right;
        
        for(int i=st; i<=mid; i++)
            left.push_back(a[i]);
        
        for(int i=mid+1; i<=end; i++)
            right.push_back(a[i]);
        
        int ptr1 = 0, ptr2 = 0;
        
        for(int i=st; i<=end; i++)
        {
            if(ptr1 < left.size() and ptr2 < right.size())
            {
                if(left[ptr1] <= right[ptr2])
                {
                    a[i] = left[ptr1];
                    ptr1++;
                }
                else
                {
                    a[i] = right[ptr2];
                    ptr2++;
                }
            }
            else if(ptr1 < left.size())
            {
                a[i] = left[ptr1];
                ptr1++;
            }
            else
            {
                a[i] = right[ptr2];
                ptr2++;
            }
        }   
    }
    
    void mergeSort(vector<int> &nums, int st, int end)
    {
        if(st < end)
        {
            int mid = (st + end)/2;
            mergeSort(nums, st, mid);
            mergeSort(nums, mid + 1, end);
            
            merge(nums, st, end, mid);
        }
    }
    
    
    
    // quick sort algorithm
    
    
        int pos(vector<int> &a, int st, int end)
    {
        srand(time(0));
        int random = rand() % (end - st + 1);
        
        swap(a[st], a[st + random]);
        
        int j = st + 1;
        for(int i=st + 1; i<=end; i++)
        {
            if(a[j] > a[st])
            {
                if(a[i] <= a[st])
                {
                    swap(a[i], a[j]);
                    j++;
                }
            }
            else
                j++;
        }
        
        j--;
        swap(a[st], a[j]);
        
        return j;
    }
    
    void quick(vector<int> &nums, int st, int end)
    {
        if(st < end)
        {
            int index = pos(nums, st, end);
            
            quick(nums, st, index - 1);
            quick(nums, index + 1, end);
        }
    }
    
    
    // inbuilt sorting algorithm 
    
    vector<int> sortArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
    
