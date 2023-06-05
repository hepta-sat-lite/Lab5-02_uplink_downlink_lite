#include "mbed.h"
#include "HEPTA_COM.h"
HEPTA_COM com(PA_9,PA_10,9600);
Serial sat(USBTX,USBRX,9600);
int main()
{
    sat.printf("Xbee Uplink Ok Mode\r\n");
    int rcmd=0,cmdflag=0;
    for(int i=0;i<10;i++){
        com.xbee_receive(&rcmd,&cmdflag);
        com.printf("num=%d\r\n",i);
        if(cmdflag==1){
            if(rcmd=='a'){
                sat.printf("rcmd=%c,cmdflag=%d\r\n",rcmd,cmdflag);
                com.printf("Hepta-Sat Lite Uplink Ok\r\n");
            }
            com.initialize();
        }
        wait_ms(1000);
    }
}
