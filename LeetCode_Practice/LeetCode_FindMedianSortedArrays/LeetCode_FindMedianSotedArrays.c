//
//  LeetCode_FindMedianSotedArrays.c
//  LeetCode_Practice
//
//  Created by weiren Lan on 2020/3/31.
//  Copyright © 2020年 weiren Lan. All rights reserved.
//

#include "LeetCode_FindMedianSotedArrays.h"
#include <stdlib.h>



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    double median = 0;
    int i=0; int j=0;
    int *nums_FindMedian = malloc((nums1Size+nums2Size)*sizeof(int));
    
    
    for(int k = 0; k<(nums1Size+nums2Size) ;k++)
    {
        if( (i<nums1Size) && (j<nums2Size) )
        {  if(*(nums1+i) <= *(nums2+j))
        {
            *(nums_FindMedian+k) = *(nums1+i) ;
            i++;
        }
        else
        {
            *(nums_FindMedian+k) = *(nums2+j) ;
            j++;
        }
        }
        else if( (i<nums1Size) && (j==nums2Size) )
        {
            *(nums_FindMedian+k) = *(nums1+i) ;
            i++;
        }
        else if( (i==nums1Size) && (j<nums2Size) )
        {
            *(nums_FindMedian+k) = *(nums2+j) ;
            j++;
        }
        
    }
    
    if( (nums1Size+nums2Size) % 2 )
    {
        median =  *(nums_FindMedian+ (nums1Size+nums2Size)/2) ;
    }
    else
    {   int median_index = (nums1Size+nums2Size)/2;
        median =  (nums_FindMedian[median_index] +nums_FindMedian[median_index-1])/2.0;
    }
    
    return median;
}


void Test_findMedianSortedArrays(void)
{
    int sorted_nums1[5] = {1,6,7,21,79};
    int sorted_nums2[4] = {3,12,29,33};
    
    int nums1Size = 5;
    int nums2Size = 4;
    
    double median_Result =     findMedianSortedArrays(sorted_nums1,nums1Size,sorted_nums2,nums2Size);
    printf("median_Result: %f",median_Result);
}
