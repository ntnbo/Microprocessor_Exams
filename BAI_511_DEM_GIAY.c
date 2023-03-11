
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
signed int8      giay; 
unsigned int16      i; 
void hienthi_delay()
{   
   for (i = 0; i < 200; i++)
   {
      xuat_8led_7doan_quet_2 (0, ma7doan [giay % 10]);     // led don vi giay
      delay_us (200);
      xuat_8led_7doan_quet_tat_led (); // tat het led, chong lem
      
      xuat_8led_7doan_quet_2 (1, ma7doan [giay / 10]);   // led chuc giay
      delay_us (200);
      xuat_8led_7doan_quet_tat_led ();
   }
}

void main() 
{   
   set_up_port_ic_chot ();
   while (true)
   {
      for (giay = 0; giay < 60; giay ++) hienthi_delay ();
   }
}


