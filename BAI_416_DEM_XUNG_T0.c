
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned int16 t0;
unsigned int8 donvi, chuc, tram, nghin;
void giai_ma_hien_thi (unsigned int16 tam)
{
   donvi = ma7doan[tam % 10];
   chuc = ma7doan[tam / 10 % 10];
   tram = ma7doan[tam / 100 % 10];
   nghin = ma7doan[tam / 1000];
   if (nghin == 0xc0)
   {
      nghin = 0xff;
      if (tram == 0xc0)
      {
         tram = 0xff;
         if (chuc == 0xc0) chuc = 0xff;
      }
   }

   xuat_4led_7doan_4so (nghin, tram, chuc, donvi) ;
}

void main()
{
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (0);
   while (true)
   {
      t0 = get_timer0 ();
      giai_ma_hien_thi (t0);
      if (t0 == 10000) set_timer0 (1);
   }
}


