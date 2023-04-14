/* chay chu LCD doc lap tung hang */

#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>

unsigned char hang1[46]={"                    NGHIA                    "};
unsigned char hang2[44]={"                    SPK                    "};
unsigned int8 i, j, vitri1, vitri2;

void main()
{
   set_up_port_ic_chot ();
   setup_lcd ();
   vitri1 = 0;
   vitri2 = 20;

   while (true)
   {
      lcd_command (0X80);
      for (i = vitri1; i < 20 + vitri1; i++)    
      {
         lcd_data (hang1[i]);
      }
      delay_ms (100);   // bo, khi chay tren BTN
      vitri1++;      // chay tu PST
      if (vitri1 == 26) vitri1 = 0; // het chu cuoi hang 1, reset lai 0
      
      lcd_command (0XC0);
      for (j = vitri2; j < 20 + vitri2; j++)
      {
         lcd_data (hang2[j]);
      }
      delay_ms (100);
      vitri2--;      // chay tu TSP
      if (vitri2 == 0) vitri2 = 24;
   }
}

