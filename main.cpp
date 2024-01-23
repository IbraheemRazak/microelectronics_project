/*
#include "mbed.h"
#include "platform/mbed_thread.h"

#define WAVE2_PERIOD_US 10

int main()
{
    //Program 1
    DigitalOut led1(D11);
    DigitalOut led2(D12);
    while (true) {
        led1 = !led1;
        thread_sleep_for(50);
        led2 = !led2;
        thread_sleep_for(BLINKING_RATE_MS);
    }
    */

    /* Program 2/3
    DigitalOut wave1(D5);
    DigitalOut wave2(D6);
    int i = 0;

    while(true){
        i++;
        wave2 = !wave2;
        if(i % 100 == 0){
            wave1 = !wave1;
            i = 0;
        }
        wait_us(WAVE2_PERIOD_US/2);
    }
}
*/



//program 4/5
#include "mbed.h"
#include "platform/mbed_thread.h"

int main()
{
    BusOut display(D2,D3,D4,D5,D9,D10,D11,D12);
    while (true) {
        for (int i = 0; i < 10; i++){
            if(i%2==0){
                switch(i){
                    /*
                    case 0: display = 0x01; break; //UR 
                    case 1: display = 0x02; break; //UU 
                    case 2: display = 0x04; break; //BR
                    case 3: display = 0x08; break; //BB
                    case 4: display = 0x10; break; //BL
                    case 5: display = 0x20; break; //UL
                    case 6: display = 0x40; break; //MM
                    case 7: display = 0x80; break; //DP
                    */
                    /* //program 4
                    case 0: display = 0x3F; break; //0
                    case 1: display = 0x05; break; //1
                    case 2: display = 0x5B; break; //2
                    case 3: display = 0x4F; break; //3
                    case 4: display = 0x65; break; //4
                    case 5: display = 0x6E; break; //5
                    case 6: display = 0x7E; break; //6
                    case 7: display = 0x07; break; //7
                    case 8: display = 0x7F; break; //8
                    case 9: display = 0x6F; break; //9
                    */ // program 5
                    case 0: display = 0x75; break; //H
                    case 2: display = 0x7A; break; //E
                    case 4: display = 0x38; break; //L
                    case 6: display = 0x38; break; //L
                    case 8: display = 0x3F; break; //O
                }
            }
            else{display = 0x00;}
            wait_us(500000);
        }
    }
}
