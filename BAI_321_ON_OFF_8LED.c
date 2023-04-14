//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
void main() 
{
   set_up_port_ic_chot ();
   set_tris_b (0x3c);
   xuat_32led_don_4byte (0, 0, 0, 0);  // tat het led
   while (true)
   {
      while (input (bt0)); // kt trang thai BT, kt den khi nhan =0 > thoat vong lap
      xuat_32led_don_4byte (0, 0, 0, 0xff);  // 8 led ON
      
      while (input (bt1));
      xuat_32led_don_4byte (0, 0, 0, 0);  // 8 led OFF
   }
}


