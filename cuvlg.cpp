#include <fstream>
#include <cstring>
#define NMAX 39
#define LGMAX_CUV 31
using namespace std;
ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");
int pozitieCuvant(int, char [][LGMAX_CUV], int [], int);
void insereaza(int, int, int [], int&);
int main()
{
    int n, lg, i, poz, v[NMAX], lgv;
    char cuv[NMAX][LGMAX_CUV];
    fin >> n >> lg;
    fin.get(); // sar peste newline
    for (lgv = i = 0; i < n; i++)
    {
        fin.getline(cuv[i], LGMAX_CUV);
        if (strlen(cuv[i]) == lg)
        {
            poz = pozitieCuvant(i, cuv, v, lgv);
            insereaza(i, poz, v, lgv);
        }
    }
    for (i = 0; i < lgv; i++)
        fout << cuv[v[i]] << '\n';
    return 0;
}
void insereaza(int x, int poz, int v[], int& lgv)
{
    // insereaza pe x la pozitia poz in vectorul v de lungime lgv
    for (int i = lgv; i > poz; i--) v[i] = v[i-1];
    v[poz] = x;
    lgv++;
}
int pozitieCuvant(int i, char cuv[][LGMAX_CUV], int v[], int lgv)
{
    // cauta pozitia cuvantului cuv[i]
    // in vectorul de pozitii (sortat crescator) v de lungime lgv
    int st, dr, mij;
    st = -1, dr = lgv;
    while (dr-st > 1)
    {
        mij = st + (dr-st)/2;
        if (strcmp(cuv[v[mij]], cuv[i]) < 0)
            st = mij;
        else
            dr = mij;
    }
    return dr;
}
