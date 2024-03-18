/*Brute force
tc - O(n)*/
/*sc - O(1)*/
class Solution
{
public:
    int pivotInteger(int n)
    {

        int sum = n * (n + 1) / 2;

        for (int i = 1; i <= n; i++)
        {
            int a = i * (i + 1) / 2;
            int b = sum - a + i;
            if (a == b)
            {
                return i;
            }
        }
        return -1;
    }
};

/*binary search
tc - O(logn)*/
class Solution
{
public:
    int pivotInteger(int n)
    {

        int l = 1;
        int h = n;
        int sum = n * (n + 1) / 2;

        while (l <= h)
        {
            int mid = (h + l) / 2;
            int a = mid * (mid + 1) / 2;
            int b = sum - a + mid;
            if (a == b)
            {
                return mid;
            }
            else if (a < b)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return -1;
    }
};