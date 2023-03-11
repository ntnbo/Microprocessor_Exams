
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c> 
signed    INT8    i; 
void main() 
{
   set_up_port_ic_chot () ;
   i = 0;
   WHILE (true)
   {
      DO
      {
         xuat_4led_7doan_2so (ma7doan[i / 10], ma7doan[i % 10]);
         delay_ms(200);
         i++;
      }

      WHILE (i < 60);
      delay_ms (3000);
      
      DO
      {
         i--;
         xuat_4led_7doan_2so (ma7doan[i / 10], ma7doan[i % 10]);
         delay_ms(200);         
      }

      WHILE (i > 0);
      delay_ms (3000);
   }
}


