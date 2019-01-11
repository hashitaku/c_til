#include"./make_data.hpp"

void make_data(std::ofstream &ref_out){
    std::random_device seed;
    std::mt19937_64 engine(seed());

    for(int i = 0; i < 100; i++){
        int math = engine() % 101;
        int english = engine() % 101;
        int flag;

        if(math > english){
            flag = -1;
        }else if(math < english){
            flag = 1;
        }else{
            flag = (engine() % 2) * 2 - 1;
        }

        ref_out << english << " " << math << " " << flag << std::endl;
    }
}
