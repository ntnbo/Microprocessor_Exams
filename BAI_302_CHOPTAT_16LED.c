//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
unsigned int8 y;
void main()
{
   set_up_port_ic_chot();
   y=0;
   while (true)
   {
      xuat_32led_don_4byte(0,0,y,y);
      delay_ms(200);
      y= ~y;
   }
} 
