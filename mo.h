#pragma once
#include "mbed.h"
#include <iostream>

namespace robocon{
	class Motors {
	private:
		mbed::PwmOut mt;
		const int max_pulse;
		const int min_pulse;
		const int zero_pulse;
		int *value;
		float adjust_move(float move);
	public:
		Motors(PinName, const int=20, const int=1500, const int=2000, const int=1000);
		void motor_move(const float move);
		void throw_ball(const float nagetaikakudo, const float imairukakudo, const float kaitensuu);
	};
};

