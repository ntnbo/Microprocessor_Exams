#include <tv_pickit2_shift_1_proteus.c>
//!#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

signed int8 giay; 
void lcd_hienthi_dongho() 
{
   lcd_goto_xy (0, 15);    // 0 hang, 15 cot
   delay_us (20);
   lcd_data (giay / 10 + 0x30);
   lcd_data (giay % 10 + 0x30);
}

void main() 
{   
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_goto_xy (0, 0);
   lcd_data ("DEM GIAY:");
   giay = 0;

   while (true)
   {
      lcd_hienthi_dongho ();
      delay_ms (500);
      giay++;
      if (giay == 60) giay = 0;
   }
}

