package sorting;

public class bubblesort {
    static int count = 0;
    static void swap(int a, int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static void bubble(int arr[], int n)
    {
        for (int i = 0; i<n-1; i++)
        {
            for(int j = 0; j < n-i-1; j++)
            {
                if (arr[j] > arr[j+1])
                {
//                    swap(arr[j], arr[j+1]);
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    count++;
                }
            }
        }
    }

    static void print(int arr[],int n)
    {
        for (int i = 0; i < n; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int arr[] = {5,3,2,1,7};
        int n = arr.length;
        System.out.println("Unsorted array : ");
        print(arr, n);
        bubble(arr, n);
        System.out.println("\nSorted array : ");
        print(arr, n);
        System.out.println("\nCount = "+count);

    }


}
