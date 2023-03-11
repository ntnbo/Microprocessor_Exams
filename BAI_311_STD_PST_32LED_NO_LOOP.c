//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
unsigned    INT8    dem_led; 
unsigned    INT32    y; 
void delay_tuy_y(UNSIGNED int8 dl2) 
{
   UNSIGNED int8 dl;
   FOR (dl = 0; dl < dl2; dl++) delay_ms (10);
}

void sang_tat_dan_pst_32led(UNSIGNED int8 dl) 
{
   
   IF (dem_led < 32)
   {
      xuat_32led_don_1dw (y);
      y = (y<<1) + 1;
      delay_tuy_y (dl);
      dem_led++;
   }

   else IF (dem_led < 64)
   {
      xuat_32led_don_1dw (y);
      y = (y<<1);
      delay_tuy_y (dl);
      dem_led++;
   }

   ELSE
   {
      dem_led = 0;
      y = 0;
   }

   dem_led++;
}

void main() 
{
   
   set_up_port_ic_chot ();
   y = 0;
   WHILE (true)
   {
      sang_tat_dan_pst_32led (2);
      //cac yeu cau dieu khien khac
   }
}


