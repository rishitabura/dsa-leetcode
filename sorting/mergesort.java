package sorting;

public class mergesort {

    static int count = 0;
    static void merge(int a[], int mid, int l , int h)
    {
        int i = l;
        int j = mid+1;
        int k = l;
        int b[] = new int[a.length];

        while (i<= mid  && j<= h)
        {
            if (a[i] < a[j])
            {
                b[k] = a[i];
                i++;
                k++;
                count++;
            }
            else
            {
                b[k] = a[j];
                j++;
                k++;
                count++;
            }
        }
        while (i<= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
        while (j<=h)
        {
            b[k] = a[j];
            k++;
            j++;

        }

        for (int z = l ; z <= h; z++)
        {
            a[z] = b[z];
        }
    }

    static void merge_sort(int arr[], int l , int h)
    {
        if (l<h)
        {
            int mid = (l + h) / 2;
            merge_sort(arr, l, mid);
            merge_sort(arr, mid + 1, h);

            merge(arr, mid, l, h);
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
        int arr[] = {4,21,53,24,64,1,56,3,2};
        int n = arr.length;
        System.out.println("Unsorted array");
        print(arr,n);
        merge_sort(arr,0,n-1);
        System.out.println("\nSorted array : ");
        print(arr,n);
        System.out.println("\nCount = "+count);
    }
}
