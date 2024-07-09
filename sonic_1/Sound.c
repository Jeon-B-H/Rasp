#include <wiringPi.h>
#include <stdio.h>

// Function prototype.
void calcRange();
void playMusic();
void playSound(int um, int duration, int rate);

// Substitute constant by using define.
#define SOUND 23

// Substitute constant
int prescaler = 19;

// Substitute array.
enum {DO = 0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI};
int pitch[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int ranges[12];
int song[] = {SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI, RE,
              SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO};
int rythm[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1,
               4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1};
           

// Play Sound
void playSound(int um, int duration, int rate) {
    pwmSetClock(prescaler);
    pwmSetRange(ranges[um]);
    pwmWrite(SOUND, 512);
    delay(10 * duration * rate);  // Convert rhythm to milliseconds
    pwmWrite(SOUND, 0);  // Turn off the sound
    delay(50);  // Short pause between notes
}

// Play Music
void playMusic(int rate) {
    int upper = sizeof(pitch) / sizeof(pitch[0]);
    
    for(int i=0; i < upper; i++) 
        playSound(song[i], rythm[i], rate);
    
    pwmWrite(SOUND, 0);
}

// Compute ranges.
void calcRange() {
    int upper = sizeof(pitch) / sizeof(pitch[0]);
    
    for(int i=0; i<upper; i++)
        ranges[i] = 19200000 / prescaler / pitch[i];
}
