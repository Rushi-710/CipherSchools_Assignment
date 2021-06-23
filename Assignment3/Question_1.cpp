// C++ code to find intersection
#include <bits/stdc++.h>
using namespace std;

// Function to find intersection
void intersection(int nums1[], int nums2[], int n, int m)
{
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (nums1[i] > nums2[j]) {
			j++;
		}
		else if (nums2[j] > nums1[i]) {
			i++;
		}
		else {
			cout << nums1[i] << " ";
			i++;
			j++;
		}
	}
}

int main()
{
	int nums1[] = { 4,9,5 };
	int nums2[] = { 9,4,9,8,4 };

	int n = sizeof(nums1) / sizeof(nums1[0]);
	int m = sizeof(nums2) / sizeof(nums2[0]);

	// sort
	sort(nums1, nums1 + n);
	sort(nums2, nums2 + m);
	
	// Function call
	cout << "Intersection of two arrays is : " << endl;
	intersection(nums1, nums2, n, m);
}
