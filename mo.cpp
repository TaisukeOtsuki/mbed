#include<mbed.h>
#include<QEI.h>
#include<iostream>
#include "mo.h"
namespace robocon{
    Encoder::Encoder(PinName one,PinName two,PinName three,int pulsesPerRev,Encoding encoding)
        :encode(one,two,three,pulsesPerRev,encoding){


        }

    Motors::Motors(PinName motor_pin, int Period, int ZeroPoint, int Max, int Min)
        : mt(motor_pin), max_pulse(Max), min_pulse(Min), zero_pulse(ZeroPoint), value(NULL)  {

            mt.period_ms(Period);
            mt.pulsewidth_us(ZeroPoint);

        }

    float Angle(void){
        int count=encode.getPulse()*(-1);
        int rev =encode.getRevolution();
        float ang=360*count/2000;
        if(rev==1){
            encode.reset();
        }
    }



    /*    void Motors::set_motor(int Period,int ZeroPoint,int Max,int Min){
          PwmOut::period_ms(Period);
          PwmOut::pulsewidth_us(ZeroPoint);
          max_pulse=Max;
          min_pulse=Min;
          zero_pulse=ZeroPoint;
          }
          */
    float Motors::adjust_move(float move){

        const int pulse_range=max_pulse-min_pulse;
        return(pulse_range*move)/100.0f;
    }
    void Motors::motor_move(int move){
        int i=0;
        if(move-*value>=20){
            i=(move-*value)/20;
        }
        while(1){
            Angle();
            *value+=20;    
            mt.pulsewidth_us(adjust_move(*value));
            i--;
            if(i==0){
                value++;
                *value=move;
                break;
            }
        }

    }
    void Motors::throw_ball(const float _Q, const float q, const float n) {
        const float K = 0.8;
        const float t = K*((_Q*n)-q);
        motor_move(t);
        if((_Q*n)==q){
            motor_move(0);
        }



    }      
}         

