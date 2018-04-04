
#pragma once
#include<mbed.h>
#include <iostream>


namespace robocon{
    class Motor {
        private:
            int max_pulse;
            int min_pulse;
            int zero_pulse;
            int *value;
            mbed::PwmOut mt;
        public:
            Motor();
            void set_motor(int Period,int ZeroPoint,int Max,int Min);
            void motor_move(int move);
            void adjust_move(float move);
            void throw_ball(int nagetaikakudo,int imairukakudo,int kaitensuu);
    };
    
};

