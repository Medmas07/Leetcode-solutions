void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for(int i=m-1;i!=-1;i--)
    {
        nums1[i+n]=nums1[i];
    }
    int i,j,k;    
    for(i=0,j=0,k=0;k<nums1Size && i<m && j<n;k++)
    {
        if(nums1[i+n]<nums2[j])
        {
            nums1[k]=nums1[i+n];
            nums1[i+n]=0;
            i++;
        }
        else 
        {
            nums1[k]=nums2[j];
            j++;
        }
    }
    if(i<m)
        for(i;i<m;i++)
        { nums1[k]=nums1[i+n];k++;}
    else if (j<n)
        for(j;j<n;j++)
        {nums1[k]=nums2[j];k++;}
}