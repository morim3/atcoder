#include <iostream>
using namespace std;

int H, W;
int A[3000][3000];

int main(){
    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0;j<W; j++){
            cin >> A[i][j];
        }
    }

    int row_sum[3000];
    int column_sum[3000];

    for(int i=0; i<H; i++){
        int sum_i = 0;
        for(int j=0;j<W; j++){
            sum_i += A[i][j];
        }
        row_sum[i] = sum_i;
    }

    for(int i=0; i<W; i++){
        int sum_i = 0;
        for(int j=0;j<H; j++){
            sum_i += A[j][i];
        }
        column_sum[i] = sum_i;
    }

    for(int i=0; i<H; i++){
        for(int j=0;j<W-1; j++){
            cout << row_sum[i] + column_sum[j] - A[i][j];
            cout << " ";

        }
        cout << row_sum[i] + column_sum[W-1] - A[i][W-1];
        cout << endl;
        
    }


}