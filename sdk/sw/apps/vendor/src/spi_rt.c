/*
 * This example shows how to send a raw SPI bistream
 * through one the SPI master port.
 */

#include <stdio.h>
#include <stdint.h>
#include "pulp.h" // sdk/sw/pulp-rt-spiv2/include/hal/chips/pulpissimo/pulp.h
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 16

int rt_test()
{

    printf("Hello!\n");
    // printf("Hello!\n");
    // First configure the SPI device
    rt_spim_conf_t conf;
    // Get default configuration
    rt_spim_conf_init(&conf);
    // Set maximum baudrate. Can actually be lower than
    // that depending on the best divider found
    conf.max_baudrate = 1000000;
    // SPI interface identifier as the Pulp chip can have
    // several interfaces
    conf.id = 0;
    // Chip select
    conf.cs = 1;

    // Then open the device
    // rt_spim_t *spim = rt_spim_open(NULL, &conf, NULL);
    // if (spim == NULL) return -1;
    // printf("Hello !\n");
    rt_spim_t spim;
    // printf("Hello !\n");
    rt_spim_open(NULL, &conf, &spim);
    // printf("Hello!\n");
    // printf("Hello end!\n");

    // Allocate a buffer from the periph memory, we'll use
    // it to store the SPI data to be sent
    char tx_buffer[BUFFER_SIZE];
    // if (tx_buffer == NULL) return -1;

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        tx_buffer[i] = i;
    }
    // printf("Hello!\n");

    // Finally send the buffer to SPI.
    // This is using basic synchronous mode.
    rt_spim_send(
        &spim, tx_buffer, BUFFER_SIZE * 8, RT_SPIM_CS_AUTO);
    // printf("Hello!\n");

    return 0;
}
