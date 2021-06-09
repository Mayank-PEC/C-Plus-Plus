 int findPeakElement(vector<int>& nums) {
         int n=nums.size();
        
        if(n==1)
            return 0;
        int l=0;
       
        int h=nums.size()-1;
        
        int mid=-1;
        while(l<=h)
        {
        
            
            mid=l+(h-l)/2;
            
           if(mid>0 && mid<n-1)
           {
               if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                    break;
            
            else if(nums[mid]<nums[mid-1])
                  h=mid-1;
            
            else if(nums[mid]<nums[mid+1])
                 l=mid+1;
           }
            
            else if(mid==0)
            {
                if( nums[0]>nums[1])
                    return 0;
                else 
                    return 1;
            }
            
            else 
            {
                if(nums[n-1]>nums[n-2])
                    return n-1;
                else 
                    return n-2;
            }
            
        }
        
    return mid;
    }