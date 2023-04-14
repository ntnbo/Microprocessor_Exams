
//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c> 
#include <tv_pickit2_shift_key4x4_138.c> 

signed int8  mp, y; 
void main() 
{   
   set_up_port_ic_chot ();
   set_tris_b (0x3c);

   while (true)
   {
      MP = KEY_4X4_DW ();

      if (MP!= 0XFF)    //kiem tra voi 0xff > check co phim nhan ko
      {
         // xu ly chuc nang cua phim
         if (MP == 0) { Y = 0;   }     // nhan 0 > 8 led sang
         if (MP == 1) { Y = 0XFF;  }   // nhan 1 > 8 led tat
         XUAT_32LED_DON_4BYTE (0, 0, 0, Y) ;
      }
   }
}

