
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned int8 led7dq[8]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8}; 
unsigned int8 i; 
void hien_thi_8led() 
{
   
   for (i = 0; i < 8; i++)
   {
      xuat_8led_7doan_quet_2 (i, led7dq[i]); // vi tri led, tuong ung so hien thi
      delay_us (100);
      xuat_8led_7doan_quet_tat_led (); // tat het led, chong lem
   }
}

void main() 
{   
   set_up_port_ic_chot ();
   while (true)
   {
      hien_thi_8led ();
   }
}

