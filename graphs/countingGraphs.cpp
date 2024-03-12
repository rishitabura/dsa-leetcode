// no of undirected graphs with disconnected components allowed
int countingGraphs(int N)
{
    if(N ==1 || N == 0)
    {
        return N;
    }

    return pow(2, N*(N-1)/2);
}