
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_1.c>

unsigned int32 Y;

VOID PHIM_UP()
{
   if (input (up) == 0)
   {
      delay_ms (20);

      if (input (up) == 0)
      {
         Y = (Y<<1) + 1;
         xuat_32led_don_1dw (y);
         while (input (up) == 0);
      }
   }
}

VOID PHIM_DW()
{
   if (input (dw) == 0)
   {
      delay_ms (20);

      if (input (dw) == 0)
      {
         Y = (Y>>1);
         xuat_32led_don_1dw (y);
         while (input (dw) == 0);
      }
   }
}

VOID PHIM_clr()
{
   if (input (clr) == 0)
   {
      delay_ms (20);

      if (input (clr) == 0)
      {
         Y = 0;
         xuat_32led_don_1dw (y);
         while (input (up) == 0);
      }
   }
}

VOID MAIN()
{
   set_up_port_ic_chot ();
   set_tris_b (0x3c);
   Y = 0;
   xuat_32led_don_1dw (y);

   while (true)
   {
      PHIM_UP ();
      PHIM_DW ();
      PHIM_clr ();
   }
}

