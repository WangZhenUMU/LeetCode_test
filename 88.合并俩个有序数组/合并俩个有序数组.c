void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int idx=m+n-1;
    int i=m-1,j=n-1;
    while(j>=0)
    {
        (i>=0&&nums1[i]>nums2[j])?
        (nums1[idx--]=nums1[i--]):(nums1[idx--]=nums2[j--]);
    }
}