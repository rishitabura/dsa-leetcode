// package leetcode_questions;

import java.util.Locale;

public class validPalindrome {
    static boolean isPalindrome(String s)
    {
////        System.out.println(s);
//        s = s.replaceAll("[!@#$%^&*.,:;']","");
////        System.out.println(s);
//        char[] arr = s.toCharArray();
//        String temp = "";
//        for (char num : arr)
//        {
//            if(num < 'a' && num > 'z' || num < 'A' && num > 'Z' || num != ' ')
//            {
//                temp+=num;
//            }
//        }
//        String temp1= temp.toLowerCase();
//        String str = temp1;
//        System.out.println(temp1);
//        System.out.println(str);
//        char [] a1 = temp1.toCharArray();
//        char[] a2 = str.toCharArray();
//
//        for (int i = 1 ; i<a1.length; i++)
//        {
//            for (int j = a2.length; j<0; j--)
//            {
//                if (a1[i] == a2[j])
//                {
//                    return true;
//                }
//
//            }
//        }
//        return false;

        s = s.replaceAll("[^a-zA-Z0-9]", ""); // Keep only alphabetic characters
        s = s.toLowerCase(); // Convert to lowercase for case-insensitive comparison
        System.out.println(s);

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false; // Characters don't match, not a palindrome
            }
            left++;
            right--;
        }

        return true; // All characters matched, it's a palindrome

    }
    public static void main(String[] args) {
        String str = "00P";
        boolean r = isPalindrome(str);
        if (r)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("no");
        }

    }
}
