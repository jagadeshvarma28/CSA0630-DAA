#include <stdio.h>
void printSubset(int subset[], int n) 
{
  for (int i = 0; i < n; i++) 
  {
    printf("%d ", subset[i]);
  }
  printf("\n");
}
int isSubsetSum(int subset[], int n, int sum) 
{
  int subsetSum = 0;
  for (int i = 0; i < n; i++) 
  {
    subsetSum += subset[i];
  }
  return (subsetSum == sum);
}
void findSubsets(int set[], int n, int sum, int index, int subset[]) 
{
  if (isSubsetSum(subset, index, sum)) 
  {
    printSubset(subset, index);
    return;
  }
  if (index == n) 
  {
    return;
  }
  subset[index] = set[index];
  findSubsets(set, n, sum, index + 1, subset);
  subset[index] = 0;
  findSubsets(set, n, sum, index + 1, subset);
}
int main() {
  int set[] = {1, 2, 3, 4, 5};
  int n = sizeof(set) / sizeof(set[0]);
  int sum = 10;

  int subset[n];
  findSubsets(set, n, sum, 0, subset);

  return 0;
}
