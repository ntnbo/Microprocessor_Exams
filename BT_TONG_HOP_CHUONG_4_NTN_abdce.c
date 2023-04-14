//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_1.c>
#include <TV_PICKIT2_SHIFT_KEY4X4_138.C>

signed int16 t0;
unsigned int8 donvi, chuc, tram, nghin, tam;
unsigned int tt_sp;
unsigned int tt_ht;
unsigned int tt_dao;

void phim_DAO()    // DAO chieu dem, cau c   // cau e, dem 24-11 va dao lai
{
   if (!input (BT2))
   {
      if (!input (BT2))
      {
         // xu ly chuc nang phim
         TT_DAO++;
         if(TT_DAO == 2) TT_DAO = 0;     // 0,1,  2 --> 0
         
         set_timer0(24 - get_timer0());
         while (!input (BT2));
      }
   }
}

void phim_HT()    // phim doi ben HT, cau d
{
   if (!input (BT1))
   {
      if (!input (BT1))
      {
         // xu ly chuc nang phim
         TT_HT++;
         if(TT_HT == 2) TT_HT = 0;     // 0,1,  2 --> 0
         
         while (!input (BT1));
      }
   }
}

void phim_SP()    // phim start pause, cau b
{
   if (!input (BT0))
   {
      if (!input (BT0))
      {
         // xu ly chuc nang phim
         TT_SP++;
         if(TT_SP == 2) TT_SP = 0;     // 0,1,  2 --> 0
         
         while (!input (BT0));
      }
   }
}

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

//!   xuat_4led_7doan_4so (chuc, donvi & 0x7f, ma7doan[5], 0x8C);    //0x7f dau cham sang; 0xBC chu P
}

void main()
{
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
   set_timer0 (0);

   while (true)
   {
//!      t0 = get_timer0 ();     // doc counter, no condition
      giai_ma_hien_thi (t0);  
//!      if (t0 > 10) set_timer0 (0); 
      
      delay_ms(100);
      
      phim_SP();     // cau b, phim start/pause
      if(TT_SP == 0)
      {
         setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit);
         xuat_32led_don_4byte(0xff, 0xff, 0xff, 0xff);
      }
      if(TT_SP == 1)
      {
         setup_timer_0 (t0_OFF);
         xuat_32led_don_4byte(0, 0, 0, 0);
      }
      
      phim_HT();     // cau d, doi ben HT
      if (TT_HT == 0)
      {
         xuat_4led_7doan_4so (chuc, donvi & 0x7f, ma7doan[5], 0x8C);
      }
      if (TT_HT == 1)
      {
         xuat_4led_7doan_4so (ma7doan[5], 0x8C & 0x7f, chuc, donvi);
      }
      
      phim_DAO();
      if (TT_DAO == 0)  // dem len
      {
         t0 = get_timer0();
         if (t0 > 24) set_timer0 (11);
      }
      if (TT_DAO == 1)  // dem xuong
      {
         t0 = 24 - get_timer0();
         if (t0 <= 10) set_timer0 (0);
      }
   }
}
