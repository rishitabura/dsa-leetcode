package sorting;

public class insertion {

    public static void main(String[] args) {
        
        int key, j;
        int arr[] = {45,3,13,56,67,32};
        int n = arr.length;

        for(int i = 1; i<n; i++)
        {
            key = arr[i];
            j = i-1;

            while (j>=0 && arr[j] > key) 
            {
                arr[j+1] = arr[j];
                j--;   
            }
            arr[j+1] = key;

        }
        for (int i = 0; i < n; i++)
        {
            System.out.print(arr[i] + " ");
        }
        
    }
    
    
}
