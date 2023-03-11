
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned int8    t0; 
void main() 
{
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);   //t0: counter 0 ext: external (ngoai) l to h: canh lên
   set_timer0 (0);      // dat so dem ban dau
   while (true)
   {
      t0 = get_timer0 ();  // doc gia tri counter
      xuat_4led_7doan_3so (ma7doan[t0 / 100],
      ma7doan[t0 / 10 % 10], ma7doan[t0 % 10]) ;
      if (t0 >= 101) set_timer0 (1) ;
   }
}


