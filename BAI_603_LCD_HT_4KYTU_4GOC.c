
#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   
   lcd_command (0x80);  // command gui lenh, THEO VI TRI
   lcd_data("A");
   lcd_command (0x93);
   lcd_data("B");
   lcd_command (0xD4);
   lcd_data("C");
   lcd_command (0xE7);
   lcd_data("D");
      
   while(true);
}
