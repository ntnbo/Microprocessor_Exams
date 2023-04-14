#include <tv_pickit2_shift_1_proteus.c>
//!#include <tv_pickit2_shift_1.c>
#include <TV_PICKIT2_SHIFT_KEY4X4_138.C>


unsigned int16 t0;
unsigned int8 donvi, chuc, tram, nghin, tam;

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

   xuat_4led_7doan_4so (chuc, donvi & 0x7f, ma7doan[5], 0x8C);    //0x7f dau cham sang; 0xBC chu P
}

void main()
{
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);

   while (true)
   {
      t0 = get_timer0 ();
      giai_ma_hien_thi (t0);
      if (t0 == 11) set_timer0 (0);    // t0 == ... set khi nao quay lai 0
      
      delay_ms(100);
   }
}
