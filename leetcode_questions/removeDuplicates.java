

public class removeDuplicates {
    static void duplicates(int[] nums)
    {
        int[] temp = new int[nums.length];
        int j = 0;
        for(int i = 1; i<nums.length ; i++)
        {
            if(nums[i-1] != nums[i])
            {
                temp[j++] = nums[i-1];
            }
        }
        temp[j++] = nums[nums.length-1];
        for(int i = 0 ; i<j; i++)
        {
            nums[i] = temp[i];
        }


        for (int i = 0; i<j; i++)
        {
            nums[i] = temp[i];
            System.out.print(nums[i] + " ");
        }
//        return j;
    }
    public static void main(String[] args) {
        int[] arr = {1,1,2};
        duplicates(arr);
    }
}
