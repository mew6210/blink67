/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#ifndef LED_SHORT_DELAY
#define LED_SHORT_DELAY 200
#endif

#ifndef LED_LONG_DELAY
#define LED_LONG_DELAY 700
#endif

#ifndef LED_SIGNAL_DELAY
#define LED_SIGNAL_DELAY 300
#endif

// Perform initialisation
int pico_led_init(void) {
#if defined(PICO_DEFAULT_LED_PIN)
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
#endif
}

// Turn the led on or off
void pico_set_led(bool led_on) {
#if defined(PICO_DEFAULT_LED_PIN)
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#endif
}

void blinkLong(){
    pico_set_led(true);
    sleep_ms(LED_LONG_DELAY);
    pico_set_led(false);
    sleep_ms(LED_SIGNAL_DELAY);
}

void blinkShort(){
    pico_set_led(true);
    sleep_ms(LED_SHORT_DELAY);
    pico_set_led(false);
    sleep_ms(LED_SIGNAL_DELAY);
}

void blink6(){
    blinkLong();
    blinkShort();
    blinkShort();
    blinkShort();
    blinkShort();
}

void blink7(){
    blinkLong();
    blinkLong();
    blinkShort();
    blinkShort();
    blinkShort();
}

void blink67(){
    blink6();
    blink7();
}

int main() {
    int rc = pico_led_init();
    hard_assert(rc == PICO_OK);
    while (true) {
        blink67();
        sleep_ms(3000);
    }
}
