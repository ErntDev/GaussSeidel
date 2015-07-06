#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

void ingresarCoeficientes(double *M[], int n)
{
    int i,j;

    puts("\n\tIngrese los coeficientes.");
    for (i=0;i<n;i++)
    {
        printf("\nEcuacion %d\n",i+1);
        for(j=0;j<n;j++) {
            printf("X%d: ",j+1);
            scanf("%lf",&M[i][j]);
        }
    }
    puts("\n\tIngrese cada uno de los terminos independientes.");

    for (i=0;i<n;i++)
    {
        printf("C%d: ",i+1);
        scanf("%lf",&M[i][n]);
    }
}

void mostrarSistemaEcuaciones(double *M[], int n)
{
    int i,j;
    puts("\n\t\tSistema de ecuaciones: ");
    for (i=0;i<n;i++)
    {
        printf("\t\t\t");
        for(j=0;j<n;j++)
            printf("%c%gx%d\t",M[i][j]>0?'+':8,M[i][j],j+1);
        printf("= %g\n",M[i][n]);
    }
}

void gaussSeidel(double *M[], int n, const int it)
{
    double *X,*Xant,suma;
    int i,j,k=0;

    X=(double*)calloc(n,sizeof(double));
    Xant=(double*)calloc(n,sizeof(double));

    for (i=0;i<n;i++)
        X[i]=0.0;

    while (k<it)
    {
        printf("\n%d Iteracion\n",k+1);

        for (i=0;i<n;i++)
        {
            suma=0;
            for (j=0;j<n;j++)
                {
                if (j==i)
                    continue;
                suma+=(M[i][j]*X[j]);
                }
            Xant[i]=X[i];
            X[i]=(M[i][n]-suma)/M[i][i];
            printf("X%d = %.9lf\n",i+1,X[i]);
        }
        k++;
    }
    calcularErrorAproximado(X,Xant,n);
}

void calcularErrorAproximado(double *Xact,double *Xant, int n)
{
    int i;
    double porcentaje;

    puts("\n\n");
    for (i=0;i<n;i++)
    {
        porcentaje=fabs(((Xact[i])-(Xant[i]))/(Xact[i]))*100;
        printf("\tEAx%d = %.3f%c\n",i+1,porcentaje,37);
    }

    puts("\n\tSolucion:");
    for (i=0;i<n;i++)
    {
        printf("\tx%d = %.2f\n",i+1,Xact[i]);
    }
}
