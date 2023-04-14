#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_key4x4_138.c>

signed int8 sp , ch_sp , dv_sp ;
signed int8 giay, mp, bdn;
unsigned int8 gt_mod, GH_tren, GH_duoi;
signed int8 i;


#int_timer1
void interrupt_timer1()  
{ 
   bdn++; 
   set_timer1(3036); 
}

void giai_ma_counter0_4led_7d()
{
   ch_sp = ma7doan[sp / 10 ];
   dv_sp = ma7doan[sp % 10];
     
   if (ch_sp == 0xc0) ch_sp = 0xff;
}

void hien_thi_counter0_4led_7d()
{
   // _|.YZ.|_
   xuat_4led_7doan_4so (0x71, dv_sp, ch_sp&0x7f, 0xC7); // 0x7f dau cham DP   
}

void giai_ma_gan_cho_8led_quet()
{    
   led_7dq[2] = 0XC7;
   led_7dq[3] = ma7doan [ch_sp %10] &0x7f; 
   led_7dq[4] = ma7doan [dv_sp/10]; 
   led_7dq[5] = 0X71;  
}

void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   setup_lcd ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit); //setup_timer_0(t0_off);
   set_timer0 (0);   // numer start
   sp = 0 ;
   
   set_timer1(3036); 
   enable_interrupts(global);
   enable_interrupts(int_timer1);
   
   giay=17;
//!   gt_mod=0;
//!   led1=led2=1;
//!   led3=4; led4=2;
   GH_tren=3;  
   GH_duoi=17;
      
   
   while(true)
   {  
      //a1
      sp= 17 - get_timer0();
      if(sp < 3) set_timer0 (0);
      
      giai_ma_counter0_4led_7d() ;
      hien_thi_counter0_4led_7d();
      
      //a2
      giai_ma_gan_cho_8led_quet();
      if (bdn<3) hien_thi_8led_7doan_quet(); 
      else
      { 
         bdn = bdn-3;
         giay++;
         if (giay>GH_tren) giay = GH_duoi; 
      }
      hien_thi_8led_7doan_quet(); 
   }
}
