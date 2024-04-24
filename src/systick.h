#pragma once

#include <stdint.h>

struct systick_t {
  union {
    struct {
      uint16_t l;
      uint16_t h;
    }ctrl_s;
    uint32_t ctrl;
  };
  uint32_t load;
  uint32_t val;
  uint32_t calib;
};

void delay_250ns(struct systick_t *);
void delay_mikro(struct systick_t *, unsigned int);
void delay_milli(struct systick_t *, unsigned int);
