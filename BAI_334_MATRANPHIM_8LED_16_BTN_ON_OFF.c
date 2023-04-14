
//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c> 
#include <tv_pickit2_shift_key4x4_138.c>

signed int8 mp;
unsigned int16 y=0;

void main()
{
   set_up_port_ic_chot () ;
   set_tris_b (0x3c) ;

   while (true)
   {
      mp = key_4x4_dw () ;

      if (mp != 0xff)
      {
         if (mp == 0) y = 0x01|y; //00000001 // ==0 led0 sang; == 7 led7 sang
         if (mp == 1) y = 0x02|y; //00000010
         if (mp == 2) y = 0x04|y; //00000100
         if (mp == 3) y = 0x08|y; //00001000
         if (mp == 4) y = 0x10|y; //00010000
         if (mp == 5) y = 0x20|y; //00100000
         if (mp == 6) y = 0x40|y; //01000000
         if (mp == 7) y = 0x80|y; //10000000
         if (mp == 8) y = 0xFE&y; //11111110 // ==8 led0 tat; den so F led7 tat
         if (mp == 9) y = 0xFD&y; //11111101
         if (mp == 10) y=0xFB&y; //11111011
         if (mp == 11) y=0xF7&y; //11110111
         if (mp == 12) y=0xEF&y; //11101111
         if (mp == 13) y=0xDF&y; //11011111
         if (mp == 14) y=0xBF&y; //10111111
         if (mp == 15) y=0x7F&y; //01111111
         xuat_32led_don_4byte (0, 0, 0, y) ;
      }
   }

}

