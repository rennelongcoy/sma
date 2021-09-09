#include "sma_calculation.h"

void sma_calculate(unsigned char dest[], unsigned char src[], int size)
{
    /* TODO: Possibly improve algorithm */

    /* Calculate Simple Moving Average */
    int i = 0;
    for (i = 0; i < size; ++i) {
        int sum = 0;
        int j;
        /* for 1st (SMA_WINDOW_SIZE - 1) elements */
        if (i < (SMA_WINDOW_SIZE - 1)) {
            for (j = 0; j < (i + 1); ++j) {
                sum += src[j];
            }
            dest[i] = sum / (i + 1);
        }
        /* for 5th element onwards */
        else {
            for (j = i - (SMA_WINDOW_SIZE - 1); j < (i + 1); ++j) {
                sum += src[j];
            }
            dest[i] = sum / SMA_WINDOW_SIZE;
        }
    }
}