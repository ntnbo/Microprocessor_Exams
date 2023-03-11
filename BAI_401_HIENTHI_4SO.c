#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
void  main() 
{      
   set_up_port_ic_chot(); 
   //xuat_4led_7doan_4so(0xb0, 0xa4, 0xf9, 0xc0);  // bang hex led 7 doan
   xuat_4led_7doan_4so(0xF9, 0x92, 0xF9, 0xA4);  // 1512
   while(true);
} 
