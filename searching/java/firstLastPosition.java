package searching.java;

class firstLastPosition {

    static public int first(int [] nums, int target)
    {
        int ans = -1;
        int l = 0;
        int h = nums.length-1;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(nums[m] == target)
            {
                ans = m;
                h = m-1;
            }
            else if(nums[m] > target)
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
    static public int last(int [] nums, int target)
    {
        int ans = -1;
        int l = 0;
        int h = nums.length-1;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(nums[m] == target)
            {
                ans = m;
                l = m+1;
            }
            else if(nums[m] > target)
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }

    static public int[] searchRange(int[] nums, int target) {
        return  new int[]{first(nums,target), last(nums, target)};
    }

    public static void main(String[] args) {
        int [] arr= {5,7,7,8,8,10};
        int k = 8;

        int [] result = searchRange(arr,k);
        if (result[0] == -1 && result[1] == -1)
        {
            System.out.println("["+result[0]+","+result[1]+"]");
        }
        else
        {
            System.out.println("["+result[0]+","+result[1]+"]");
        }
    }
}