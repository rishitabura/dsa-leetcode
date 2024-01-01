// using binary approch
int firstOccurance(vector<int>& arr, int n, int x)
{
	int low = 0;
	int high = n-1;
	int first = -1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid] == x)
		{
			first = mid;
			high = mid-1;
		}
		else if(arr[mid] < x)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
		
    }
	return first;
    
}


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1;
    int count_max = 0;
    for(int i = 0; i<n; i++)
    {
        int firstOcc = firstOccurance(matrix[i], m, 1);
        if(firstOcc == -1)
        {
            int count_1s = 0;
        }
        else
        {
            int count_1s = m - firstOcc;
            {
            if (count_1s > count_max) {
                    count_max = count_1s;
                    index = i;
                }
            }
        }
    }
    return index;
}

// using 2 pointer approch
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
     int i = 0;
    int j = m-1;
    int index = 0;
    while(i<n && j>=0)
    {
        if(matrix[i][j] == 1){
            index = i;
            j--;
        }
        else{
            i++;
        }
    }
    return index;
}