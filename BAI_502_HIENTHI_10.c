
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned int16 tg_delay; 
void main() 
{   
   set_up_port_ic_chot ();
   tg_delay = 1;
   while (true)
   {
      xuat_8led_7doan_quet_1 (0x7f, 0xc0);  //0 thu tu PST, ma 7 doan cua so dem
      delay_ms (tg_delay);
      
      xuat_8led_7doan_quet_1 (0xbf, 0xf9);  //1
      delay_ms (tg_delay);      
   }
}


