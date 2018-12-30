#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>

#include"./core.h"

const double eta = 0.1; //学習率
const size_t epoch = 5; //学習回数
double w[3]; //重みベクトル

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

    if(pipe == NULL){
        fprintf(stderr, "popen error\n");
        exit(1);
    }

    fprintf(pipe, "set xrange [-25:125]\n");
    fprintf(pipe, "set yrange [-25:125]\n");
    fprintf(pipe, "set xlabel 'english points'\n");
    fprintf(pipe, "set ylabel 'math points'\n");
    fprintf(pipe, "set terminal gif animate optimize delay 13 size 600, 600\n"); //gifへ出力 必要ないならコメントアウト
    fprintf(pipe, "set output 'tmp.gif'\n"); //gifへ出力 必要ないならコメントアウト

    for(size_t i = 0; i < epoch; i++){
        for(size_t j = 0; j < count_line(data_file); j++){
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
    free(data.english);
    free(data.math);
    free(data.flag);

    return 0;
}
