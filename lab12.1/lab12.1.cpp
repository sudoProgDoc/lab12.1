#include <iostream>
using namespace std;

int m, n, i, j, v, k;
float **a, f, c, z;

void ladder(float **a)
{
    for (i = 0; i < n - 1; i++)
    {
        v = i; 
        for (j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[v][i])) v = j;
        if (v != i)
            for (j = i; j <= n; j++)
            {
                z = a[i][j];
                a[i][j] = a[v][j];
                a[v][j] = z;
            }
        for (k = i + 1; k < n; k++)
        {
            c = a[k][i] / a[i][i];
            for (j = i; j <= n; j++)
                a[k][j] -= c * a[i][j];
        }
    }

}

int main()
{
    FILE* fl = fopen("test1.txt", "rt");
    FILE* fm = fopen("ou.txt", "at");
    fscanf(fl, "%d", &m);
    fscanf(fl, "%d", &n);
    a = new float* [m];
    for (i = 0; i < n; i++) a[i] = new float[n];

    for (i = 0; i < m; i++)
        for (j = 0; j <= n; j++)
        {
            fscanf(fl, "%f", &f);
            a[i][j] = f;
        }

    ladder(a);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            fprintf(fm,"%f", a[i][j]);
            fprintf(fm, " ");
        }
        fprintf(fm, "\n");
    }
}