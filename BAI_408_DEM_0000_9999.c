#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c> 
signed    INT16    i; 
void main() 
{
   set_up_port_ic_chot();
   while(true)
   {
      for(i = 9000; i < 10000; i++)
      {
         xuat_4led_7doan_4so(ma7doan[i/1000], ma7doan[i/10/10%10], ma7doan[i/10%10], ma7doan[i%10]);
         delay_ms (30);
      }      
   }
}
