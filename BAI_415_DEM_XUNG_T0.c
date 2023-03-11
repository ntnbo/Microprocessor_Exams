
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned int16 t0;
void main()
{
   set_up_port_ic_chot () ;
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);   // xoa t0_8_bit
   set_timer0 (250) ;
   while (true)
   {
      t0 = get_timer0 ();
      xuat_4led_7doan_giaima_xoa_so0 (t0) ;
      if (t0 >= 301) set_timer0 (250);
   }
}


