#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"./core.h"

const double eta = 0.1; //学習率
// const size_t epoch = 10; //学習回数
enum {epoch = 10}; //配列の添字にしたいのでconst intはNG
double convergence_error_array[epoch];
const double convergence_error = 0.0001; //誤差の最低値
double w[3] = {[2] = 1.0}; //重みベクトル

double f(double, double, double); //rmse用なくてもいいが見にくいので実装

int main(){
    
    FILE *data_file = fopen("data.txt", "r");
    Data data; 
    
    if(data_file == NULL){
        fprintf(stderr, "data_file open error\n");
        exit(1);
    }

    data_init(&data, count_line(data_file));
    data_input(data_file, &data);

    FILE *pipe = popen("gnuplot -persist", "w");
    FILE *pipe2 = popen("gnuplot -persist", "w");

    if(pipe == NULL){
        fprintf(stderr, "popen error\n");
        exit(1);
    }

    if(pipe2 == NULL){
        fprintf(stderr, "popen error\n");
        exit(1);
    }

    fprintf(pipe, "set xrange [-75:75]\n"); //描画範囲は任意
    fprintf(pipe, "set yrange [-75:75]\n"); //描画範囲は任意
    fprintf(pipe, "set xlabel 'english points'\n");
    fprintf(pipe, "set ylabel 'math points'\n");
    // fprintf(pipe, "set terminal gif animate optimize delay 13 size 600, 600\n"); //gifへ出力 必要ないならコメントアウト
    // fprintf(pipe, "set output 'machine_leaening.gif'\n"); //gifへ出力 必要ないならコメントアウト

    fprintf(pipe2, "set xrange [-1:%d]\n",epoch);
    fprintf(pipe2, "set yrange [-1:100]\n");
    fprintf(pipe2, "set xlabel 'epoch'\n");
    fprintf(pipe2, "set ylabel 'convergence_error'\n");
    // fprintf(pipe2, "set terminal gif animate optimize delay 13 size 600, 600\n"); //gifへ出力 必要ないならコメントアウト
    // fprintf(pipe2, "set output 'rmse.gif'\n"); //gifへ出力 必要ないならコメントアウト

    double ave_math = 0.0; //中心化のためのデータの平均値
    double ave_english = 0.0; //中心化のためのデータの平均値

    for(size_t i = 0; i < count_line(data_file); i++){ //平均値を取るためにデータの合計を取得
        ave_english += data.english[i];
        ave_math += data.math[i];
    }

    ave_english /= count_line(data_file); //平均
    ave_math /= count_line(data_file); //平均

    for(size_t i = 0; i < count_line(data_file); i++){ //中心化処理
        data.english[i] -= ave_english;
        data.math[i] -= ave_math;
    }

    for(size_t i = 0; i < epoch; i++){ //学習階数分forを回す
        double rmse = 0.0; //エポックごとに誤差を出す

        for(size_t j = 0; j < count_line(data_file); j++){ //誤差(rmse)の計算
            int error = data.flag[j] - step(w[0], w[1], w[2], data.english[j], data.math[j]);
            if(error != 0){
                rmse += pow(data.math[j] - f(-(w[0] / w[1]), -(w[2] / w[1]), data.english[j]), 2.0);
            }
        }

        rmse = sqrt(rmse / count_line(data_file));

        convergence_error_array[i] = rmse; //gnuplotにプロットするために誤差を配列へ代入

        fprintf(pipe2, "plot '-' with points\n"); //誤差用のプロット
        for(size_t j = 0; j <= i; j++){
            fprintf(pipe2, "%zd %f\n", j, convergence_error_array[j]);
        }fprintf(pipe2, "e\n");

        fflush(pipe2); //フラッシュしないとpcloseのタイミングで描画されるので

        printf("%f\n", rmse);
        if(rmse < convergence_error) break; //誤差が一定に達したらbreakで終了

        for(size_t j = 0; j < count_line(data_file); j++){ //パッチ勾配降下法
            int error = data.flag[j] - step(w[0], w[1], w[2], data.english[j], data.math[j]);
            if(error != 0){
                w[0] += eta * error * data.english[j];
                w[1] += eta * error * data.math[j];
                w[2] += eta * error * data.flag[j];
            }

            fprintf(pipe, "set title 'machine learning(eta:%g) : epoch %zd'\n", eta, i);
            fprintf(pipe, "set label 1 point pointtype 7 pointsize 2 at first %f, %f \"\"\n", data.english[j], data.math[j]);
            fprintf(pipe, "plot '-' using 1:($3 == -1 ? $2 : 1/0) with points lc rgb \"blue\" title 'math course',"
                          "'-' using 1:($3 == 1 ? $2 : 1/0) with points lc rgb \"red\" title 'english course',"
                          "%f*x %+f\n", -(w[0] / w[1]), -(w[2] / w[1]));

            for(size_t i = 0; i < 2; i++){
                for(size_t j = 0; j < count_line(data_file); j++){
                    fprintf(pipe, "%f %f %d\n", data.english[j], data.math[j], data.flag[j]);
                }fprintf(pipe, "e\n");
            }
            fprintf(pipe, "pause 0.1\n");
        }
    }

    fclose(data_file);
    pclose(pipe);
    pclose(pipe2);
    free(data.english);
    free(data.math);
    free(data.flag);

    return 0;
}

double f(double a, double b, double x){
    return a * x + b;
}
