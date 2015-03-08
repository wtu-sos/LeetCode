#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int idx = 0;
		int count = m+n; 
		int mid = count/2;
		int a = 0;
		int b = 0;
		double result;

		if (count == 0)
			return 0;
		else if (count == 1)
		{
			if (m == 1)
				return A[0];
			else
				return B[0];
		}
		
		while (idx <= mid)
		{
			if (a<m && b<n)
			{
				if (A[a] > B[b]){
					result = B[b];
					b++;
				} else {
					result = A[a];
					a++;
				}
			}
			else if (a<m && b>=n)
			{
				result = A[a++];
			}
			else if (a>=m && b<n)
			{
				result = B[b++];
			}
			idx++;

			if (idx == mid && count%2 == 0)
			{
				if (a<m && b<n)
				{
					if (A[a] > B[b]){
						result = (B[b]+result)/2;
					} else {
						result = (A[a]+result)/2;
					}
				}
				else if (a<m && b>=n)
				{
					result = (A[a]+result)/2;
				}
				else if (a>=m && b<n)
				{
					result = (B[b]+result)/2;
				}
				idx++;
			}
		}

		return result;
    }
};

int main()
{
	int A[] = {};
	int B[] = {1,2};
	Solution s;
	double r = s.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));
	//double r = s.findMedianSortedArrays(A, 0, B, sizeof(B)/sizeof(int));
	cout << r;
	return 0;
}
