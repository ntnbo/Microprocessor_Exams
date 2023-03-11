//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
unsigned INT8 i;
unsigned INT32 y;

void main()
{
   set_up_port_ic_chot();
   y=0;
   while (true)
   {
      for(i=0;i<32;i++)
      {
         xuat_32led_don_1dw(y);
         delay_ms(200);
         y= (y<<1)+1;
      }
      for(i=0;i<32;i++)
      {
         xuat_32led_don_1dw(y);
         delay_ms(200);
         y= (y<<1);
      }
   }
}
