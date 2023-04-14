
#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   lcd_command (lcd_addr_line1);
   lcd_data ("khoa dien - dien tu ");
   lcd_command (lcd_addr_line2);
   lcd_data ("bm vimach_vienthong");
   delay_ms (1000);

   while (true)
   {
      lcd_command (lcd_shift_right) ;  // lcd_shift_left > bi loi, hien thi du hang 3,4
      delay_ms (1000) ;
   }
}

