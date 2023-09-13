package leetcode_questions;

public class searchInsert {
    static  int searchInsertNum(int[] arr, int k)
    {
        int n = arr.length;
        for (int i = 0; i<n ; i++)
        {
            if (arr[i] == k)
            {
                return i;
            }
            else if (arr[i] > k)
            {
                return i;
            }
        }
        return  n;
    }
    public static void main(String[] args) {
        int[] arr = {1,3,5,6};

        int target = 5;
        System.out.println(searchInsertNum(arr, target));

    }
}
