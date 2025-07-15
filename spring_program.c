#include <stdio.h>
#include <math.h>
#include <complex.h>

// Hを計算する関数（変更なし）
double complex calculate_H(double dy, double d2y, double d3y, int n)
{
    double theta2 = atan(dy);
    double theta3 = atan(d2y);
    double theta4 = atan(d3y);
    double complex h2 = cexp(I * theta2);
    double complex h3 = cexp(I * theta3);
    double complex h4 = cexp(I * theta4);
    double complex H1 = (h2 + h3 + h4) / 3.0;
    double complex H2 = h2 * h3 * h4;
    double complex H = csqrt(H1 * H2) * pow(2.0, -n);
    return H;
}

int main(void)
{
    // --- シミュレーションのパラメータ設定 ---
    const int n = 4;
    double y = 1.0;         // 初期位置
    double y_prime = 0.0;   // 初速度
    const double dt = 0.01; // 時間の刻み幅
    const double total_time = 100.0;

    FILE *fp = fopen("spring_rk4.dat", "w");
    if (fp == NULL)
    {
        printf("ファイルを開けません。\n");
        return 1;
    }

    // --- シミュレーションループ ---
    for (double t = 0; t < total_time; t += dt)
    {
        // 現在の指紋Hを計算
        double dy = y_prime;
        double d2y = -y;
        double d3y = -y_prime;
        double complex H = calculate_H(dy, d2y, d3y, n);

        // 指紋Hの座標をファイルに書き出す
        if (isfinite(creal(H)) && isfinite(cimag(H)))
        {
            fprintf(fp, "%f,%f\n", creal(H), cimag(H));
        }

        // --- ★★★ ここが変更点（4次のルンゲ＝クッタ法） ★★★ ---
        // 中間的な傾き（k）を4つ計算する
        double k1_y = y_prime;
        double k1_yp = -y;

        double k2_y = y_prime + 0.5 * dt * k1_yp;
        double k2_yp = -(y + 0.5 * dt * k1_y);

        double k3_y = y_prime + 0.5 * dt * k2_yp;
        double k3_yp = -(y + 0.5 * dt * k2_y);

        double k4_y = y_prime + dt * k3_yp;
        double k4_yp = -(y + dt * k3_y);

        // 4つの傾きを重み付けして平均し、次の状態を更新
        y = y + (dt / 6.0) * (k1_y + 2.0 * k2_y + 2.0 * k3_y + k4_y);
        y_prime = y_prime + (dt / 6.0) * (k1_yp + 2.0 * k2_yp + 2.0 * k3_yp + k4_yp);
    }

    fclose(fp);
    printf("RK4によるバネの指紋データ 'spring_rk4.dat' が生成されました。\n");
    return 0;
}
