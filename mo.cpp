#include<mbed.h>
#include<iostream>

#include "mo.h"

namespace robocon{
    Motors::Motors() {
    }

    void Motors::set_motor(int Period,int ZeroPoint,int Max,int Min){
        PwmOut::period_ms(Period);
        PwmOut::pulsewidth_us(ZeroPoint);
        max_pulse=Max;
        min_pulse=Min;
        zero_pulse=ZeroPoint;
    }
    int Motors::adjust_move(float move){

        return((max_pulse-min_pulse)*move)/100;
    }
    void Motors::motor_move(int move){
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
        void Motors::throw_ball(float _Q,float q,float n){
            float t,K=0.8;
            t=K*((_Q*n)-q);
            motor_move(t);
            if((_Q*n)==q){
                motor_move(0);
            }
        }      


    }      
}         
