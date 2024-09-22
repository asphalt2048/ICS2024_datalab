/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

int test_tconst(void){
  return 0xFFFFFFE0;
}

int test_bitNand(int x, int y){
  return ~(x&y);
}

int test_getByte(int x,int y){
  return (x>>(8*y))&0xff;
}

int test_roundUp(int x){
  if(x < 0)
    return x & ~255;
  else
    return (x + 255) & ~255;
}

int test_swapOddandEven(int x){
  int mask1 = 0xAAAAAAAA;
  int mask2 = 0x55555555;
  int even_bits = x & mask1;
  int odd_bits = x & mask2;
    
  even_bits >>= 1;
  odd_bits <<= 1; 
  return even_bits | odd_bits;
}

int test_secondLowBit(int x){
  int y=x-(x&-x);
  return y&(-y);
}

int test_rotateNBits(int x, int n){
  n = n%32;
  int left_part = x<<n;
  int right_part = x>>(32 - n);
  return (left_part|right_part);
}

int test_fractions(int x){
  return x*7/16;
}

int test_biggerOrEqual(int x, int y){
  return x >= y;
}

int test_hdOverflow(int x,int y){
  long long res=(long long)x+(long long)y;
  return res>2147483647||res<-2147483648;
}

int test_overflowCalc(int x, int y, int z){
  union tests
  {
    int a;
    unsigned b;
  }u,v,w;
  u.a=x;
  v.a=y;
  w.a=z;
  long long res=(long long)u.b+(long long)v.b+(long long)w.b;
  return res>>32;
}

int test_partialFill(int l, int h) {
  int ans=0;
  for(int i=l;i<=h;++i){
    if(i%2==0)ans+=1<<i;
  }
  return ans;
}

unsigned test_float_abs(unsigned uf) {
  float f = u2f(uf);
  if (isnan(f))
    return uf;
  if(f==0&&uf>>31)return 0;
  return f<0?f2u(-f):uf;
}

unsigned test_float_i2f(int x) {
  float f = (float) x;
  return f2u(f);
}

int test_oddParity(int x){
  int answer=0;
  for(int i=1;i<=32;++i){
    answer+=x%2;
    x>>=1;
  }
  return answer%2?0:1;
}