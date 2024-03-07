#include <stdio.h>
#include <string.h>
#include <math.h>


void ascendingNumbers(int num){ //printing i, ptr
    int i,j;
     for(i=1;i<=num;i++){
       for(j=1;j<=i;j++){
            printf("%d ",i);
        }
      printf("\n");
  }
}

void polydirectionalNumbers(int num){ //printing i;
    printf("\n");
    int i,j;
     for(i=1;i<=num;i++){
        //for(i=1;i<=num;i++){
       //for(i=num;i>=1;i--){
         for(j=1;j<=num;j++){
      //for(j=num;j>=1;j--){
      // for(j=1;j<=num;j++){
            printf("%d ",i);
        }
      printf("\n");
  }
}

void upperChar(int num){ //printing j;
    int i,j;
     for(i=num-1;i>=1;i--){
       for(j=0;j<num;j++){
            printf("%c ",j+65); //change val to 97 for lowercase;
        }
      printf("\n");
  }
}

 void allChar(int num){ //rem opposites '<='  != '>'
int a;
printf("\n");
    for(a=0;a<num;a++){
     printf("%c ",32+a);
    }
 }
 
 void pascalTriangle1(int num){ //*ptr
         int i,j;
     for(i=0;i<=num;i++){ //decrease + positive( j<=i ) = +ve gradient;
       for(j=0;j<i;j++){  //increase + positive = -ve gradient;
            printf("* ");
        }
      printf("\n");
  }
 }
 
  void pascalTriangle2(int num){ //*ptr
      int i,j;
     for(i=num-1;i>0;i--){
       for(j=0;j<i;j++){
            printf("* ");
        }
      printf("\n");  
  }
  
 }
 
 void pascalTriangle3(int num){ //char ptr down
      int i,j;
      printf("\n");
     for(i=num;i>=1;i--){
       for(j=0;j<i;j++){
            printf("%c ",i+96);
        }
      printf("\n");  
  }
 }
 
   void pascalTriangle4(int num){ //char ptr up
      int i,j;
     for(i=1;i<=num;i++){
       for(j=0;j<i;j++){
            printf("%c ",i+97); //change val=96 for starting with a ;
        }                        //change val=64 for starting with A;
      printf("\n");  
  }
 }
 void pascalTriangle5(int num){ //downbased ptriangle; +vegradient;
 	 int i,j,k;
    printf("triangle 1\n");
	for (i = 1; i <= num; i++) {
    for ( j = num; j > i; j--) {
        printf(" ");
    }
    for ( k = 1; k <= i; k++) {
        printf("*");
    }
    printf("\n");
}	
 }
 
 void ptriangle(){
    int num;
    printf("Enter the height of triangle: ");
    scanf("%d",&num);
    int c,r, pt[10][10];
  for(r=0;r<num;r++){
for(c=0;c<num;c++){
if(c<=r){
if(c==r || c==0)
pt[r][c]=1;
else
pt[r][c]=pt[r-1][c]+pt[r-1][c-1];
     printf(pt[r][c] < 10 ? "0%d " : "%d " ,pt[r][c]);
      }
   }
printf("\n");
  }  
}


void zletter(int num){
    int i,j;
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(i==0 || i==num-1){
                printf("*");
            }
            else if(j+i==num-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void dletter(){
     int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if((i==0 || i==4) && (j!=4)){
                printf("*");
            }
            else if((j==0) || (j==4 && (i==1 ||
            i==3 || i==2))){
                printf("*");
            }
            else if(j==4){
                printf("");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void advancedPtr(){ //*ptr
       int number;
    
    while (1) { //repeate until -ve no is input;
        printf("Enter a number: ");
        scanf("%d", &number);
        
        if (number < 0) {
            printf("Negative number entered. Exiting loop.\n");
            break; // Exit the loop
        }
         int i,j;
     for(i=0;i<number-1;i++){
       for(j=0;j<i;j++){
            printf("* ");
        }
      printf("\n");  
  }
    }
    
    printf("Program ended.\n");
  
 }
 
int  main(){
  ascendingNumbers(6); 
  polydirectionalNumbers(6);
  printf("\n");
  upperChar(4);
  allChar(95);
  pascalTriangle1(5);
  pascalTriangle2(5);
  pascalTriangle3(5);
  pascalTriangle4(5);
pascalTriangle5(5);
printf("\n");
  zletter(5);
  dletter();
//advancedPtr();

int i,j;
printf("\n");
for(i=0;i<6;i++){ //increasing, decreasing (topbased ptriangle) +ve gradient;
    for(j=6;j>i;j--){
        printf("*");
    }
    printf("\n");
}

for(i=0;i<6;i++){ //increasing, increasing    ^
    for(j=0;j<6-i;j++){
        printf("*");
    }
    printf("\n");
}

//all char
  int a;
  printf("\n");
for(a=0;a<64;a++){
     printf("%c ",64+a);
}
  return 0;
}
