#include <bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    
    /**********my code but done in 2 traversals ************/


    int freq[3]={0,0,0};
    
    for(int i=0;i<n;i++)
      {
          freq[a[i]]++;
      }
      int idx=0;
      for(int i=0;i<3;i++)
      {
          while(freq[i])
          {
              a[idx++]=i;
              freq[i]--;
          }
      }



      /********** G4G method in one traversal******************/



      int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
 
        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }



    /**********************The best method **********************************/

  //it also counts the number 
      int arr[] = {0,1,2,2,1,0};
	int N = sizeof(arr)/sizeof(int);
	int i = 0, start = 0, end = N-1,no_of_swaps = 0;
	while(i<=end)
	{
		if(arr[i] == 0)//check for 0
		{
			if(arr[start] != 0)
			{
				swap(arr[i], arr[start]);
				no_of_swaps++;
			}
			else
				i++;
			start++;
		}
		else if(arr[i] == 2)//check for 2
		{
			if(arr[end] != 2)
			{
				swap(arr[i], arr[end]);
				no_of_swaps++;
			}
			end--;
		}
		else//do nothing for 1
			i++;
	}



    /***************************************************************/
	
}

// No need to do all this Count Sort or Dutch National Flag Algo. I have a 
// Very simple and working approach with O(n) Time complexity and O(1) 
// Space complexity. Works for all cases.

// Algorithm:
// Since we have to move all 0 to left and 2 to right, we consider 
// only these two values and do not care about 1, as they automatically get adjusted to center.
// 1)Take two variables start=0 and end=N-1.
// 2)start will store the index before which all 0's are stored.
// 3)end will store the index after which all 2's are stored.
// 4)Traverse the array and check for 0 and 2.
// (a) if arr[i] is 0
// check if arr[start] !=0 (then arr[start] should either be 1 or 2, 
// so swap arr[i] with start index to move arr[i] to its correct position and increment start)
// (b) if it is 2
// check if arr[end] !=2 (then arr[end] should either be 0 or 1, 
// so swap arr[i] with end index to move arr[i] to its correct position and decrement end)
// 5)You have sorted the array inplace with minimum no of swaps :)