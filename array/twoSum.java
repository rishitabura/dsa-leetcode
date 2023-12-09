package array;

public class twoSum {

    public static int[] twosum(int[] arr, int target)
    {
        int[] newArr = new int[2];
        for (int i = 0; i<arr.length; i++)
        {
            for (int j = 1; j<arr.length ; j++)
            {
                if (arr[i] +  arr[j] == target && i!=j)
                {
                    newArr[0] = i;
                    newArr[1] = j;
                    return newArr;
                }
            }
        }

        return arr;
    }
;
    public static void main(String[] args) {
        int[] arr = {2,5,5,11};

        int[] array = twosum(arr,10);
        for (int i = 0; i<array.length; i++)
        {
            System.out.print(array[i] + " ");
        }

    }
}

