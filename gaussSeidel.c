/*
Proyecto    :Programa para resolver un sistema de ecuaciones algebraicas lineales simultáneas por el método de Gauss-Seidel
Programa    :GaussSeidel.c
Autor       :Ernesto G. M.
*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    double **M;    //Guardar los coeficientes del sistema de ecuaciones
    int i,n,iter;

    puts("Programa para resolver un sistema de ecuaciones algebraicas lineales simultaneas");
    puts("\t\t\tpor el metodo de Gauss-Seidel");

    do
    {
        printf("\nNumero de ecuaciones [2-10]: ");
        scanf("%d",&n);
    } while (n<2 || n>10);

    M=(double**)calloc(n,sizeof(double*));

    for (i=0;i<n;i++)
        M[i]=(double*)calloc(n+1,sizeof(double));

    ingresarCoeficientes(M,n);
    mostrarSistemaEcuaciones(M,n);

    printf("Numero de iteraciones que desea realizar: ");
    scanf("%d",&iter);
    gaussSeidel(M,n,iter);

    return 0;
}
