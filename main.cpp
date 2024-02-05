#include "mbed.h"
#include "platform/mbed_thread.h"
/*

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
/*
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
                    /*
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
*/

//program 6a
AnalogOut aOut(A1);

int main(){
    while(true){
        aOut = 0.5/3.3;
        wait_ms(500);
        aOut = 1/3.3;
        wait_ms(500);
        aOut = 2/3.3;
        wait_ms(500);
        aOut = 2.5/3.3; //since aOut setting aOut to 1 means max output (3.3v), these numbers need to be scaled
        wait_ms(500);
    }
}
/*
//program 6b

// This is the way they want it done
AnalogOut sawtoothOut(A2);
int main(){ 
    while(true){
        for(int i = 0; i < 100; i++){
            sawtoothOut = i * 0.010101; // Since i only goes up to 99 we need an ugly recurring decimal to hit 3v
            wait_us(100); // 1/100th of the period of the output wave
        }
    }
}
*/
/*
// This is the way I'd do it (assuming time.h is available)
#include "time.h"

#define X_COEFF 100
#define Y_COEFF 3

AnalogOut sawtoothOut(A3);

int main(){ // This creates a much smoother wave, only downside is since there's technically infinite harmonics there could be aliasing issues
    clock_t c; // The way to fix the aliasing is to generate a bandlimited wave using a fourier series but that would require an FFT library which we don't have
    float t;
    while(true){
        c = clock();
        t = c/CLOCKS_PER_SEC;
        sawtoothOut = (Y_COEFF * ((t * X_COEFF) - floor(t * X_COEFF)))/3.3; //t - floor(t) creates a sawtooth with amplitude and period of 1, coefficients set the desired freq and ampl
        wait_ms(1); // This line is just so it's not looping as fast is it possibly can, might not even be needed
    }
}
*/
