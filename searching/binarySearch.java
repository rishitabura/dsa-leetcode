package searching;


public class binarySearch {
    static int search(int[] arr,int k )
    {
//        Arrays.sort(arr);
        int l = 0, m;
        int h = arr.length-1;
        while (l<=h)
        {
            m = l+(h-l)/2;
            if (arr[m] == k)
            {
                return  m   ;
            }
            if (arr[m] > k)
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        int [] arr = {-1,0,3,5,9,12};
        // int n = arr.length;
        int target = 2;

        int s = search(arr,target);
        if (s == -1)
        {
            System.out.println(target+ " is not present in the array");
        }
        else
        {
            System.out.println(target+ " is present in the array at the index " +s);
        }


    }
}
