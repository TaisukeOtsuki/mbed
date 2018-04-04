#include "mbed.h"
//#include "QEI.h"

#include"mo.h"

//QEI encode(PB_13,PB_14,PB_15,1000,QEI::X2_ENCODING);

int main() {
    robocon::Motors motor1(PA_7);

    while(1) {
        printf("0\r\n");
    }
}

