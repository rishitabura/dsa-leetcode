package sorting;

public class quicksort {

    static int count=0;
    static void swap(int a[], int i , int j )
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static int partition(int a[], int p , int q)
    {
        int pivot = a[p];
        int i = p+1;
        int j = q;

        while (i<=j)
        {
            while (i<=j && a[i] <= pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i<j)
            {
                swap(a, i, j);
                count ++;
            }
        }
        swap(a, p, j);
        count++;
        return j;

    }

    static void quick(int a[], int l , int h)
    {
        if (l<h)
        {
            int index = partition(a,l,h);
            quick(a,l, index);
            quick(a,index+1, h);

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
        int arr[] = {54,21,5,1222,53,1323,765,43,34,10};
        int num = arr.length;
        System.out.println("Unsorted array : ");
        print(arr, num);
        System.out.println();
        quick(arr, 0, num-1);
        System.out.println("\nSorted array : ");
        print(arr, num);
        System.out.println("\nCount = "+count);

    }
}
