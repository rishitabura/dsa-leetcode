#include<bits/stdc++.h>
int floorFind(vector<int> &a, int n, int x)
{
	int l = 0;
	int h = n-1;
	int floorVal = -1;
	while(l<=h)
	{
		int mid = (l+h)/2;

		if(a[mid] <= x)
		{
			floorVal = a[mid];
			l = mid+1;
		}
		else
		{
			h = mid-1;
		}
	}
	return floorVal;
}

int ceilFind(vector<int> &a, int n, int x)
{
	int l = 0;
	int h = n-1;
	int ceilVal = -1;
	while(l<=h)
	{
		int mid = (l+h)/2;

		if(a[mid] >= x)
		{
			ceilVal = a[mid];
			h = mid-1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return ceilVal;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int f = floorFind(a, n, x);
	int c = ceilFind(a, n, x);

	return  make_pair(f,c);

}