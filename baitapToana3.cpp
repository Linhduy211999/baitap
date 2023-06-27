#include <iostream>
using namespace std;

const int MAX = 100;

int n;
double a[MAX][MAX];

double det()
{
    double res = 1;
    for (int i = 1; i <= n; i++) {
        int k = i;
        for (int j = i + 1; j <= n; j++) {
            if (abs(a[j][i]) > abs(a[k][i])) {
                k = j;
            }
        }
        if (abs(a[k][i]) < 1e-9) {
            return 0;
        }
        if (k != i) {
            swap(a[i], a[k]);
            res = -res;
        }
        res *= a[i][i];
        for (int j = i + 1; j <= n; j++) {
            a[i][j] /= a[i][i];
        }
        for (int j = 1; j <= n; j++) {
            if (j != i && abs(a[j][i]) > 1e-9) {
                for (int k = i + 1; k <= n; k++) {
                    a[j][k] -= a[i][k] * a[j][i];
                }
            }
        }
    }
    return res;
}

int main()
{
    cout << "Nhap kich thuoc ma tran: ";
    cin >> n;    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "Nhap cac phan tu thu "<< "a["<<i<<"]["<<j<<"]"<<endl ;
            cin >> a[i][j];
        }
    }
    cout << "Dinh thuc cua ma tran la: " << det() << endl;
    return 0;
}
