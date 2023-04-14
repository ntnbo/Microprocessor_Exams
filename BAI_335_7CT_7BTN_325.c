
/*#include <tv_pickit2_shift_1_proteus.c>
#include<tv_pickit2_shift_key4x4_138.c>

unsigned int16 y;
unsigned int8 tt_chieu,mp;

void kt_up()
{
   if (mp == 0)
   {
      delay_ms (20) ;

      if (mp == 0)
      {
         //xu ly chuc nang
         if (tt_chieu == 0)
         {
            y = (y<<1)|1;
            xuat_32led_don_2word (0, y) ;
            delay_ms (200) ;
         }

         if (tt_chieu == 1)
         {
            y = (y>>1)|0x8000;
            xuat_32led_don_2word (0, y) ;
            delay_ms (200) ;
         }

         while (key_nhan () ! = 0xff);
      }
   }
}

void kt_dw()
{
   if (mp == 4)
   {
      delay_ms (20) ;

      if (mp == 4)
      {
         //xu ly chuc nang
         if (tt_chieu == 0)
         {
            y = (y>>1);
            xuat_32led_don_2word (0, y) ;
            delay_ms (200) ;
         }

         if (tt_chieu == 1)
         {
            y = (y<<1);
            xuat_32led_don_2word (0, y) ;
            delay_ms (200) ;
         }

         while (key_nhan () ! = 0xff);
      }
   }
}

void kt_clr()
{
   if (mp == 8)
   {
      delay_ms (20) ;

      if (mp == 8)
      {
         //xu ly chuc nang
         y = 0;
         xuat_32led_don_2word (0, y) ;
         delay_ms (20) ;
         tt_chieu++;

         if (tt_chieu == 2)
         {
            tt_chieu = 0;
         }

         while (key_nhan () ! = 0xff);
      }
   }
}

void main()
{
   set_up_port_ic_chot () ;
   set_tris_b (0x3c) ;
   y = 0;
   xuat_32led_don_2word (0, y) ;
   tt_chieu = 0;

   while (true)
   {
      kt_clr () ;
      kt_up () ;
      kt_dw () ;
   }
}

*/
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
#include <TV_PICKIT2_SHIFT_KEY4X4_138.C>

unsigned int16 y;
unsigned int8 n,mp,a;
void btnup();
void btndw();
void btnclr();

void btnup()
{
   if (n == 0)
   {
      if (a == 0) y = (y<<1) +  1;
      if (a == 1) y = (y>>1) + 0x8000;
      xuat_32led_don_2word (0, y) ;
      while (key_nhan ()!= 0xff);
      n = 2;
   }
}

void  btndw()
{
   if (n == 4)
   {
      if (a == 0) y= y>>1;
      if (a == 1) y= y<<1;
      xuat_32led_don_2word (0, y) ;
      while (key_nhan ()!= 0xff);
      n = 2;
   }
}

void btnclr()
{
   if (n == 8)
   {
      xuat_32led_don_2word (0, 0) ;
      y = 0;
      a++;
      if (a > 1) a=0;
      while (key_nhan ()!= 0xff);
      n = 2;
   }
}

void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   y=0;
   a=0;

   while(TRUE)
   {
      mp = key_4x4_up ();
      if (key_nhan ()!= 0xff) n = mp;
      btnup () ;
      btnclr () ;
      btndw () ;
   }
}

