//! Hien thi hh mm ss > tren 8 led 7 doan quet dung timer1
//! 4 led 7 doan dem sp, gh 0-50
//! LCD hien thi   CHINH GIO
//!                CHINH PHUC
//!                CHINH GIAY
//!                CHINH GH SAN PHAM
//! Ban dau mui ten o CHINH GIO > D > di chuyen mui ten xuong duoi
//! C di chuyen mui ten len tren
//! => CHINH GIO - led hang gio nhap nhay. Tuong tu CHINH PHUC, CHINH GIAY

//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include<tv_pickit2_shift_key4x4_138.c>
#include<tv_pickit2_shift_lcd.c>

unsigned int8 h=0,m=0,s=0,bdn=0,cd=0,gh=0,gh_tam=0,set=0,mp=0,t0=0;

int1 t,q,k;

#int_timer1

void ngat1()
{
   bdn++;
   set_timer1 (3036);
}

void giaima()
{
   led_7dq[0] = ma7doan[s % 10];
   led_7dq[1] = ma7doan[s / 10];
   led_7dq[3] = ma7doan[m % 10];
   led_7dq[4] = ma7doan[m / 10];
   led_7dq[6] = ma7doan[h % 10];
   led_7dq[7] = ma7doan[h / 10];
}

void hienthilcd()
{
   lcd_goto_xy (0, 1) ;    // hien thi o hang 0, cot 1
   lcd_data ("Chinh Gio");
   lcd_goto_xy (1, 1) ;    // hien thi o hang 1, cot 1
   lcd_data ("Chinh Phut");
   lcd_goto_xy (2, 1) ;    // hien thi o hang 2, cot 1
   lcd_data ("Chinh Giay");
   lcd_goto_xy (3, 1) ;    // hien thi o hang 3, cot 1
   lcd_data ("Chinh Gioi Han SP");
}

void muiten()     // di chuyen mui ten
{
   if (cd == 0)      // cd == 0 CHON GIO
   {
      lcd_goto_xy (1, 0) ; // xoa mui ten hang chinh PHUT
      lcd_data (' ');
      lcd_goto_xy (0, 0) ; // mui ten hang 0, cot 0
       lcd_data (0x7e);    // 0x7e ma cua dau =>
   }

   else if (cd == 1)    // cd == 1 CHON PHUT
   {
      lcd_goto_xy (0, 0) ; // hang 0, hang 2 > khoang trang ' '
      lcd_data (' ');
      lcd_goto_xy (2, 0) ;
      lcd_data (' ');
      lcd_goto_xy (1, 0) ;
      lcd_data (0x7e);     // 0x7e ma cua dau =>
   }

   else if (cd == 2)    // cd == 2 CHON GIAY
   {
      lcd_goto_xy (1, 0) ;
      lcd_data (' ');
      lcd_goto_xy (3, 0) ;
      lcd_data (' ');
      lcd_goto_xy (2, 0) ;
      lcd_data (0x7e);
   }

   else if (cd == 3)    // cd == 3 CHON GH SP
   {
      lcd_goto_xy (2, 0) ;
      lcd_data (' ');
      lcd_goto_xy (3, 0) ;
      lcd_data (0x7e);
   }
}

void gioihansp()  // cai dat GH sp 
{
   if (mp < 10)
   {
      t = ~t;
      if (t == 1) gh_tam = mp;
      else gh_tam = gh_tam * 10 + mp;
      if (gh_tam < 51) gh = gh_tam;
   }
}

void chinh()
{
   if (mp < 10)
   {
      k = ~k;
      q = 1;      // giam sat trang thai
      if (k == 1) set = mp;
      else set = set * 10 + mp;
   }
}

void dat()
{
   if (q == 1)
   {
      if (cd == 0) h = set;
      else if (cd == 1) m = set;
      else if (cd == 2) s = set;
   }
}

void tatled()
{
   if (cd == 0)
   {
      led_7dq[6] = 0xff;
      led_7dq[7] = 0xff;
   }

   else if (cd == 1)
   {
      led_7dq[3] = 0xff;
      led_7dq[4] = 0xff;
   }

   else if (cd == 2)
   {
      led_7dq[0] = 0xff;
      led_7dq[1] = 0xff;
   }
}

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   set_tris_b (0x3c);
   setup_timer_1 (t1_internal|t1_div_by_8);
   set_timer1 (3036);
   enable_interrupts (global);
   enable_interrupts (int_timer1);
   setup_timer_0 (t0_ext_h_to_l|t0_div_1|t0_8_bit);
   set_timer0 (0);
   hienthilcd ();

   while (true)
   {
      mp = key_4x4_dw ();

      if (bdn < 10)
      {
         if ( (mp == 12)&& (cd > 0) )
         {
            cd--;
            q = 0;
         }

         if ( (mp == 13)&& (cd < 3) )
         {
            cd++;
            q = 0;
         }

         muiten ();
         if (cd == 3) gioihansp ();
         else chinh ();
         dat ();
         if (bdn == 0) tatled ();
         else if (bdn == 5) giaima ();
         hien_thi_8led_7doan_quet_all ();
         t0 = get_timer0 ();

         if (t0 > gh)
         {
            set_timer0 (0);
            t0 = 0;
         }

         xuat_4led_7doan_4so (ma7doan[gh / 10], ma7doan[gh % 10]&0x7f, ma7doan[t0 / 10], ma7doan[t0 % 10]) ;
      }

      else
      {
         bdn = 0;
         s++;

         if (s == 60)
         {
            s = 0;
            m++;

            if (m == 60)
            {
               m = 0;
               h++;
               if (h == 24) h=0;
            }
         }

         giaima ();
      }
   }
}

