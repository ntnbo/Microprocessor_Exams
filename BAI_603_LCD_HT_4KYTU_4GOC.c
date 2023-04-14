/* HT 4 ki tu 4 goc, theo vi tri DDRAM memory */

#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   
   lcd_command (0x80);  // command gui lenh, THEO VI TRI table DDRAM memory
   lcd_data("A");       // data, gui du lieu
   lcd_command (0x93);
   lcd_data("B");
   lcd_command (0xD4);
   lcd_data("C");
   lcd_command (0xE7);
   lcd_data("D");
      
   while(true);
}
