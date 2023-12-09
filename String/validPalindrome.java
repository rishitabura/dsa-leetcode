package String;

public class validPalindrome {
    public static boolean isPalindrome(String s) {

        s = s.replaceAll("[^A-Za-z0-9]","");
        s = s.toLowerCase();
        int l = 0;
        int k = s.length() -1;
        while(l<k)
        {
            if(s.charAt(l) != s.charAt(k))
            {
                return false;
            }
            l++;
            k--;
        }
        return true;

    }

    public static void main(String[] args) {
        String s = "A man, a plan, a canal: Panama";
        System.out.println(isPalindrome(s));

    }
}
