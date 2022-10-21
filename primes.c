#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>
bool primecheck(int prime){
  int squareroot;
  int i;
  squareroot=sqrt(prime);
  for(i=3;i<=squareroot;i+=2){
    if(prime%i==0){
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]){
  int numtobechecked;
  int resultofprimecheck;
  int i;
  int maxnum=atoi(argv[1]);
  for(numtobechecked=1;numtobechecked<maxnum;numtobechecked++){
	  if(numtobechecked==2){
		  printf("2\n");
	  }
    if(numtobechecked%2!=0){
      resultofprimecheck=primecheck(numtobechecked);
      if(resultofprimecheck){
	printf("%d\n", numtobechecked);
      }
    }
  }
}
