#include<stdio.h>
#include<stdlib.h>
int search(int lowerlimit, int upperlimit, int halfpoint, int target, int array[]){
  if(array[halfpoint] > target){
    upperlimit=halfpoint;
    halfpoint=((lowerlimit+upperlimit)>>1);
    search(lowerlimit, upperlimit, halfpoint, target, array);
  }
  if(array[halfpoint] < target){
    lowerlimit=halfpoint;
    halfpoint=((lowerlimit+upperlimit)>>1);
    search(lowerlimit, upperlimit, halfpoint, target, array);
  }
  if(array[halfpoint] == target){
    return halfpoint;
  }
}
int main(int argc, char *argv[]){
  int array[argc];
  int target;
  int i;
  int answer;
  int mid=((argc-1)>>1);
  for (i=0; i<(argc-1); i++){
    array[i]=atoi(argv[i+1]);
  }
  while(1==1){
    printf("Enter number to find:\n");
    scanf("%d", &target);
    answer=search(0, argc-1, mid, target, array);
    printf("%d\n", answer+1);
  }
}
