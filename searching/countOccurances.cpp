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
int lastOccurance(vector<int>& arr, int n, int x)
{
	int low = 0;
	int high = n-1;
	int last = -1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid] == x)
		{
			last = mid;
			low = mid+1;
		}
		else if(arr[mid] > x)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
		
    }
	return last;
}

int count(vector<int>& arr, int n, int x) {
	int f = firstOccurance(arr,  n,  x);
	int l = lastOccurance(arr,  n,  x);
	if(f==-1)return 0;
	return l-f+1;

	
	
}
