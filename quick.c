#include <stdio.h>
#include <string.h>

char unconvert(int *number){
  char *result;
  result = (char*) number;
  return *result;
}
int convert(char letter){
  int value;
  value=(int)letter;
  return value;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      i++;
      
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quicksort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quicksort(array, low, pi - 1);
    
    quicksort(array, pi + 1, high);
  }
}

int main(int argc, char* argv[]){
  char word[50];
  int i;
  int j;
  char sorted[50];
  int array[50];
  printf("%d\n", 1);
  if(strlen(argv[1]) > 50){
    printf("Input too large!!\n");
    return 0;
  }else{
    strcpy(word, argv[1]);
  }
  for(i=0; i<strlen(word); i++){
    array[i] = convert(word[i]);
  }
  int size =strlen(word);
  quicksort(array, 0, size-1);
  for(j=0; j<strlen(word); j++){
    sorted[j] = unconvert(&array[j]);
  }
  printf("Sorted word is: \n%s \n", sorted);
  return 0;
}
