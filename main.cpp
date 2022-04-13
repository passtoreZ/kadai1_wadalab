#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    double v[80] = {};
    v[79] = 10.0;
    ofstream ofs("output.dat");
    while(1){
        double err =0.0;
        double tmp_v[80]={};
        tmp_v[79]= 10.0;
        tmp_v[0] = 0.0;
        for(int i=1; i<79; i++){
            tmp_v[i] = v[i];
        }

        for(int i = 1; i < 79; i++){    
            v[i] = 0.001/1000*(v[i+1]-2.0*v[i]+v[i-1])*0.05/((1.0/80)*(1.0/80))+v[i];
        }

        for(int i=1; i<79; i++){
            err += fabs(v[i]-tmp_v[i]);
        }

        if(err<2e-4) break;
        cout << err << endl;
    }
    for(int i=0; i<80; i++){
        ofs << v[i] << endl;
    }
    ofs.close();
}