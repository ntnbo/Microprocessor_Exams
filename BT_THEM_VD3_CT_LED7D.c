
// Nhan 2 phim <10 trên ban phim ma tran > cai dat GH dem sp
// C > bat dau dem
// D > ngung dem
// F > dao chieu dem, ngay tai gtri dang dem
// *so sp hien thi tren led 7 doan

//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include<tv_pickit2_shift_key4x4_138.c>

unsigned int8 mp,t0,gh;
int1 t,q;

void datgioihan()
{
   mp = key_4x4_dw () ;

   if (mp < 10)
   {
      t = ~t;
      if (t == 1) gh = mp;
      else gh = gh * 10 + mp;
   }
}

void main()
{
   set_up_port_ic_chot () ;
   set_tris_b (0x3c) ;
   setup_timer_0 (t0_off) ;
   gh = 0, t0 = 0;

   while (true)
   {
      datgioihan () ;
      if (mp == 12) setup_timer_0 (t0_ext_h_to_l|t0_div_1|t0_8_bit);    // nhan C
      if (mp == 13) setup_timer_0 (t0_off);                             // nhan D

      if (mp == 15)                                                     // nhan F
      {
         q = ~q;
         set_timer0 (gh - t0) ;
      }

      t0 = get_timer0 () ;

      if (t0 > gh)
      {
         set_timer0 (0) ;
         t0 = 0;
      }

      if (q == 0) xuat_4led_7doan_giaima_xoa_so0 (t0);
      else xuat_4led_7doan_giaima_xoa_so0 (gh - t0) ;
   }
}

