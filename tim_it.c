

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{

	
  if (htim->Instance == TIM2){
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2){
		//电机 1 
		cy_stepper_[0].step_--;  // 9 8 7 6 5 4 3 2 1 
		if (cy_stepper_[0].step_<=0){
			Stepper_CH1_Duty(0);//关闭PWM
			cy_stepper_[0].done_ = true;
			Stepper_CH1_Stop();
		}
	}else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
		//电机 6 
		cy_stepper_[5].step_--;
		if (cy_stepper_[5].step_ <= 0){
			Stepper_CH6_Duty(0);//关闭PWM
			cy_stepper_[5].done_ = true;
			Stepper_CH6_Stop();
		}
	}
  }else if (htim->Instance == TIM4){
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
		//电机 5 
		cy_stepper_[4].step_--;
		if (cy_stepper_[4].step_ <= 0){
			Stepper_CH5_Duty(0);//关闭PWM
			cy_stepper_[4].done_ = true;
			Stepper_CH5_Stop();
		}
	}else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2){
		//电机 4 
		cy_stepper_[3].step_--;
		if (cy_stepper_[3].step_ <= 0){
			Stepper_CH4_Duty(0);//关闭PWM
			cy_stepper_[3].done_ = true;
			Stepper_CH4_Stop();
		}

	}else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3){
		//电机 2
		cy_stepper_[1].step_--;
		if (cy_stepper_[1].step_ <= 0){
			Stepper_CH2_Duty(0);//关闭PWM
			cy_stepper_[1].done_ = true;
			Stepper_CH2_Stop();
		}
	}else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4){
		//电机 3 
		cy_stepper_[2].step_--;
		if (cy_stepper_[2].step_ <= 0){
			Stepper_CH3_Duty(0);//关闭PWM
			cy_stepper_[2].done_ = true;
			Stepper_CH3_Stop();
		}
	
	}
	
	
  }
}


