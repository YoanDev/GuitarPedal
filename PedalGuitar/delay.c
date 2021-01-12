/** @file simple_client.c
 *
 * @brief This simple client demonstrates the most basic features of JACK
 * as they would be used by many applications.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <jack/jack.h>
#include <math.h>

#define DELAY_MAX 48000

jack_port_t *input_port;
jack_port_t *output_port;
jack_client_t *client;

float_t Delay_Buffer[DELAY_MAX];
uint32_t DelayCounter = 0;
uint32_t Delay_Depth = 24000;

void delay(jack_default_audio_sample_t *in,jack_default_audio_sample_t *out, int i)
{
    float* channelData = in;
    Delay_Buffer[DelayCounter] = Delay_Buffer[DelayCounter]*0.5 + in[i];
    DelayCounter++;
    if(DelayCounter>=Delay_Depth)
    {
        DelayCounter = 0;
    }
    out[i] = in[i] + Delay_Buffer[DelayCounter]*0.5;
    //printf("%d \n",DelayCounter);
}







