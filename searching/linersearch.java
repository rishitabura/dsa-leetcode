package searching;

public class linersearch {
    public static void main(String[] args) {
        int [] num = {4,2,1,55,32,11};
        linear_search(num,5);
    }

    static int linear_search(int []arr, int k)
    {
        if (arr.length == 0)
        {
            System.out.println("No array");
            return 0;
        }
        for (int i = 0; i < arr.length; i++)
        {
            if (arr[i] == k )
            {
                System.out.println("Number "+ k + " is present at index "+ i);
                return 0;
            }

        }
        return 0;

    }

}
