/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//感觉不算难，两层for把所有可能的数字组合遍历一遍然后记录并输出角标就好

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i=0,j=0;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* a=(int*)malloc(2*sizeof(int));
                *returnSize=2;//题干没说清楚，twosum函数返回的数组需要returnsize作为参考，因此这里要赋值2
                a[0]=i;
                a[1]=j;
                return a;
            }
        }
    }
    return 0;//分支里的return有可能没办法返回（尽管该题可以返回），编译器会以此报告异常，因此这里加return
}