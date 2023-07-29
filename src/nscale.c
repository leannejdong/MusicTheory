#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int notes, i, midinote;
    double frequency, ratio;
    double c0, c5;
    double intervals[24];

    if(argc!=3){
        printf("Usage: nscale notes midinote\n");
        return 1;
    }

    notes = atoi(argv[1]);
    if(notes < 1){
        printf("Usage: nscale notes midinote\n");
        return 1;
    }
    if(notes > 24){
        printf("Error: maximum valye for notes is 24\n");
        return 1;
    }

    midinote=atoi(argv[2]);
    if(midinote < 0){
        printf("Error: cannot have negative MIDI notes!\n");
        return 1;
    }
    if(midinote > 127){
        printf("Error: maximum midnote is 127\n");
        return 1;
    }

    // find the frequency of the MIDI note
    ratio = pow(2.0, 1.0/12.0);
    // find middle C, 3 semitones above low A = 220
    c5 = 220.0 * pow(ratio, 3);

    // midi note 0 is C, 5 Octaves below Middle C
    c0 = c5 * pow(0.5, 5);
    frequency = c0*pow(ratio, midinote);

    // calc ratio from notes, and fill the frequency array
    ratio = pow(2.0, 1.0/notes);
    for(i = 0; i < notes; i++){
        intervals[i] = frequency;
        frequency *=ratio;
    }

    // finally, read array, write to screen
    for(i = 0; i < notes; i++){
        printf("%f\n", intervals[i]);
    }
    return 0;
}

// nscale notes midinote
//https://leanne.godbolt.org/z/hTE8zajY5