void sortColors(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
        int mini=i;

        for(int j=i+1;j<numsSize;j++){
            if(nums[mini]>nums[j]){
                mini=j;
            }
        }
        int temp=nums[i];
        nums[i]=nums[mini];
        nums[mini]=temp;
    }
}