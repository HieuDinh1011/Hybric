#ifndef INC_DATA_H_
#define INC_DATA_H_
#include <esp_now.h>
#include <WiFi.h>
//----------------------------------------Variables to accommodate the data to be sent.

struct struct_message {
    int rnd_1;
    int rnd_2;
} ;
extern int send_rnd_val_1;
extern int send_rnd_val_2;

extern int receive_rnd_val_1;
extern int receive_rnd_val_2;
extern struct_message receive_Data; //--> Create a struct_message to receive data.
extern struct_message send_Data; // Create a struct_message to send data.
#endif 