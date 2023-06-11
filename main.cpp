#include "mbed.h"
#include "HEPTA_COM.h"
HEPTA_COM com(PA_9,PA_10,9600);
RawSerial pc(USBTX,USBRX,9600);
int main()
{
    pc.printf("Xbee Uplink Ok Mode\r\n");
    int rcmd=0,cmdflag=0;
    for(int i=0;i<10;i++){
        com.printf("num=%d\r\n",i);
        com.xbee_receive(&rcmd,&cmdflag);
        if(cmdflag==1){
            if(rcmd=='a'){
                pc.printf("rcmd=%c,cmdflag=%d\r\n",rcmd,cmdflag);
                com.printf("Hepta-Sat Lite Uplink Ok\r\n");
            }
            com.initialize();
        }
        wait(1.0);
    }
}
