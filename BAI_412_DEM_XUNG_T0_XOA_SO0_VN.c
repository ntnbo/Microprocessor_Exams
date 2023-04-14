#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c> 
unsigned INT8    t0; 
unsigned INT8    donvi, chuc, tram, nghin; 

void  giai_ma_hien_thi (UNSIGNED int16 tam) 
{
   donvi = ma7doan[tam%10];
   chuc = ma7doan[tam/10%10];
   tram = ma7doan[tam/100%10];
   nghin = ma7doan[tam/1000];
   IF (tram == 0xc0) // 1100 0000 
   {
      tram = 0xff; // oxff 1111 1111
      IF (chuc == 0xc0) chuc = 0xff;
   }

   xuat_4led_7doan_4so (0xff, tram, chuc, donvi);  // 0xff tat nghin
}

void main() 
{   
   set_up_port_ic_chot () ;
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);
   WHILE (true)
   {
      t0 = get_timer0 ();
      giai_ma_hien_thi (t0);
      IF (t0 >= 101) set_timer0 (1) ;
   }
}


