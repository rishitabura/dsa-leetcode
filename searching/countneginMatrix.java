package searching;

public class countneginMatrix {
    static public int countNegatives(int [][] grid)
    {
        int m = grid.length;
        int n = 0;
        int count = 0;
        for (int i = 0 ; i<m; i++)
        {
            n = grid[i].length;
        }
        for (int i = 0; i<m;i++)
        {
            for(int j = 0 ; j<n; j++)
            {
                if(grid[i][j] < 0)
                {
                    count++;
                }

            }
        }
        return count;


        // gives O(m+n) time complexity
//        public int countNegatives(int[][] grid) {
//        int count = 0, row = 0, col = grid[0].length -1;
//        while(col >= 0 && row < grid.length){
//            if(grid[row][col] < 0){
//                count += grid.length - row;
//                col--;
//            }else{
//                row++;
//            }
//        }
//        return count;
//    }

    }

    public static void main(String[] args) {

        int [][] grid = {{4,3,2,-1},
                        {3,2,1,-1},
                        {1,1,-1,-2},
                        {-1,-1,-2,-3}};
        int m = grid.length;
        int n = 0;
        for (int i = 0 ; i<m; i++)
        {
            n = grid[i].length;
        }
        System.out.println(countNegatives(grid));
//        System.out.println(m);
//        System.out.println(n);


    }
}
