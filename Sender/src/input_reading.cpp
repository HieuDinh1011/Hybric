#include "main.h"
#include "input_reading.h"

 // we aim to work with more than one buttons
#define Buttons 3

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int button1_flagLong = 0;
int button2_flagLong = 0;
int button3_flagLong = 0;
int KeyReg0[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeforKeyPress = 200;

void subKeyProcess(int i){
	if(i == 0){
		button1_flag = 1;
	}
	if(i == 1){
			button2_flag = 1;
		}
	if(i == 2){
			button3_flag = 1;
		}
}
void subKeyProcessLong(int i){
	if(i == 0){
		button1_flagLong = 1;
		}
		if(i == 1){
			button2_flagLong = 1;
			}
		if(i == 2){
			button3_flagLong = 1;
			}
}
void getKeyInput(){
	for (int i = 0 ;i < 3 ;i++){
	KeyReg0[i] = KeyReg1[i];
	KeyReg1[i]= KeyReg2[i];
	if(i == 0){KeyReg2[i] = digitalRead(BTN_Pin1);}
	else if(i == 1) {KeyReg2[i] =digitalRead(BTN_Pin2);}
	else if(i == 2) {KeyReg2[i]= digitalRead(BTN_Pin3);}
	if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
		if(KeyReg3[i] != KeyReg2[i]){
			KeyReg3[i] = KeyReg2[i];
			if(KeyReg2[i] == PRESS_STATE){
				subKeyProcess(i);
				TimeforKeyPress = 200;
			}
		}
		else {

			TimeforKeyPress--;
			if(TimeforKeyPress == 0){
				if(KeyReg2[i] == PRESS_STATE){
					subKeyProcessLong(i);
				}
				TimeforKeyPress = 200;
				//KeyReg3[i] = NORMAL_STATE;
			}
		}
	}
}
}
int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3PressedLong(){
	if(button3_flagLong == 1){
		button3_flagLong = 0;
		return 1;
	}
	return 0;
}
int isButton2PressedLong(){
	if(button2_flagLong == 1){
		button2_flagLong = 0;
		return 1;
	}
	return 0;
}
int isButton1PressedLong(){
	if(button1_flagLong == 1){
		button1_flagLong = 0;
		return 1;
	}
	return 0;
}