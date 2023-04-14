
//!#include<tv_pickit2_shift_1_proteus.c>
#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_key4x4_138.c>
#include<tv_pickit2_shift_lcd.c>

unsigned int16 tg;

unsigned int8 mp;

void hienthi_tg()
{
   lcd_goto_xy (1, 18) ; // LCD hien thi o hang thu 2 cot thu 19
   lcd_data (tg + 0x30) ; // neu tg = 3 thì: 3 + 0x30 = 0x33 = > LCD hien thi so 3 (33 la so 3 trong ma ascii)
}

void hienthi_on() // hien thi chu ON
{
   lcd_goto_xy (1, 8) ;
   lcd_data ("ON ");
}

void hienthi_off()   // hien thi chu OFF
{
   lcd_goto_xy (1, 8) ;
   lcd_data ("OFF");
}

void main()
{
   set_up_port_ic_chot ();
   set_tris_b (0x3c);
   setup_lcd ();
   
   lcd_goto_xy (0, 0) ;
   lcd_data ("DIEU KHIEN BUZZER");
   
   lcd_goto_xy (1, 0) ;
   lcd_data ("BUZZER:");
   
   lcd_goto_xy (1, 15) ;
   lcd_data ("TG:");
   
   while (true)
   {
      mp = key_4x4_dw ();
      hienthi_tg ();
      hienthi_off();

      if (mp!= 0xff)
      {
         if (mp < 10)
         {
            tg = mp;
         }

         if (mp == 10)  // nham A, buzzer
         {
            XUAT_32LED_don_4byte(0,0,0,0xFF); // BUZZER_ON(); > thay xuat led, giam on
            hienthi_on ();
            delay_ms (1000 * tg);
            
            XUAT_32LED_don_4byte(0,0,0,1);   // BUZZER_OFF();
            hienthi_off ();
         }
      }
   }
}

