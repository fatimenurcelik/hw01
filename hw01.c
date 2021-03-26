#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[])
{
    int **a;
    int **b;
    int **transposeB;
    int **mul;
    int i,j,k,limit;
    limit=atoi(argv[1]);
    
    a=(int**)malloc(sizeof(int)*limit);
    for(i=0;i<limit;i++){
        a[i]=(int*)malloc(sizeof(int)*limit);
        for(j=0;j<limit;j++){
            a[i][j]=i+j;
        }    
    }
    
    b=(int**)malloc(sizeof(int)*limit);
    for(i=0;i<limit;i++){
        b[i]=(int*)malloc(sizeof(int)*limit);
        for(j=0;j<limit;j++){
            b[i][j]=i+j;
        }    
    }
    
    transposeB=(int**)malloc(sizeof(int)*limit);
    for(i=0;i<limit;i++){
        transposeB[i]=(int*)malloc(sizeof(int)*limit);
        for(j=0;j<limit;j++){
            transposeB[i][j]=b[j][i];
        }    
    }
    
    clock_t t;
    t = clock();
    
    mul=(int**)malloc(sizeof(int)*limit);
    for(i=0;i<limit;i++){
        mul[i]=(int*)malloc(sizeof(int)*limit);
        for(j=0;j<limit;j++){
            mul[i][j]=0;
            for(k=0;k<limit;k++){
            mul[i][j]+=a[i][k]*transposeB[j][k];
            }
        }    
    }
    
    t = clock() - t;
    
    clock_t t2;
    t2 = clock();
    
    for(i=0;i<limit;i++){
        for(j=0;j<limit;j++){
            mul[i][j]=0;
            for(k=0;k<limit;k++){
            mul[i][j]+=a[i][k]*b[k][j];
            }
        }    
    }
    
    t2 = clock() - t2;
    
   double time_taken = ((double)t)/CLOCKS_PER_SEC;
   double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
   printf("The program took %f seconds to execute(cache friendly)", time_taken);
   printf("The program took %f seconds to execute(traditional method)", time_taken2);
    printf("\n");
}
