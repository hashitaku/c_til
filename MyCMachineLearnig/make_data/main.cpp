#include<fstream>
#include"./make_data.hpp"

int main(){
    
    std::ofstream out("./../data.txt");

    make_data(out);
    
    return 0;
}
