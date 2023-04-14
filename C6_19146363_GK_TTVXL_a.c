#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_key4x4_138.c>

signed int8 sp , ch_sp , dv_sp ;

void giai_ma_counter0_4led_7d()
{
   ch_sp = ma7doan[sp / 10 ];
   dv_sp = ma7doan[sp % 10];
     
   if (ch_sp == 0xc0) ch_sp = 0xff;
}

void hien_thi_counter0_4led_7d()
{
   // _|.YZ.|_
   xuat_4led_7doan_4so (0x71, dv_sp, ch_sp&0x7f, 0xC7); // 0x7f dau cham DP   
}

void main()
{
   set_up_port_ic_chot();
   setup_lcd ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit); //setup_timer_0(t0_off);
   set_timer0 (0);   // numer start
   sp = 0 ;
   
   while(true)
   {
      sp= 17 - get_timer0();
      if(sp < 3) set_timer0 (0);
      
      giai_ma_counter0_4led_7d() ;
      hien_thi_counter0_4led_7d();
   }
}
