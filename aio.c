
 /* standard headers */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* mraa header */
#include "mraa/gpio.h"
#include "mraa/aio.h"


/* gpio declaration */
#define GPIO_PIN_1 63
#define GPIO_PIN_2 62
#define GPIO_PIN_3 61
#define AIO_PORT  6

mraa_result_t glow_3_leds(int, int, int);

mraa_gpio_context gpio_1, gpio_2, gpio_3;



int
main(void)
{
    mraa_result_t status = MRAA_SUCCESS;
    int sensor_out;
    mraa_aio_context aio;
    int value = 0;
    float float_value = 0.0;



    /* initialize mraa for the platform (not needed most of the times) */
    mraa_init();


    /* initialize GPIO pin */
    gpio_1 = mraa_gpio_init(GPIO_PIN_1);
    if (gpio_1 == NULL) {
        fprintf(stderr, "Failed to initialize GPIO %d\n", GPIO_PIN_1);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    /* initialize GPIO pin */
    gpio_2 = mraa_gpio_init(GPIO_PIN_2);
    if (gpio_2 == NULL) {
        fprintf(stderr, "Failed to initialize GPIO %d\n", GPIO_PIN_2);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    gpio_3 = mraa_gpio_init(GPIO_PIN_3);
    if (gpio_3 == NULL) {
        fprintf(stderr, "Failed to initialize GPIO %d\n", GPIO_PIN_3);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    /* initialize AIO */
    aio = mraa_aio_init(AIO_PORT);
    if (aio == NULL) {
        fprintf(stderr, "Failed to initialize AIO: %d\n",AIO_PORT);
        mraa_deinit();
        return EXIT_FAILURE;
    }



    /* set GPIO to output */
    status = mraa_gpio_dir(gpio_1, MRAA_GPIO_OUT);
    if (status != MRAA_SUCCESS) {
        goto err_exit;
    }

    /* set GPIO to output */
    status = mraa_gpio_dir(gpio_2, MRAA_GPIO_OUT);
    if (status != MRAA_SUCCESS) {
        goto err_exit;
    }
    /* set GPIO to output */
    status = mraa_gpio_dir(gpio_3, MRAA_GPIO_OUT);
    if (status != MRAA_SUCCESS) {
        goto err_exit;
    }

    fprintf(stdout,"the sensor output range btw 0-1023\n");

    /* toggle both GPIO's */
while (1) {
    //fscanf(stdin,"%d",&sensor_out);
    sensor_out = mraa_aio_read(aio);
    value = mraa_aio_read(aio);
    float_value = mraa_aio_read_float(aio);
    fprintf(stdout, "ADC A0 read - %d\n", value);
    fprintf(stdout, "ADC A0 read float - %.5f\n", float_value);
    //sleep(10);
int check = sensor_out/128;
    //sensor_out = sensor_out/128;
    
    
if(check<1)
{
	glow_3_leds(0,0,0);
    fprintf(stdout, "Potentiometer Value is btw 0-127 - %d\n", value);

}

    else if(check<2)
{
	glow_3_leds(0,0,1);
    fprintf(stdout, "Potentiometer Value is btw 128-255 - %d\n", value);
}

   else if(check<3)
{
	glow_3_leds(0,1,0);
    fprintf(stdout, "Potentiometer Value is btw 256-383 - %d\n", value);
}

   else if(check<4)
{
	glow_3_leds(0,1,1);
    fprintf(stdout, "Potentiometer Value is btw 384-511 - %d\n", value);
}
   else if(check<5)
{
        glow_3_leds(1,0,0);
    fprintf(stdout, "Potentiometer Value is btw 512-639 - %d\n", value);
}
   else if(check<6)
{
    glow_3_leds(1,0,1);
    fprintf(stdout, "Potentiometer Value is btw 640-767 - %d\n", value);
}
   else if(check<7)
{
    	glow_3_leds(1,1,0);
    fprintf(stdout, "Potentiometer Value is btw 768-895 - %d\n", value);
}
   else if(check<8)
{
    	glow_3_leds(1,1,1);
    fprintf(stdout, "Potentiometer Value is btw 896-1023 - %d\n", value);
}

   else 
{
    	fprintf(stdout,"invalid range\n");
}


    
sleep(1);
}

    /* deinitialize mraa for the platform (not needed most of the times) */
    //mraa_deinit();

    return EXIT_SUCCESS;

    err_exit:
    mraa_result_print(status);
    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_FAILURE;
}




mraa_result_t glow_3_leds(int val1, int val2, int val3)
{
//mraa_gpio_context 
mraa_gpio_write(gpio_1, val1);
mraa_gpio_write(gpio_2, val2);
mraa_gpio_write(gpio_3, val3);
return MRAA_SUCCESS;
}





















