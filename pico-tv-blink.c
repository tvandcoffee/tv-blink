/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/******
#include "pico/stdlib.h"


int main() {

    const uint LED_PIN = 16;
    const uint LED_PIN1 = 15;
    const uint BUT_PIN = 17;

    gpio_init(LED_PIN);
    gpio_init(LED_PIN1);
    gpio_init(BUT_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN1, GPIO_OUT);
    gpio_set_dir(BUT_PIN, GPIO_IN);
    bool x = false;
    while (true)
    {
        if (x == true)
        {
            if (gpio_get(BUT_PIN) == 0)
            {
                x = false;
                sleep_ms(25);
            }
            gpio_put(LED_PIN, 1);
            gpio_put(LED_PIN1, 0);
            sleep_ms(250);
            gpio_put(LED_PIN, 0);
            gpio_put(LED_PIN1, 1);
            sleep_ms(250);
            gpio_put(LED_PIN, 1);
            sleep_ms(250);
        }
        else
        {
            gpio_put(LED_PIN, 0);
            gpio_put(LED_PIN1, 0);
            if (gpio_get(BUT_PIN) == 0)
            {
                x = true;
                sleep_ms(25);
            }
        }
    }


}
*****/

/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>

int main() {

stdio_init_all();

printf("start of program\n");


//Button
printf("Button PIN Assigned\n");
    const uint BUT_PIN = 17;
//LEDs A-G
printf("LEDs A-G PINs Assigned\n");
    const uint A_PIN = 2;
    const uint B_PIN = 3;
    const uint C_PIN = 4;
    const uint D_PIN = 5;
    const uint E_PIN = 6;
    const uint F_PIN = 7;
    const uint G_PIN = 8;


//Initialize PINS
printf("PINs Initialized\n");
    gpio_init(A_PIN);
    gpio_init(B_PIN);
    gpio_init(C_PIN);
    gpio_init(D_PIN);
    gpio_init(E_PIN);
    gpio_init(F_PIN);
    gpio_init(G_PIN);
    gpio_init(BUT_PIN);

//Sets PINs to output
printf("PINs set to OUTPUT\n");
    gpio_set_dir(A_PIN, GPIO_OUT);
    gpio_set_dir(B_PIN, GPIO_OUT);
    gpio_set_dir(C_PIN, GPIO_OUT);
    gpio_set_dir(D_PIN, GPIO_OUT);
    gpio_set_dir(E_PIN, GPIO_OUT);
    gpio_set_dir(F_PIN, GPIO_OUT);
    gpio_set_dir(G_PIN, GPIO_OUT);

/***
 * Zero, A-F
gpio_put(A_PIN, 1);
gpio_put(B_PIN, 1);
gpio_put(C_PIN, 1); 
gpio_put(D_PIN, 1);
gpio_put(E_PIN, 1);
gpio_put(F_PIN, 1);
*/


/***
 *One B, C
gpio_put(B_PIN, 1);
gpio_put(C_PIN, 1); 
***/

/***
 *Two A, B, G, E, D
gpio_put(A_PIN, 1);
gpio_put(B_PIN, 1);
gpio_put(G_PIN, 1); 
gpio_put(E_PIN, 1);
gpio_put(D_PIN, 1);
***/

/***
 *Three A, B, G, C, D
gpio_put(A_PIN, 1);
gpio_put(B_PIN, 1);
gpio_put(G_PIN, 1); 
gpio_put(C_PIN, 1);
gpio_put(D_PIN, 1);
***/

/***
 * Four F, G, B, C
 gpio_put(F_PIN, 1);
 gpio_put(G_PIN, 1);
 gpio_put(B_PIN, 1);
 gpio_put(C_PIN, 1);
*/

/***
 *Five A, F, G, C, D
gpio_put(A_PIN, 1);
gpio_put(F_PIN, 1);
gpio_put(G_PIN, 1); 
gpio_put(C_PIN, 1);
gpio_put(D_PIN, 1);
***/
printf("Button PIN set to INPUT\n");
    gpio_set_dir(BUT_PIN, GPIO_IN);
printf("Variable Initialized\n");
    int x = 0;

printf("Ready...\n");

    while (true)
    {
      if (x == 0)
      {
        gpio_put(G_PIN, 0);
        gpio_put(A_PIN, 1);
        gpio_put(B_PIN, 1);
        gpio_put(C_PIN, 1); 
        gpio_put(D_PIN, 1);
        gpio_put(E_PIN, 1);
        gpio_put(F_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 1;
               sleep_ms(25);
               }  
      }
        printf("x=%d\n", x);
       if (x == 1)
      {
        printf("x=1\n");
        gpio_put(A_PIN, 0);
        gpio_put(D_PIN, 0);
        gpio_put(E_PIN, 0);
        gpio_put(F_PIN, 0);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 2;
               sleep_ms(25);
               }  
      }

       if (x == 2)
      {
        gpio_put(C_PIN, 0);
        sleep_ms(25);
        gpio_put(A_PIN, 1);
        gpio_put(G_PIN, 1); 
        gpio_put(E_PIN, 1);
        gpio_put(D_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 3;
               sleep_ms(25);
               }  
      }

      if (x == 3)
      {
        gpio_put(E_PIN, 0);
        sleep_ms(25);
        gpio_put(C_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 4;
               sleep_ms(25);
               }  
      }
        if (x == 4)
      {
        gpio_put(D_PIN, 0);
        gpio_put(A_PIN, 0);
        sleep_ms(25);
        gpio_put(F_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 5;
               sleep_ms(25);
               }  
      }


    if (x == 5)
      {
        gpio_put(B_PIN, 0);
        sleep_ms(25);
        gpio_put(A_PIN, 1);
        gpio_put(D_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 6;
               sleep_ms(25);
               }  
    }
        if (x == 6)
      {
        gpio_put(E_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 7;
               sleep_ms(25);
               }  
    }  

    if (x == 7)
      {
        gpio_put(F_PIN, 0);
        gpio_put(E_PIN, 0);
        gpio_put(G_PIN, 0);
        gpio_put(D_PIN, 0);
        sleep_ms(10);
        gpio_put(B_PIN, 1);
        gpio_put(C_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 8;
               sleep_ms(25);
               }  
    }  

     if (x == 8)
      {
        gpio_put(F_PIN, 1);
        gpio_put(E_PIN, 1);
        gpio_put(G_PIN, 1);
        gpio_put(D_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 9;
               sleep_ms(25);
               }  
    }  

        if (x == 9)
      {
        gpio_put(E_PIN, 0);
        gpio_put(D_PIN, 0);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0xa;
               sleep_ms(25);
               }  
    }  

    if (x == 0xa)
      {
        gpio_put(E_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0xb;
               sleep_ms(25);
               }  
    }  

     if (x == 0xb)
      {
        gpio_put(A_PIN, 0);
        gpio_put(B_PIN, 0);
        sleep_ms(10);
        gpio_put(D_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0xc;
               sleep_ms(25);
               }  
    }  

    if (x == 0xc)
      {
        gpio_put(G_PIN, 0);
        gpio_put(C_PIN, 0);
        sleep_ms(10);
        gpio_put(A_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0xd;
               sleep_ms(25);
               }  
    }  

    if (x == 0xd)
      {
        gpio_put(F_PIN, 0);
        gpio_put(A_PIN, 0);
        sleep_ms(10);
        gpio_put(B_PIN, 1);
        gpio_put(C_PIN, 1);
        gpio_put(G_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0xe;
               sleep_ms(25);
               }  
    }

     if (x == 0xe)
      {
        gpio_put(B_PIN, 0);
        gpio_put(C_PIN, 0);
        sleep_ms(10);
        gpio_put(A_PIN, 1);
        gpio_put(F_PIN, 1);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0xf;
               sleep_ms(25);
               }  
    }

     if (x == 0xe)
      {
        gpio_put(D_PIN, 0);
        sleep_ms(150);
        if (gpio_get(BUT_PIN) == 0)
            {
                x = 0;
               sleep_ms(25);
               }  
    }

    }

}
