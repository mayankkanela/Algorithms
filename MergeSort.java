// public class MergeSort {
//     public void mergeSort(int[] arr,int l,int n)
//     {
//         if(l < n)
//         {
//             int m=(n+l)/2;
//             mergeSort(arr, l, m);
//             mergeSort(arr, m+1, n);
//             merge(arr, l, m, n);
//         }    
//     }
//     public void merge(int[] arr,int l,int m,int n)
//     {
//         int n1 = m - l + 1;
//         int n2 = n - m;
//         int[] A=new int[n1];
//         int[] B=new int[n2];
        
//         for(int i=0; i<n1; i++)
//         A[i] = arr[l+i];
        
//         for(int j=0; j<n2; j++)
//         B[j] = arr[m+1+j];
        
//         int i = 0;
//         int j = 0;
//         int k = 0;

//         while(i < n1 && j < n2)
//         {
//          if(A[i] <= B[j])
//          {
//              arr[k] = A[i];
//              i++;
//          }
//          else
//          {
//              arr[k] = B[j];
//              j++;
//          }
//          k++;

//         }

//         while(i < n1)
//         {
//             arr[k] = A[i];
//             i++;
//             k++;
//         }
        
//         while(j < n2)
//         {
//             arr[k] = B[j];
//             j++;
//             k++;
//         }
//     }
//     public static void main(String[] args) {
//         int[] arr = {2,9,1,5,4,3};
//         MergeSort test= new MergeSort();
//         test.mergeSort(arr ,0 ,arr.length-1);
//         for(int i=0; i<arr.length; i++)
//         System.out.println(arr[i]);                    
//     }

// }
/* Java program for Merge Sort */
class MergeSort 
{ 
	// Merges two subarrays of arr[]. 
	// First subarray is arr[l..m] 
	// Second subarray is arr[m+1..r] 
	void merge(int arr[], int l, int m, int r) 
	{ 
		// Find sizes of two subarrays to be merged 
		int n1 = m - l + 1; 
		int n2 = r - m; 

		/* Create temp arrays */
		int L[] = new int [n1]; 
		int R[] = new int [n2]; 

		/*Copy data to temp arrays*/
		for (int i=0; i<n1; ++i) 
			L[i] = arr[l + i]; 
		for (int j=0; j<n2; ++j) 
			R[j] = arr[m + 1+ j]; 


		/* Merge the temp arrays */

		// Initial indexes of first and second subarrays 
		int i = 0, j = 0; 

		// Initial index of merged subarry array 
		int k = l; 
		while (i < n1 && j < n2) 
		{ 
			if (L[i] <= R[j]) 
			{ 
				arr[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				arr[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 

		/* Copy remaining elements of L[] if any */
		while (i < n1) 
		{ 
			arr[k] = L[i]; 
			i++; 
			k++; 
		} 

		/* Copy remaining elements of R[] if any */
		while (j < n2) 
		{ 
			arr[k] = R[j]; 
			j++; 
			k++; 
		} 
	} 

	// Main function that sorts arr[l..r] using 
	// merge() 
	void sort(int arr[], int l, int r) 
	{ 
		if (l < r) 
		{ 
			// Find the middle point 
			int m = (l+r)/2; 

			// Sort first and second halves 
			sort(arr, l, m); 
			sort(arr , m+1, r); 

			// Merge the sorted halves 
			merge(arr, l, m, r); 
		} 
	} 

	/* A utility function to print array of size n */
	static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i] + " "); 
		System.out.println(); 
	} 

	// Driver method 
	public static void main(String args[]) 
	{ 
		int arr[] = {7, 13, 1, 2, 6, 7,24}; 

		System.out.println("Given Array"); 
		printArray(arr); 

		MergeSort ob = new MergeSort(); 
		ob.sort(arr, 0, arr.length-1); 

		System.out.println("\nSorted array"); 
		printArray(arr); 
	} 
} 
