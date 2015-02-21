#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include "RCSwitch.h"
#include "RcOok.h"
#include "Sensor.h"

#define RXPIN 7
#define TXPIN 0

main() 
{
    if(wiringPiSetup() == -1) {
        printf("failed wiring pi\n");
        return 0;
    }

    RCSwitch * rc = new RCSwitch(RXPIN,TXPIN);
    while ( 1 ) {
        if ( rc->OokAvailable() ) {
            char message[512];
            rc->getOokCode(message);
            Sensor * s = Sensor::getRightSensor(message);
            if ( s != NULL ) {
                printf("Temp : %f\n",s->getTemperature());
            }
            delete s;
        }
        usleep(1000);
    }
}
