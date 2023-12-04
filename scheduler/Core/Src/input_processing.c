/*
 * input_processing.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */

#include "main.h"
#include "input_reading.h"
#include "input_processing.h"

enum ButtonState_0 { BUTTON_RELEASED_0, BUTTON_PRESSED_0, BUTTON_PRESSED_MORE_THAN_1_SECOND_0 };
enum ButtonState_0 buttonState_0 = BUTTON_RELEASED_0;


int is_press_flag[N0_OF_BUTTONS] = {0, 0, 0};

void fsm_for_input_processing(void) {
	switch(buttonState_0){
		case BUTTON_RELEASED_0:
			if(is_button_pressed(0)){
				buttonState_0 = BUTTON_PRESSED_0;
				is_press_flag[0] = 1;
			}
				// INCREASE VALUE OF PORT A BY ONE UNIT
			break;
		case BUTTON_PRESSED_0:
			if (!is_button_pressed(0)){
				buttonState_0 = BUTTON_RELEASED_0;
				is_press_flag[0] = 0;
			}else{
				if(is_button_pressed_1s(0)){
					buttonState_0 = BUTTON_PRESSED_MORE_THAN_1_SECOND_0;
					is_press_flag[0] = 1;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND_0:
			if (!is_button_pressed(0)){
				buttonState_0 = BUTTON_RELEASED_0;
				is_press_flag[0] = 0;
			}
			// TODO
			break;
	}
}

void buttonPress(){
	fsm_for_input_processing();
	if(is_press_flag[0]){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		is_press_flag[0] = 0;
	}
};
