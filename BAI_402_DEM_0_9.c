//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
signed INT8 i; 
void main() 
{
   set_up_port_ic_chot ();
   WHILE (true)
   {
      FOR (i = 5; i < 9; i++)       // fix, dem 5-9
      {
         xuat_4led_7doan_1so(ma7doan[i]);
         delay_ms (500);
      }
   }
}


