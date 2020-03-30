//
//  LeetCode_TwoSum.c
//  LeetCode_Practice
//
//  Created by weiren Lan on 2020/3/28.
//  Copyright © 2020年 weiren Lan. All rights reserved.
//

#include "LeetCode_TwoSum.h"
#include <stdlib.h>

//Brute Force Algorithm
int* twoSum( int* nums, int numsSize, int target ){
    
    int lastNum;
    int *returnIndices = malloc(sizeof(int)*2);
    
    
    for( int i = 0; i<numsSize ;i++ )
    {
        if( *(nums+i) < target )
        {   *returnIndices = i;
            lastNum = target - *(nums+i);
            
            for(int j=0;j<numsSize; j++)
            {
                if( j != i )
                {
                    if( *(nums+j) == lastNum )
                    {
                        *( returnIndices+1 ) = j;
                        goto out;
                    }
                }
            }
        }
    }
out:
    return returnIndices;
    
}


void Test_TwoSum(void)
{
    int Testcase[7] = {2, 19, 6, 10,18,5,7};
    int numSize = 7;
    int target = 28;
    int *result;
    result = twoSum(Testcase,numSize,target);
    
    for(int i = 0; i<2; i++)
    {
        printf("result[0]:%d",result[i]);
        printf("\n");
    }
    
}
