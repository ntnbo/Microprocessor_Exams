
//#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_key4x4_138.c>

unsigned int16 y, i;
unsigned int8  mp;

void btUp()
{
   if (mp == 0)
   {
      delay_ms (20) ;

      if (mp == 0)
      {
         for (i = 0; i < 16; i++)
         {
            y = (y<<1)|1;
            xuat_32led_don_2word (0, y) ;
            delay_ms (50) ;
            while (mp!= 0xff);
         }
      }
   }
}

void  btDw()
{
   if (mp == 4)
   {
      delay_ms (20) ;

      if (mp == 0)
      {
         for (i = 0; i < 16; i++)
         {
            y = y>>1;
            xuat_32led_don_2word (0, y) ;
            delay_ms (50) ;
            while (mp!= 0xff);
         }
      }
   }
}

void btClr()
{
   if (mp == 8)
   {
      delay_ms (20) ;

      if (mp == 0)
      {
         y = 0;
         xuat_32led_don_2word (0, y) ;
         while (mp!= 0xff);
      }
   }
}

void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   y=0;

   while(TRUE)
   {
      mp = key_4x4_up ();

      if (mp!= 0xff)
      {
         btUp () ;
         btDw () ;
         btClr () ;
      }
   }
}

