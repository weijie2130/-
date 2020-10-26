

	int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
	{
		int *res = (int*)malloc(sizeof(int)*numsSize);
		*returnSize = numsSize;
		int i, j, count = 0;
		for (i = 0; i < numsSize; i++)
		{
			for (j = 0; j < numsSize; j++)
			{
				if (nums[i]>nums[j])
				{
					count++;
				}
				else
					continue;
			}
			res[i] = count;
			count = 0;
		}
		return res;
	}



