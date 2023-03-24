
#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

void main() 
{
   
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_command (lcd_addr_line1);
   lcd_data ("khoa CO KHI MAY");
   lcd_command (lcd_addr_line2);
   lcd_data ("bm dientucong nghiep");
   delay_ms (100) ;

   while (true)
   {
      lcd_command (lcd_shift_left);
      delay_ms (100);
   }
}

