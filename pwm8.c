#include <wiringPi.h>
#include <stdio.h>

#define wPi_PWM1 23

int prescaler = 19;

enum {DO = 0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI};
int pitch[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int ranges[12];
int song[] = {SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI, RE,
              SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO};
int rythm[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1,
               4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1};
             
void calcRange() {
    int upper = sizeof(pitch) / sizeof(pitch[0]);
    
    for(int i=0; i<upper; i++)
        ranges[i] = 19200000 / prescaler / pitch[i];
}

void playSound(int um, int duration) {
    pwmSetClock(prescaler);
    pwmSetRange(ranges[um]);
    pwmWrite(wPi_PWM1, ranges[um]/2);
    delay(2000 / duration);  // Convert rhythm to milliseconds
    pwmWrite(wPi_PWM1, 0);  // Turn off the sound
    delay(50);  // Short pause between notes
}

int main(void) {
    wiringPiSetup();
    
    pinMode(wPi_PWM1, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    
    calcRange();
    
    int upper = sizeof(song) / sizeof(song[0]);
    for(int i=0; i < upper; i++) {
        playSound(song[i], rythm[i]);
    }
    
    pwmWrite(wPi_PWM1, 0);
    return 0;
}
