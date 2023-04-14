#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   
   lcd_command (lcd_addr_line1);       // command gui lenh, THEO HANG line 1
   lcd_data("Nguyen Trong Nghia");     // data gui du lieu, neu >20 hang 1 tran qua hang 3, hang 2 tran qua hang 4
   
   lcd_command (lcd_addr_line4);
   lcd_data("KHOA CO KHI CTM SPKT");
   
   while(true);
}
