#include <iostream>
using namespace std;

int m, n, i, j, v, k;
float **a, f, z;

void ladder(float **a)
{
    for (i = 0; i < n - 1; i++)
    {
        v = i; 
        for (j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[v][i])) v = j;//в еще не пройденных строках находим строку с наибольшим i-м элементом(текущая ступенька)
        if (v != i)
            for (j = i; j <= n; j++)//меняем местами строку с наибольшим i-м элементом и текущую строку матрицы
            {
                z = a[i][j];
                a[i][j] = a[v][j];
                a[v][j] = z;
            }
        for (k = i + 1; k < n; k++)//проходим только по строкам которые еще не заняли нужные места в лесенке
        {
            z = a[k][i] / a[i][i];//находим коэффициент разности i-х элементов строк
            for (j = i; j <= n; j++)
                a[k][j] -= z * a[i][j];//отнимаем от одной строки другую z раз(таким образом зануляем i-й элемент)
        }
    }

}

int main()
{
    FILE* fl = fopen("test1.txt", "rt");
    FILE* fm = fopen("ou.txt", "at");
    fscanf(fl, "%d%d", &m, &n);

    a = new float* [m];
    for (i = 0; i < n; i++) a[i] = new float[n];

    for (i = 0; i < m; i++)
        for (j = 0; j <= n; j++)
            fscanf(fl, "%f", &a[i][j]);

    ladder(a);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j <= n; j++) fprintf(fm, "%f%c", a[i][j], ' ');
        fprintf(fm, "\n");
    }
    fprintf(fm, "\n");
}