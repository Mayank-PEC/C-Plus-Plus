  #include<bits/stdc++.h>
  using namespace std;

  int search(vector<int>& arr, int target) {
 int n=arr.size();
         int l=0;
	    int h=n-1;
	    int ans=-1;
	    while(l<=h)
	    {
	        int mid=((l+h)/2);
	        int prev=(mid-1+n)%n;
	        int forw=(mid+1)%n;
	        
	      /*  if( arr[mid]<=arr[prev] && arr[mid]<=arr[forw])
	        {
	           return mid%n;
	        }
	        if(arr[mid]>=arr[forw] && arr[forw]<=arr[(forw+1)%n])
	        {
	            return forw%n;
	        }*/
	        
	        if(arr[mid]>=arr[forw])
            {
                ans=forw;
                break;
            }
	        else if(arr[mid]>=arr[l])
	              l=mid+1;
	          
	           else if(arr[mid]<=arr[h])
	               h=mid-1;
	    }
        
        if(target<=arr[n-1])
        {
            l=ans;   // go right 
            h=n-1;
        }
        
        else
        {
            l=0;          //go left
            h=ans-1;
        }
        
        
       // return BS(arr,n,target,l,h); --->this normal Bsearch...
  }


  int alternate_solution_easy(vector<int>& arr, int target)
  {
       
        int l=0;
        int n=arr.size();
        int h=n-1;
        int ans=-1;
        
        while(l<=h)
        {
            int mid=(l+(h-l)/2);
            
            if(arr[mid]==target)
                 return mid;
            
            else if(arr[mid]>=arr[l])  // consider the exapmle [4 5 6 7 0 1 2 3]
            {
              if(target<arr[mid] && target>=arr[l])
            {
                h=mid-1;
            }
            else 
            {
                    l=mid+1;
            }
                
            }
                
            
            else if(arr[mid]<=arr[h])
            {
              if(target<=arr[h] && target>arr[mid])
                {
                        l=mid+1;
                }
                else 
                {
                      h=mid-1;
                }
          
            }
                   
            
            
                
        }
        return -1;
        
  }    