package leetcode_questions;

public class palindrome {
    static boolean isPalindrome(int x)
    {
        int rem = 0;
        int rev = 0;
        int temp = x;
        while(temp!=0)
        {
            rem = temp%10;
            rev = (rev*10) + rem;
            temp /= 10;

        }
        if(rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE )
        {
            return false;
        }
        if (rev != x || x < 0)
        {
            return false;
        }
        else
        {
            return true;
        }

    }

    public static void main(String[] args) {
        int x = 121;
        boolean result = isPalindrome(x);
        if (result)
        {
            System.out.println("yes");
        }
        else
        {
            System.out.println("no");
        }


    }

}
