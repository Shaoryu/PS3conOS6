#include "mbed.h"
#include "PS3_SBDBT5V.h"
#include <string.h>
#include "PinNames.h"

 UnbufferedSerial pc(USBTX,USBRX,115200);
 PS3 ps3(p27,p26);
 DigitalOut led(LED1);

 
 int data[PS3::MAX_BUTTON];
 int analog_data[4];
 short int val = 0;
 
 void ps3_get_data();
 
 int main()
 {
     ps3.attach(&ps3_get_data);
     while(1) {
     	if(ps3.check_connection()){
     		printf("connecting ");
     		if(val == 1) {		// ボタンが押されているとき
                    if(data[PS3::UP]){
                        printf("up ");
        				// 処理
        			}
              
              for (int i=0; i<4; i++) {
                    printf("/%d,",analog_data[i]);
              }
                    
        		} else if(val == -1) {	// 全てのボタンが離されたとき
        			printf("release ");// 処理
        		} else {	// ボタン操作が行われていなかったとき
        			printf("space ");// 処理
        		}
     	} else {
     		printf("disconnecting ");
     	}
        //実処理
         printf("\r\n");
         led = !led;
     }
 }

 void ps3_get_data()
 {
 	val = ps3.get_data(data);
    ps3.get_analog(analog_data);
 }
