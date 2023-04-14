
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
unsigned int8 y; 
void main() 
{
   set_up_port_ic_chot ();
   set_tris_b (0x3c);   //luu y
   y = 0;
   xuat_32led_don_4byte (0, 0, 0, 0);

   while (true)
   {
      while (input (on)); // cho nhan ON
      y = 0x0f;
      xuat_32led_don_4byte (0, 0, 0, y);

      do
      {
         if (!input (inv)) // so sanh voi 0
         {
            y = ~y;
            xuat_32led_don_4byte (0, 0, 0, y);
         }
      }while (input (off));

      xuat_32led_don_4byte (0, 0, 0, 0);
   }
}

