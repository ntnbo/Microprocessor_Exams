//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_1.c>
#include <TV_PICKIT2_SHIFT_KEY4X4_138.C>
#include <tv_pickit2_shift_lcd.c>

signed int8 giay, mp, bdn;
signed int8 led1, led2, led3, led4;
unsigned int8 gt_mod, GH_tren, GH_duoi;
signed int8 i;
unsigned int8 dem, thung, gt_datdem, gt_datdem1, gt_datdem2 ;
int1 tt_giay, tt_dem;

#int_timer1
void interrupt_timer1()  
{ 
   bdn++; 
   set_timer1(3036); 
}

void lcd_hienthi_so_z_toado_xy(signed int8 lcd_so, x1, y1)
{
   lcd_goto_xy (x1, y1) ;
   for (i = 0; i < 6; i++)
   {
      if (i == 3) lcd_goto_xy (x1 + 1, y1);
      lcd_data (lcd_so_x[lcd_so][i]);
   }
}

void giai_ma_gan_cho_8led_quet()    //a
{ 
   led_7dq[1] = 0XF1;
   led_7dq[2] = 0X47;
   led_7dq[3] = ma7doan [giay%10]; 
   led_7dq[4] = ma7doan [giay/10]; 
   led_7dq[5] = 0XF1;
   led_7dq[6] = 0X47;
}

void hienthi_4led()     //
{
   if(gt_mod==1)
   {
      if(bdn<4)
      {
         xuat_4led_7doan_4so(ma7doan[led4],ma7doan[led3]&0x7f,ma7doan[led2],ma7doan[led1]);
      }
      else
      {
         xuat_4led_7doan_4so(0xff,0xff&0x7f,ma7doan[led2],ma7doan[led1]);
      }
   }
   if(gt_mod==2)
   {
      if(bdn<4)
      {
         xuat_4led_7doan_4so(ma7doan[led4],ma7doan[led3]&0x7f,ma7doan[led2],ma7doan[led1]);
      }
      else
      {
         xuat_4led_7doan_4so(ma7doan[led4],ma7doan[led3]&0x7f,0xff,0xff);
      }
   }
   else
   {
      xuat_4led_7doan_4so(ma7doan[led4],ma7doan[led3]&0x7f,ma7doan[led2],ma7doan[led1]);
   } 
}

void caidat_giatridem_4led(signed int8 x)
{   
   if(gt_mod==2)
   {
      led2=led1;
      led1=x;
   }
   if(gt_mod==1)
   {
      led4=led3;
      led3=x;
   }
}

void caidat_giatridem_lcd(signed int8 y)
{
   gt_datdem2 = gt_datdem1;
   gt_datdem1 = y;
   gt_datdem = gt_datdem2*10 + gt_datdem1;
}
 
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   setup_lcd ();
   set_timer0 (0);
   lcd_command (0x40);
   
   for (i = 0; i < 64; i++) { lcd_data (lcd_ma_8doan[i]); }
   lcd_hienthi_so_z_toado_xy (0, 0, 0) ;
   set_timer1(3036); 
   enable_interrupts(global);
   enable_interrupts(int_timer1);
   
   giay=11;
   gt_mod=0;
   led1=led2=1;
   led3=4; led4=2;
   GH_tren=24;       //24
   GH_duoi=11;       //11
   
   thung=0;
   gt_datdem=0;
   tt_giay= tt_dem=0;
   while(true)
   {
      //a
      giai_ma_gan_cho_8led_quet();
      if (bdn<7) hien_thi_8led_7doan_quet(); 
      else
      { 
         bdn = bdn-7;
         giay++;
         if (giay>GH_tren) giay = GH_duoi; 
      }
      hien_thi_8led_7doan_quet();     
      
   }
}


