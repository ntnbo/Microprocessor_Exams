
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
signed int8       giay, bdn, phut; 
#int_timer1 

void interrupt_timer1() 
{   
   bdn++;
   set_timer1 (3036);   // so dem bat dau
}
     
void giai_ma_gan_cho_8led_quet() 
{   
   led_7dq[0] = ma7doan [giay % 10];
   led_7dq[1] = ma7doan [giay / 10];
   led_7dq[3] = ma7doan [phut % 10];
   led_7dq[4] = ma7doan [phut / 10];
}

void main() 
{   
   set_up_port_ic_chot ();
   setup_timer_1 (t1_internal|t1_div_by_1);     // khoi tao ngat timer1, nhanh hon T1_DIV_BY_1
   set_timer1 (3036);   // so dem bat dau
   enable_interrupts (global);      // cho interrupts timer1
   enable_interrupts (int_timer1);
   giay = 0;
   bdn = 0;
   phut = 0;

   while (true)
   {
      giai_ma_gan_cho_8led_quet ();
      if (bdn < 10) hien_thi_8led_7doan_quet ();

      else
      {
         bdn = bdn - 10;      // timer dem nhieu hon 10 can --> tinh cho lan sau
         giay++;
         if (giay == 60) 
         {
            giay = 0;
            phut++;
            if (phut == 60) phut =0;    
         }
      }
   }
}

