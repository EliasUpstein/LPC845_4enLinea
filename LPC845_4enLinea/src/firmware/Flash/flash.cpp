#include "flash.h"

/*static*/ void setFlashWaitStates(uint8_t nofWaits) {
  /* Configure the FLASHCFG with the FLASHTIM (Flash memory access time).
   * Latest NXP SDK provides the function IAP_ConfigAccessFlashTime() to do a similar thing.
   * By default after reset, the LPC845 sets it to 0x2 which is 3 system clock access time.
   * NOTE: if getting for higher clock speeds a hardfault, then add some wait states. The LPC845 just runs fine with zero wait states and maximum clock speed for me :-).
   */
  uint32_t val;

  val = (FLASH_CTRL->FLASHCFG)&~FLASH_CTRL_FLASHCFG_FLASHTIM_MASK; /* do not touch the other bits! */
  switch(nofWaits) {
    default:
    case 0: val |= 0x0; break;  /* 1 system clock access time */
    case 1: val |= 0x1; break;  /* 2 system clock access time */
    case 2: val |= 0x2; break;  /* 3 system clock access time */
  }
  FLASH_CTRL->FLASHCFG = val; /* write back settings */
}
