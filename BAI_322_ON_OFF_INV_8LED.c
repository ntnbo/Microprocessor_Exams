#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned INT8 y; 
void main() 
{
   set_up_port_ic_chot ();
   set_tris_b (0x3c);
   y = 0;
   xuat_32led_don_4byte (0, 0, 0, 0);
   WHILE (true)
   {
      WHILE (input (on));
      y = 0x0f;
      xuat_32led_don_4byte (0, 0, 0, y);
      DO
      {
         IF (!input (inv))
         {
            y = ~y;
            xuat_32led_don_4byte (0, 0, 0, y);
         }
      }WHILE (input (off));

      xuat_32led_don_4byte (0, 0, 0, 0);
   }
}


