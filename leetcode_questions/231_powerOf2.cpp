/*usig power function
tc - O(n)
sc - O(1)
TLE*/
bool isPowerOfTwo(int n)
{

    for (int i = 0; i < n; i++)
    {
        if (pow(2, i) == n)
        {
            return true;
        }
    }
    return false;
}

/*using division
tc - O(log n)
sc - O(1)*/
bool isPowerOfTwo(int n)
{

    if (n <= 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n == 1;
}

/*using division and recursion
tc - O(log n)
sc - O(log n)*/
bool isPowerOfTwo(int n)
{

    if (n <= 0)
    {
        return false;
    }

    return (n == 1 || (n % 2 == 0 && isPowerOfTwo(n / 2)));
}

/*using bit manipulation
tc - O(1)
sc - O(1)*/
bool isPowerOfTwo(int n)
{

    if (n <= 0)
    {
        return false;
    }
    return (n & (n - 1)) == 0 ? true : false;
}