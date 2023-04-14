//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_key4x4_138.c>

signed int8 sp , ch_sp , dv_sp , i ;
signed int8 bdn, bdn_nn, time, ch_time_lon, dv_time_lon, ch_time_nho, dv_time_nho ;
unsigned int8 mp , tt_ud , tt_nn ;

#int_timer1
void interrupt_timer1()
{ 
   bdn_nn++;
   bdn++; 
//!   bdn_led ++;
   set_timer1(3036); 
}

void giai_ma_counter0_4led_7d()
{
   ch_sp = ma7doan[sp / 10 ];
   dv_sp = ma7doan[sp % 10];
     
   if (ch_sp == 0xc0) ch_sp = 0xff;
}

void hien_thi_counter0_4led_7d()
{
   // DV.|--|.CH   
   xuat_4led_7doan_4so (dv_sp & 0x7f, 0x8f, 0x39, ch_sp) ;
}

void main()
{
   set_up_port_ic_chot();
   setup_lcd ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit); //setup_timer_0(t0_off);
   set_timer0 (8);      // ban dau
   sp = 0 ;
   bdn = 0 ; bdn_nn = 0 ;
   time = 3 ;     // mssv, so dem len
   
   while(true)
   {          
      sp=get_timer0();
      if(sp > 15) set_timer0(8);
      delay_ms(100); // xoa khi chay tren BTN
      
      giai_ma_counter0_4led_7d() ;
      hien_thi_counter0_4led_7d();      
   }
}
