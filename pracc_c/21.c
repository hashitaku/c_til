/*乱数*/
#include<stdio.h>
#include<stdint.h>

uint32_t xor128(void) {
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

uint32_t xor(void) {
  static uint32_t y = 2463534242;
  y = y ^ (y << 13); y = y ^ (y >> 17);
  return y = y ^ (y << 15);
}

int main(){

    printf("%d\n",xor128() % 10);
    printf("%d\n",xor128() % 10);
    printf("%d\n",xor128() % 10);
    printf("%d\n",xor128() % 10);

    return 0;
}
