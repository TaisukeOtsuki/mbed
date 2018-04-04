
#pragma once
#include<mbed.h>
#include <iostream>


namespace robocon{
    class Motors {
        private:
            int max_pulse;
            int min_pulse;
            int zero_pulse;
            int *value;
            mbed::PwmOut mt;
        public:
            Motors();
            void set_motor(int Period,int ZeroPoint,int Max,int Min);
            void motor_move(int move);
            int adjust_move(float move);
            void throw_ball(int nagetaikakudo,int imairukakudo,int kaitensuu);
    };
    
};

