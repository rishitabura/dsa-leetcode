package searching;

public class binarySerachInsert {
    static public int searchInsert(int[] arr, int n , int k)
    {

        for(int i = 0; i < n; i++)
        {
            if(arr[i] == k)
            {
                return i;
            }
            else if(arr[i] > k)
            {
                return i;
            }


        }
        return n;
    }

    public static void main(String args[])
    {
        int[] arr = {1,3,5,6};
        int n = arr.length;
        int target = 2;
        System.out.println(searchInsert(arr,n,target));


    }

}