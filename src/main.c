#include <stdint.h>
#include <board-constants.h>

#define SIMULATOR 1
#include "systick.h"
#include "gpio.h"

int main(void) {
  struct systick_t *stk = (struct systick_t *)SYSTICK_ADDR;
  struct gpio_t *gpio_e = (struct gpio_t *)GPIO_E;

  gpio_e->moder = 0x55555555;
  gpio_e->otyper_l = 0x0000;

  gpio_e->odrs.l = 0x0;
  delay_milli(stk, 500);
  gpio_e->odrs.l = 0x0f;
  delay_milli(stk, 500);
  gpio_e->odrs.l = 0xff;
  
  delay_250ns(stk);
  return 0;
}
