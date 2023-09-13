package searching;

public class lexicalorder {
    static public char nextGreatestLetter(char[] letters, char target) {

//        int n = letters.length;
//        for(int i = 0 ; i < n ; i++)
//        {
//
//            if(letters[i].compareToIgnoreCase(target)>0)
//            {
//                return letters[i];
//            }
//        }
//        return letters[0];

        int n = letters.length;
        for(int i = 0 ; i < n ; i++)
        {

            if(letters[i] > target)
            {
                return letters[i];
            }
        }
        return letters[0];

    }
    public static void main(String args[])
    {
        char[] letters = {'c','f','j'};
        char target = 'c';
        System.out.println(nextGreatestLetter(letters,target));

    }
}
