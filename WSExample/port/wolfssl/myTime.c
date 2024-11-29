#include "pico/stdlib.h"

#include "wolfssl/wolfcrypt/camellia.h"
#include "math.h"


unsigned long my_time(unsigned long* timer){
	return to_us_since_boot(get_absolute_time());
}

word32 LowResTimer(void) {
   /*
   write your own clock tick function if don't want time(0)
   needs second accuracy but doesn't have to correlated to EPOCH
   */
   return (word32) (to_ms_since_boot (get_absolute_time()) / 1000);
}



//https://deemocean.com/2022/10/02/rp2040-randomness-and-ring-oscillator/

#define ROSC_RANDOMBIT_OFFSET _u(0x0000001c)
#define ROSC_BASE _u(0x40060000)

// return random number by ROSC between 0-2^N
// N should be in [0,32]
unsigned int ROrand(int N)
{
  unsigned int random = 0;
  uint32_t r = get_rand_32 ();
  if (N == 32){
	  random = r;
  } else {
	  random = r & (uint32_t)(pow(2, N+1)-1);
  }

  return random;
}


unsigned int my_rng_seed_gen(void){
	return ROrand(32);

}


