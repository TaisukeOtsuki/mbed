#include "mbed.h"
#include "QEI.h"

#include"mo.h"

//PwmOut motor1(PA_7),motor2(),motor3();

QEI encode(PB_13,PB_14,PB_15,1000,QEI::X2_ENCODING);

int main() {
    robocon::Motors motor1;
    int count,angle,rev,i=1000;
    //motor1.set_motor(20,1500,1000,2000);
    robocon::Motor motor1;
    motor1.set_motor(20, 1500, 1000, 2000);   
    

    
    while(1) {
        
        
        printf("0\r\n");
    }
}
