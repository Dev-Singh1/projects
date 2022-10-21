#include <stdio.h>
#include <string.h>

 void merge(int arr[], int l, int m, int r){  
   int i, j, k;  
   int n1 = m - l + 1;  
   int n2 = r - m;  
   
   int L[n1], R[n2];  
   
   for (i = 0; i < n1; i++)  
     L[i] = arr[l + i];  
   for (j = 0; j < n2; j++)  
     R[j] = arr[m + 1 + j];  
   
   i = 0;   
   
   j = 0;   
   
   k = l;   
   while (i < n1 && j < n2){  
     if (L[i] <= R[j]){  
       arr[k] = L[i];  
       i++;  
     }  
     else{  
       arr[k] = R[j];  
       j++;  
     }  
     k++;  
   }  
   
   while (i < n1) {  
     arr[k] = L[i];  
     i++;  
     k++;  
   }  
   
   while (j < n2){  
     arr[k] = R[j];  
     j++;  
     k++;  
   }  
 }

void mergesort(int arr[], int l, int r){  
  if (l < r){  
    int m = l + (r - l) / 2;  
    
    mergesort(arr, l, m);  
    mergesort(arr, m + 1, r);  
    
    merge(arr, l, m, r);  
  }  
}

int convert(char letter){
  int value;
  value=(int)letter;
  return value;
}

char unconvert(int *number){
  char *result;
  result = (char*) number;
  return *result;
}

int main(int argc, char* argv[]){
  char word[50];
  int i;
  int j;
  char sorted[50];
  int array[50];
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
  mergesort(array, 0, size-1);
  for(j=0; j<strlen(word); j++){
    sorted[j] = unconvert(&array[j]);
  }
  printf("Sorted word is:\n%s\n", sorted);
  return 0;
}
