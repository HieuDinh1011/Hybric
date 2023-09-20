#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE 1
#define PRESS_STATE 0
void subKeyProcess(int);
void subKeyProcessLong(int);


void getKeyInput();
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
int isButton1PressedLong();
int isButton2PressedLong();
int isButton3PressedLong();

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

extern int button1_flagLong;
extern int button2_flagLong;
extern int button3_flagLong;
#endif /* INC_BUTTON_H_ */