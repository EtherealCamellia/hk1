#include <stdio.h>

typedef struct index {
int left;
int right;
int sum;
} index_t;

index_t find_max_crossing_subarray(int* a, int low, int mid, int high)
{
int left_sum = 0x80000000;
int right_sum = 0x80000000;
int sum = 0;
int max_left, max_right;

int i;

index_t value;

for (i = mid; i >= low; i--) {
sum += a[i];
if (sum > left_sum) {
left_sum = sum;
max_left = i;
}
}

sum = 0;
for (i = mid + 1; i <= high; i++) {
sum += a[i];
if (sum > right_sum) {
right_sum = sum;
max_right = i;
}
}

value.left = max_left;
value.right = max_right;
value.sum = left_sum + right_sum;

return value;
}

index_t find_maximum_subarray(int *a, int low, int high)
{
index_t left_value, right_value, value;
int mid;

if (high == low) {
value.left = low;
value.right = high;
value.sum = a[low];
return value;
} else {
mid = (high + low)/2;
left_value = find_maximum_subarray(a, low, mid);
right_value = find_maximum_subarray(a, mid + 1, high);
value = find_max_crossing_subarray(a, low, mid, high);

if (left_value.sum >= right_value.sum && left_value.sum >= value.sum)
return left_value;
else if (right_value.sum >= left_value.sum && right_value.sum >= value.sum)
return right_value;
else
return value;
}
}

int main()
{
int i,x;
printf("输入数组元素个数");
scanf("%d",&x);
printf("输入数组元素\n");
int a[x];
for(i=0;i<x;i++)
{
scanf("%d",&a[i]);
}

index_t value;

value = find_maximum_subarray(a, 0, x-1);

printf("The maximum subarray is from %d to %d, sum is %d\n", value.left, value.right, value.sum);

return 0;
}
