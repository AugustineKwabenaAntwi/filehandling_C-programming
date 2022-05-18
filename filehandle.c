#include <stdio.h>
#include <stdlib.h>

#define N 2
int main (){
    // declaration of variables
    int i,j;
    float matrixA[N][N];
    float matrixB[N][N];
    float product[N][N];
    float transposeA[N][N];
    char frstMatFileQuery[1000];
    char secondMatFileQuery[1000];
    char resultMatFileQuery[1000];
    // program starts here
    FILE *matFIRST,*matSECOND,*matANSWER;
    printf("Please follow the instructions\n\n");

    printf("Please provide the file name of the first matrix eg.file.txt\n ");
    scanf("%s",frstMatFileQuery);

    printf("Please provide the file name of the second matrix eg.file.txt\n ");
    scanf("%s",secondMatFileQuery);

    printf("Please provide the file name to print the result eg.file.txt\n ");
    scanf("%s",resultMatFileQuery);
// taking input of first matrix
    matFIRST = fopen(frstMatFileQuery,"r");
    if (matFIRST !=NULL){
        for ( i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                fscanf(matFIRST,"%f",&matrixA[i][j]);
            }
            fscanf(matFIRST,"\n");
        }
        // print first matrix
        printf("This is the first matrix\n");
        for ( i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%f\t",matrixA[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        
        // transposing first matrix

        for (int i = 0; i < N; i++)
        {
        for (int j = 0; j < N; j++)
        {
            transposeA[j][i]=matrixA[i][j];
        }
        };
        printf("this is the transpose of the matrix\n");
        // print transpose 
        for ( i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%f\t",transposeA[i][j]);
            }
            printf("\n");
        }

        printf("\n");

    }else
    {
        printf("File cant be opened\n");
        exit(1);
    }

printf("\n\n");
// second matrix
    matSECOND = fopen(secondMatFileQuery,"r");
    if (matSECOND!=NULL)
    {
            for ( i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                fscanf(matSECOND,"%f",&matrixB[i][j]);
            }
            fscanf(matSECOND,"\n");
        }
        // print second matrix 
        // for ( i = 0; i < N; i++)
        // {
        //     for (j = 0; j < N; j++)
        //     {
        //         printf("%d",matrixB[i][j]);
        //     }
        //     printf("\n");
        // }
    }else
    {
        printf("File cant be opened\n");
        exit(1);
    }

    // matrix multiplication
    float sum = 0;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                sum = sum + (transposeA[i][k]*matrixB[k][j]);
            }
            product[i][j] = sum;
            sum = 0;
        }
    }
// printing product
printf("This is the product of the matrices\n\n");
for ( i=0;i<N;i++){
        for ( j=0;j<N;j++){
            printf("%f\t",product[i][j]);
        }
        printf("\n");
    }
// writing result to new or existing file
    matANSWER = fopen(resultMatFileQuery,"w");
    if (matANSWER == NULL)
    {
        printf("Unable to create or open the file");
    }else
    {
        for ( i=0;i<N;i++){
            for ( j=0;j<N;j++){
                fprintf(matANSWER,"%f\t",product[i][j]);
            }
        fprintf(matANSWER,"\n");
        }
    fclose(matANSWER);
    }





    fclose(matFIRST);
    fclose(matSECOND);

    return 0;
}