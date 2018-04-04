#include<mbed.h>
#include<iostream>

#include "mo.h"

namespace robocon{
    Motor::Motor() {
    }
    void Motor::set_motor(int Period,int ZeroPoint,int Max,int Min){
         mt.period_ms(Period);
         mt.pulsewidth_us(ZeroPoint);
         max_pulse=Max;
         min_pulse=Min;
         zero_pulse=ZeroPoint;
         
    }
    void Motor::adjust_move(float move){
         return move*(max_pulse-min_pulse)/100;
    }
    void Motor::motor_move(int move){
         int i=0;
         if(move-*value>=20){
             i=(move-*value)/20;
         }
         while(1){
         *value+=20;    
         PwmOut::pulsewidth_us(adjust_move(*value));
         i--;
         if(i==0){
             value++;
             *value=move;
             break;
         }
         }
    }
    void Motor::throw_ball(float Q,float q,float n){
         float t,K=0.8;
         t=K*((Q*n)-q);
         motor_move(t);
         if((Q*n)==q){
             motor_move(0);
         }
    }      
         
         
}      
         
        
