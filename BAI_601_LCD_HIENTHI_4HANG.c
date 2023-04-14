/* Hien thi 4 hang, da thiet lap tu dau */

#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

unsigned char hang1[]={"Nguyen Trong Nghia  "};    // [] ko gioi han so ki tu, max 20 ki tu, >20 bi tran
unsigned char hang2[]={"Trong Nghia Nguyen  "}; 
unsigned char hang3[]={"KHOA CO KHI MAY SPKT"}; 
unsigned char hang4[]={"0123456789abcdefghij"}; 
signed int8 i; 
  
void main() 
{
   
   set_up_port_ic_chot ();
   setup_lcd ();
   
   lcd_command (lcd_addr_line1);
   for (i = 0; i < 20; i++) { lcd_data (hang1[i]); }  // 10 so ki tu hien thi
   lcd_command (lcd_addr_line2);
   for (i = 0; i < 20; i++) { lcd_data (hang2[i]); }
   lcd_command (lcd_addr_line3);
   for (i = 0; i < 30; i++) { lcd_data (hang3[i]); }
   lcd_command (lcd_addr_line4);
   for (i = 0; i < 20; i++) { lcd_data (hang4[i]); }
   
   while (true);
}

