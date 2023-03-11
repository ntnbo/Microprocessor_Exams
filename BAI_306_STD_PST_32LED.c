
//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
unsigned INT16 y;
unsigned INT8 i;

void main()
{
   set_up_port_ic_chot () ;
   y = 0;

   WHILE (true)
   {
      FOR (i = 0; i < 16; i++)
      {
         xuat_32led_don_2word (y, y) ;
         delay_ms (300) ;
         y = (y<<1) + 1;
      }

      FOR (i = 0; i < 16; i++)
      {
         xuat_32led_don_2word (y, y) ;
         delay_ms (300) ;
         y = (y<<1);
      }
   }
}

