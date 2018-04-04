#include "mo.h"

namespace robocon{
	Motors::Motors(PinName motor_pin, int Period, int ZeroPoint, int Max, int Min) : mt(motor_pin), max_pulse(Max), min_pulse(Min), zero_pulse(ZeroPoint), value(NULL) {
		mt.period_ms(Period);
		mt.pulsewidth_us(ZeroPoint);
	}

	float Motors::adjust_move(float move) {
		const int pulse_range = max_pulse - min_pulse;
		return (pulse_range * move) / 100.0f;
	}

	void Motors::motor_move(const float move) {
		/*
		int i=0;
		if(move-*value>=20){
			i=(move-*value)/20;
		}
		while(1){
			*value+=20;    
			mt.pulsewidth_us(adjust_move(*value));
			i--;
			if(i==0){
				value++;
				*value=move;
				break;
			}
		}
		*/
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

