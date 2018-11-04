#include <msp430.h>
#include "statemachine.h"
#include "led_dim_statemachine.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

/**
 * Based on the button that initiated the interrup make the led change
 * to the state of that button
 */
void 
led_state_update()
{
    switch (switch_btn)
    {
    case SW1: /*BRIGHT_RED*/
        // set red on and green on
        led_changed = 1;
        green_on = 0; 
        red_on = 1; 
        break; 
    case SW2: /*DIM_RED*/
        // turn red on
        led_changed = 1;
        red_on = 1; 
        green_on = 0; 
        led_dim_state_update();
        buzzer_advance_frequency(); 
        break; 
    case SW3: /*BRIGHT_GREEN*/
        // turn green on
        // if red is on, then turn off
        led_changed = 1;
        green_on = 1; 
        red_on = 0; 
        //buzzer_advance_frequency();
        break; 
    case SW4: /*DIM_GREEN*/
        // turn green on if our red is on
        led_changed = 1;
        green_on = 1; 
        red_on = 0; 
        led_dim_state_update();
        //buzzer_advance_frequency();
        break; 
    }
    // reset switch states
    switch_state_down = 0;
    switch_state_up = 0; 
    led_update();
}