package sorting;

public class quickSort1 {

    static int count=0;
    static void swap(int a[], int i , int j )
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static int partition(int[] a, int l, int h) 
    {
        int pivot = a[l];
        int i = l + 1;
        int j = h;

        while (i <= j) 
        {
            while (i <= j && a[i] <= pivot) 
            {
                i++;
            }
            while (a[j] > pivot) 
            {
                j--;
            }
            if (i < j) 
            {
                swap(a, i, j);
                count++;
            }
        }
        swap(a, l, j);
        return j;

    }

    static void quick(int[] a, int l, int h) {
        if (l < h) {
            int j = partition(a, l, h);
            quick(a, l, j);
            quick(a, j + 1, h);
        }

    }

    static void print(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void main(String[] args) {

        int[] arr = {13, 54, 11, 32, 66, 43, 25 };
        int n = arr.length;
        System.out.println("Before sorting : ");
        print(arr);
        quick(arr, 0, n-1);
        System.out.println("\nAfter sorting : ");
        print(arr);
    }

}
