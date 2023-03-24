
#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 

unsigned char hang1[]={"1234567890"};
signed int8 i, vitri;
void main()
{
   set_up_port_ic_chot () ;
   setup_lcd () ;
   vitri = 0;
   while (true)
   {
      lcd_command (0x80) ;      
      for (i = vitri; i < 10 + vitri; i++)
      {
         lcd_data (hang1[i]) ;
      }
//!               delay_ms(500);
      
      lcd_command (0xC0) ;
      for (i = vitri; i < 10 + vitri; i++)
      {
         lcd_data (hang1[i]) ;
      }

      delay_ms (500) ;
      vitri++;
      if (vitri == 10) vitri = 0;
   }
}

//!void main() 
//!
//{
   //!
   //!   set_up_port_ic_chot ();
   //!   setup_lcd ();
   //!   lcd_command (lcd_addr_line1);
   //!   lcd_data ("khoa dien - dien tu ");
   //!   lcd_command (lcd_addr_line2);
   //!   lcd_data ("bm dientucong nghiep");
   //!   lcd_command (lcd_addr_line3);
   //!   lcd_data ("khoa dien - dien tu ");
   //!   lcd_command (lcd_addr_line4);
   //!   lcd_data ("bm dientucong nghiep");
   //!   delay_ms (1000);
   //!
   //!
   //!   while (true)
   // !
   //{
      //!      lcd_command (lcd_shift_left);
      //!      delay_ms (1000);
      // !
   //}

   //!



