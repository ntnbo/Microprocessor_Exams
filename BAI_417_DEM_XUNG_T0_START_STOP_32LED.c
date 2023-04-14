
//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
unsigned int16 t0 , t0_tam ;
unsigned int TT_CT ;

void kt_on()
{
   if (input (on) == 0)
   {
      delay_ms (20);
      {
         if (input (on) == 0)
         {
            TT_CT = 0;
            while (input (on) == 0) ;
         }
      }
   }
}

void kt_off()  //ham chong doi phim 323
{
   if (input (off) == 0)
   {
      delay_ms (20);
      {
         if (input (off) == 0)
         {
            TT_CT = 1;
            while (input (off) == 0) ;
         }
      }
   }
}

void main()
{
   set_up_port_ic_chot ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1) ;
   set_timer0 (0);
   TT_CT = 1;
   t0_tam = t0 = 0;
   
   xuat_4led_7doan_giaima_xoa_so0 (t0);
   
   while (true)
   {
      kt_on ();
      kt_off ();
      if (TT_CT == 0)
      {
         setup_timer_0 (t0_ext_l_to_h);
         t0 = get_timer0 () ;
         if (t0 != t0_tam)
         {
            t0_tam = t0;
            xuat_4led_7doan_giaima_xoa_so0 (t0);
            if (t0 >= 101) set_timer0 (1) ;
         }

         xuat_32led_don_1dw (0xffffffff);
      }

      else
      {
         xuat_32led_don_1dw (0);
         setup_timer_0 (t0_off);    // OFF tat led
      }
   }
}


