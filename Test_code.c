#include <wiringPi.h>
#include <stdio.h>

#define wPi_PWM1 23

int prescaler = 19;

enum {C = 0, D, E, F, G, A, B};
int pitch[] = {262, 294, 330, 349, 392, 440, 494};
int ranges[7];

int song[] = {E, E, E, E, E, E, E, G, C, D, E};
int rythm[] = {2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 6};
             
void calcRange() {
    int upper = sizeof(pitch) / sizeof(pitch[0]);
    
    for(int i=0; i<upper; i++)
        ranges[i] = 19200000 / prescaler / pitch[i];
}

void playSound(int um, int duration) {
    pwmSetClock(prescaler);
    pwmSetRange(ranges[um]);
    pwmWrite(wPi_PWM1, ranges[um]/2);
    delay(duration * 200);  // Convert rhythm to milliseconds
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
