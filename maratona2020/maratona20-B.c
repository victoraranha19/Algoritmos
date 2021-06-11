#include <stdio.h>

int main() {
    int n, d, l, r, c, fim=1;
    int grid[9][9];

    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            grid[i][j] = 0;
        }
    }

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d %d %d %d", &d, &l, &r, &c);
        c = c-1;
        r = r-1;
        if (d==0) {
            if ((c+l-1)>9) {
                fim=0;
                break;
            }
            for(int i=c;i<(c+l);i++) {
                grid[r][i] += 1;
            }
        } else {
            if ((r+l-1)>9) {
                fim=0;
                break;
            }
            for(int i=r;i<(r+l);i++) {
                grid[i][c] += 1;
            }
        }
    }

    int bloco;
    for (int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            bloco = grid[i][j];
            if (bloco>1) {
                fim = 0;
                break;
            }
        }
        if (bloco>1) {
            fim = 0;
            break;
        }
    }

    if (fim==0) {
        printf("N");
    } else {
        printf("Y");
    }
    return 0;
}