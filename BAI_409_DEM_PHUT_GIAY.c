#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c> 
signed    INT16    giay,phut; 
void main() 
{
   set_up_port_ic_chot();
   while(true)
   {
   
      for(phut = 0; phut < 60; phut++)
      {
         if (ma7doan[phut/10]=0xC0)    // xoa so 0 khi phut<10
         {
            ma7doan[phut/10]=0xff;
         }
         for(giay = 0; giay < 60; giay++)
         {
            xuat_4led_7doan_4so(ma7doan[phut/10], ma7doan[phut%10], ma7doan[giay/10], ma7doan[giay%10]);
            delay_ms (50);
         }            
      }      
   }
}
