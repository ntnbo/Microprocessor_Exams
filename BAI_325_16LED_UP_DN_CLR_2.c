
#include <tv_pickit2_shift_1_proteus.c>
#include<tv_pickit2_shift_key4x4_138.c>

unsigned int16 y;

unsigned int8 tt_chieu;

void kt_up()
{
   if ( ! input (up) )
   {
      delay_ms (20) ;

      if ( ! input (up) )
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

         while ( ! input (up)) ;
      }
   }
}

void kt_dw()
{
   if ( ! input (dw) )
   {
      delay_ms (20) ;

      if ( ! input (dw) )
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

         while ( ! input (dw)) ;
      }
   }
}

void kt_clr()
{
   if ( ! input (clr) )
   {
      delay_ms (20) ;

      if ( ! input (clr) )
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

         while ( ! input (clr)) ;
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

/*
#include<tv_pickit2_shift_1.c>
unsigned int16 y;

unsigned int8  dao_chieu;

void main()
{
   set_up_port_ic_chot () ;
   set_tris_b (0x3c) ;
   y = 0;
   xuat_32led_don_4byte (0, 0, 0, 0) ;

   while (true)
   {
      
      if (input (bt1) == 0)
      {
         delay_ms (50) ;

         if (input (bt1) == 0)
         {
            y = (y<<1)|1;
            delay_ms (20) ;
            xuat_32led_don_4byte (0, 0, y>>8, y) ;
         }
      }

      if (input (bt2) == 0)
      {
         delay_ms (50) ;

         if (input (bt2) == 0)
         {
            y = y>>1;
            delay_ms (20) ;
            xuat_32led_don_4byte (0, 0, y>>8, y) ;
         }
      }

      if (input (bt3) == 0)
      {
         delay_ms (50) ;

         if (input (bt3) == 0)
         {
            y = 0;
            xuat_32led_don_4byte (0, 0, 0, 0) ;
         }

         if (input (bt1) == 0)
         {
            delay_ms (50) ;

            if (input (bt1) == 0)
            {
               y = (y>>1)|0x8000;
               delay_ms (20) ;
               xuat_32led_don_4byte (0, 0, y>>8, y) ;
            }
         }

         if (input (bt2) == 0)
         {
            delay_ms (50) ;

            if (input (bt2) == 0)
            {
               y = y<<1;
               delay_ms (20) ;
               xuat_32led_don_4byte (0, 0, y>>8, y) ;
            }
         }
      }
   }
}

#include <tv_pickit2_shift_1_proteus.c>
unsigned int16 y;

unsigned int8 tt_chieu;

void ktra_clr()
{
   if (input (bt1) == 0)
   {
      delay_ms (20) ;

      if (input (bt1) == 0)
      {
         xuat_32led_don_2word (0, 0) ;
         tt_chieu++;

         if (tt_chieu == 2)
            tt_chieu = 0;

         while (input (bt1) == 0);
      }
   }

}

void ktra_up()
{
   if (input (bt2) == 0)
   {
      if (tt_chieu == 0)
      {
         y = (y<<1) + 1;
         xuat_32led_don_2word (y, y) ;
      }
   }
}

void ktra_down()
{
   if (input (bt3) == 0)
   {
      if (tt_chieu == 1)
      {
         y = (y>>1) + 0x8000;
         xuat_32led_don_2word (y, y) ;
      }
   }
}

void main()
{
   set_up_port_ic_chot () ;
   y = 0;
   xuat_32led_don_2word (0, y) ;

   while (true)
   {
      ktra_clr () ;
      ktra_up () ;
      ktra_down () ;
   }

}

*/
