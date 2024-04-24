#include "systick.h"

void delay_250ns(struct systick_t *stk) {
  stk->ctrl = 0;
  stk->load = 42;
  stk->val = 0;
  stk->ctrl = 5;
  while (stk->ctrl_s.h & 1);
  stk->ctrl = 0;
}

void delay_mikro(struct systick_t *stk, unsigned int us) {
  for (int i = 0; i < us; i++) {
    delay_250ns(stk);
    delay_250ns(stk);
    delay_250ns(stk);
    delay_250ns(stk);
  }
}

void delay_milli(struct systick_t *stk, unsigned int ms) {
  for (int i = 0; i < ms; i++) {
    delay_mikro(stk, 1000);
  }
}
