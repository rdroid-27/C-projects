#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141

int main()
{

    // Duration of audio wave
    int duration = 2;
    // Tone Frewquency: Frequency of the wave in Hz
    float f = 440.0; // A4 note
    // Sampling Freqeuency: Samples per second
    float sampling_rate = 44100;
    // Total number of samples in the audio wave
    int number_of_samples = duration * sampling_rate;
    // Maximum amplitude for 16-bit audio (2^16 - 1)
    int max_amplitude = 32767;

    float time = 0;
    float angle;
    int i = 0;
    short sample = 0;

    // Creating File for raw data
    FILE *file;
    file = fopen("sine_wave.raw", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    while (i < number_of_samples)
    {
        // Time interval for each sample
        time = i * (1 / sampling_rate);
        // Angle in radians
        angle = 2 * PI * f * time;
        // Sample values
        sample = sin(angle) * max_amplitude;

        // Write the sample to the file
        fwrite(&sample, sizeof(sample), 1, file);

        i++;
    }

    // Close the file
    fclose(file);

    return 0;
}