#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector <vector <int> > g(n, vector <int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << g[i][j] << ' ';
        cout << endl;
    }
} 