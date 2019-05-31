//---------------------------------------------------------------------------
#include <cstdint>
//---------------------------------------------------------------------------

// my
uint32_t saturated_sum(uint32_t RGB_in1, uint32_t RGB_in2) {
  uint32_t or_7b, and_7b, RGB_sum, mask_satrtd;
  or_7b = (RGB_in1 | RGB_in2) & 0x00808080;
  and_7b = RGB_in1 & RGB_in2 & 0x00808080;
  RGB_in1 &= 0x007f7f7f;
  RGB_in2 &= 0x007f7f7f;
  RGB_sum = RGB_in1 + RGB_in2;
  mask_satrtd = ((RGB_sum & 0x00808080 & or_7b | and_7b) >> 7) * 0xff;
  return (mask_satrtd | RGB_sum | or_7b);
}

// branch
uint32_t saturated_sum_branch(uint32_t RGB_in1, uint32_t RGB_in2) {
  uint32_t result, sum_byte;
  sum_byte = (RGB_in1 & 0x000000FF) + (RGB_in2 & 0x000000FF);
  if (sum_byte > 0xff)
    result = 0xff;
  else
    result = sum_byte;

  sum_byte = (RGB_in1 & 0x0000FF00) + (RGB_in2 & 0x0000FF00);
  if (sum_byte > 0xff00)
    result = result | 0x0000ff00;
  else
    result = result | sum_byte;

  sum_byte = (RGB_in1 & 0x00FF0000) + (RGB_in2 & 0x00FF0000);
  if (sum_byte > 0xff0000)
    result = result | 0x00ff0000;
  else
    result = result | sum_byte;

  return result;
}

// your
uint32_t saturated_sum1(uint32_t left, uint32_t right) {
  uint32_t overflow_places = (left ^ right) & 0x00010100;
  uint32_t sum = left + right;
  uint32_t mask = (((sum - overflow_places) >> 8) & 0x00010101) * 255;
  return (sum - mask) | mask;
}

uint32_t saturated_sum2(uint32_t left, uint32_t righ) {
  uint32_t res, xres;
  res = left + righ;
  xres = (((left & righ) | ((left | righ) & ~res)) & 0x808080);
  res ^= xres << 1;
  res |= (xres * 0xFF) >> 7;
  return res;
}

uint32_t saturated_sum3(uint32_t rgb1, uint32_t rgb2) {
  unsigned long sum = rgb1 + rgb2;
  if ((rgb1 & 0x000000FF) + (rgb2 & 0x000000FF) > 0xFF)
    sum = (sum - 0x100) | 0xFF;
  if ((rgb1 & 0x0000FF00) + (rgb2 & 0x0000FF00) > 0xFF00)
    sum = (sum - 0x10000) | 0xFF00;
  if ((rgb1 & 0x00FF0000) + (rgb2 & 0x00FF0000) > 0xFF0000)
    sum = (sum - 0x1000000) | 0xFF0000;
  return sum;
}

uint32_t saturated_sum4(uint32_t left, uint32_t righ) {
  uint32_t res, xres, ffres;
  res = left + righ;
  xres = (res ^ left ^ righ) & 0x1010100;
  ffres = (xres * 0xFF) >> 8;
  res = (res | ffres) - xres;
  res |= ffres;
  return res;
}

uint32_t saturated_sum5(uint32_t rgb1, uint32_t rgb2) {
  unsigned long sum = rgb1 + rgb2;
  unsigned long mask = (rgb1 ^ rgb2 ^ sum) & 0x01010100;
  mask = mask ^ (((sum - (mask & 0x00000100)) ^ sum) & 0x01010000);
  mask = mask ^ (((sum - (mask & 0x00010000)) ^ sum) & 0x01000000);
  sum = sum - mask;
  mask = (mask * 0xFF) >> 8;
  return sum | mask;
}
