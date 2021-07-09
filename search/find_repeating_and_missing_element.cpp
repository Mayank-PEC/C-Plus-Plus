// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:


    int *findTwoElement(int *arr, int n) {
        // code here
     
     /*******************************************/
     int *ans = new int[2];
        
       for(int i=0;i<n;i++)
       {
           if(arr[abs(arr[i])-1]<0)  
                ans[0]=abs(arr[i]);
           
           else 
                arr[abs(arr[i])-1] *=-1;
       }
       
       
       for(int i=0;i<n;i++)
         if(arr[i]>0)
            ans[1]=i+1;
            
        return  ans;   
        
    /************************************************/
        
    //  using xor....   
        int res=0;
      for(int i=0;i<n;i++)
      {
          res^=arr[i];
      }
      
      for(int i=1;i<=n;i++)
        res^=i;
        
        
    // now res contains both the numbers that is
    // repeating as well as missing number
    
    int temp=res;
    int i=0;
    while(temp>0)    //---> only one step required 
                     //set_bit_no = xor1 & ~(xor1 - 1);
    {
        if(temp&1)
          break;
          
         i++;
         temp=temp>>1;
    }
       
       int mask=1<<i;
       int firstno = 0;
       int secondno = 0;
       
       
       for(int k=0;k<n;k++)
       {
           if((arr[k] & mask))
             firstno =firstno ^ arr[k];
            else
              secondno = secondno ^ arr[k];
       }
       
       
      for(int k=1;k<=n;k++)
      {
          if(k & mask)
            firstno = firstno^k;
          else
            secondno = secondno^k;
      }
      
      
      bool flag=false;
      for(int k=0;i<n;k++)
         {
             if(firstno==arr[k])
             {
                 flag=true;
                 break;
             }
         }
         
         int *ans = new int[2];
            
        if(flag)
        {
            ans[0]=firstno;
            ans[1]=secondno;
        }
        else
        {
            ans[0]=secondno;
            ans[1]=firstno;
        }
          
// in xor method getTwoElements function returns
// x and y, where either x is missing and y is 
// repeating or y is repeating and x is missing. 
// That is why at the end of function it should 
// check if x in array then swap it... 
            return ans;
            
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends