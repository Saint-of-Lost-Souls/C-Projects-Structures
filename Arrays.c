#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

// Build a temperature logger: we need temp and timestamp
#define LEN 10 // Length of array

typedef struct Sample
{
    double temp;
    time_t timestamp;
} Sample;

int randRangeInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

double randRange(double min, double max, int decimal_digits)
{
    double scale_factor = pow(10, decimal_digits);
    int scaled_min = round(min * scale_factor);
    int scaled_max = round(max * scale_factor);
    return randRangeInt(scaled_min, scaled_max) / scale_factor; // Promotion of int to double

}
double getTemp()
{
    return randRange(20, 25, 1);
}

int main()
{
    system("cls");
    Sample samples[LEN];

    for (int i = 0; i < LEN; i++)
    {
        printf("Sample %d...\n", i);
        samples[i].timestamp = time(NULL); // Will return universal time in secs
        samples[i].temp = getTemp(); // Store the temps value in our sample array
        sleep(1); // Putting process to sleep for 1 sec
    }
    
    // Print: timestamp, time offset from first sample, temperature
    printf("\ntimestamp, offset, temp\n");
    for (int i = 0; i < LEN; i++)
    {
        printf("%lld, %lld, %5.1f\n", samples[i].timestamp, 
                                      samples[i].timestamp - samples[0].timestamp,
                                      samples[i].temp);
    }
    


    printf("\n\n");
    return EXIT_SUCCESS;
}
