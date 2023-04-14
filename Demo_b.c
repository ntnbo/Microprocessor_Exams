//Câu b: 
#include <tv_pickit2_shift_1.c>
//!#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_key4x4_138.c>

signed int8 sp , ch_sp , dv_sp , i ;
signed int8 bdn, time, ch_time_lon, dv_time_lon, ch_time_nho, dv_time_nho ;

#int_timer1
void interrupt_timer1()
{ 
//!   bdn_nn++;
   bdn++; 
//!   bdn_led ++;
   set_timer1(3036); 
}

void lcd_hienthi_so_z_toado_xy(signed int8 lcd_so, x1, y1)     
{
   lcd_goto_xy (x1, y1) ;
   for (i = 0; i < 6; i++)
   {
      if (i == 3) lcd_goto_xy (x1 + 1, y1);
      lcd_data (lcd_so_x[lcd_so][i]) ;
   }
}

void gm_lcd_so_lon()
{
   ch_time_lon=time/10;
   dv_time_lon=time%10;

   if(ch_time_lon==0) ch_time_lon=10;  //10 khoang trang , xoa so 0 vn
   
}

void gm_lcd_so_nho()
{
   dv_time_nho = time % 10 +  0x30; //
   ch_time_nho = time / 10 +  0x30;


   if (ch_time_nho == 0x30) ch_time_nho = 0x20; // xoa so 0 vn 0x20 khoang trang
}

void ht_lcd_nho()
{
   lcd_goto_xy (0, 12) ;   // vi tri hien thi hang-cot
   lcd_data (ch_time_nho) ;
   lcd_data (dv_time_nho) ;
}

void giai_ma_counter0_4led_7d()
{
   ch_sp = ma7doan[sp / 10 ];
   dv_sp = ma7doan[sp % 10];
     
   if (ch_sp == 0xc0) ch_sp = 0xff;
}

void hien_thi_counter0_4led_7d()
{
   xuat_4led_7doan_4so (dv_sp&0x7f, 0x8f, 0x39, ch_sp) ;
}

void main()
{
   set_up_port_ic_chot();
   setup_lcd ();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1|t0_8_bit); //setup_timer_0(t0_off);
   set_timer0 (8);
   sp = 0 ;
   
   time = 3 ;  // id num, num start
   
   lcd_command (0x40);
   for (i = 0; i < 64; i++) { lcd_data (lcd_ma_8doan[i]); }    // khoi tao cac ki tu tu tao
   
   setup_timer_1(t1_internal | t1_div_by_8); //setup_timer_1(t1_disabled);   
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer1);
   
   lcd_command(0x80+6) ; lcd_data("DemSP=") ;      //lcd_command: vi tri
   lcd_command(0xc0) ; lcd_data("Don vi:") ;
   lcd_command(0xc0 + 15) ; lcd_data("Chuc:") ;
   
   
   while(true)
   {  
      //a
      sp=get_timer0();
      if(sp > 16) set_timer0(8);    //num start, num back
      giai_ma_counter0_4led_7d() ;
      hien_thi_counter0_4led_7d();
      
      //b
      if( bdn > 10)
      {
         time++ ; 
         if( time>15) time = 3 ;
         bdn = bdn - 10 ;
      }
      else 
      {
         gm_lcd_so_lon() ; 
         gm_lcd_so_nho() ; 
         
         ht_lcd_nho() ;
         lcd_hienthi_so_z_toado_xy(dv_time_lon,2,0) ;    //ht so lon; so ht-hang-cot
         lcd_hienthi_so_z_toado_xy(ch_time_lon,2,17) ;
      }
   }
}
