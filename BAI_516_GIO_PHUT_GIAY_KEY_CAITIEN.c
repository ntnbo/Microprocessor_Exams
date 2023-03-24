
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>

signed int8    gio,phut,giay,bdn,gia_tri_mod; 

#int_timer1
void interrupt_timer1() 
{
   
   bdn++;
   set_timer1 (3036);
}

void giai_ma_gan_cho_8led_quet() 
{
   
   led_7dq[0] = ma7doan [giay % 10];
   led_7dq[1] = ma7doan [giay / 10];
   led_7dq[3] = ma7doan [phut % 10];
   led_7dq[4] = ma7doan [phut / 10];
   led_7dq[6] = ma7doan [gio % 10];
   led_7dq[7] = ma7doan [gio / 10];
   
   if (gia_tri_mod == 1) led_7dq[6] = led_7dq[6]&0x7f;
   else if (gia_tri_mod == 2) led_7dq[3] = led_7dq[3]&0x7f;
   else if (gia_tri_mod == 3) led_7dq[0] = led_7dq[0]&0x7f;
}

       
void phim_mod() 
{
   if (phim_bt1 (200))
   {
      gia_tri_mod++;
      if (gia_tri_mod >= 4) gia_tri_mod = 0;
   }
}

  
void phim_up() 
{
   if (phim_bt0 (200))
   {
      switch (gia_tri_mod)
      {
         case 1: if (gio == 23) gio = 0;
         else gio++;
         break;
         case 2: if (phut == 59) phut = 0;
         else phut++;
         break;
         case 3: if (giay == 59) giay = 0;
         else giay++;
         break;
         default: break;
      }
   }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void phim_dw() 
{
   if (phim_bt2 (200))
   {
      switch (gia_tri_mod)
      {
         case 1: if (gio == 0) gio = 23;
         else gio--;
         break;
         case 2: if (phut == 0) phut = 59;
         else phut--;
         break;
         case 3: if (giay == 0) giay = 59;
         else giay--;
         break;
         default: break;
      }
   }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void main() 
{
   
   set_up_port_ic_chot ();
   setup_timer_1 (t1_internal|t1_div_by_8);
   set_timer1 (3036);
   enable_interrupts (global);
   enable_interrupts (int_timer1);;
   giay = 0x00;
   phut = 0;
   gio = 0;
   gia_tri_mod = 0;

   while (true)
   {
      giai_ma_gan_cho_8led_quet ();

      if (bdn < 10)
      {
         hien_thi_8led_7doan_quet ();
         phim_mod (); phim_up (); phim_dw ();
      }

      else
      {
         bdn = bdn - 10;
         giay++;

         if (giay == 60)
         {
            giay = 0;
            phut++;

            if (phut == 60)
            {
               phut = 0;
               gio++;
               if (gio == 24) gio = 0;
            }
         }
      }
   }
}

