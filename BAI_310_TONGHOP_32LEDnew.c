//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
unsigned int8 i,j;
unsigned int32 y;
unsigned int16 zt,zp;

void sang_tat_32led_5lan()
{
   for(j=0;j<5;j++)
   {
      xuat_32led_don_4byte(0,0,0,0);
      delay_ms(200);
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      delay_ms(200);
   }
}

void sang_tat_dan_pst_32led_2lan()
{
   for(j=0;j<2;j++)
   {
      for(i=0;i<32;i++)
      {
         xuat_32led_don_1dw(y);
         delay_ms(100);
         y= (y<<1)+1;
      }
      for(i=0;i<32;i++)
      {
         xuat_32led_don_1dw(y);
         delay_ms(100);
         y= (y<<1);
      }
   }
}

void sang_tat_dan_tsp_32led_2lan()
{
   for(j=0;j<2;j++)
   {
      for(i=0;i<32;i++)
      {
         xuat_32led_don_1dw(y);
         delay_ms(100);
         y= (y>>1)+0x80000000;
      }
      for(i=0;i<32;i++)
      {
         xuat_32led_don_1dw(y);
         delay_ms(100);
         y= (y>>1);
      }
   }
}

void sang_tat_dan_ngoai_vao_32led_2lan()
{
   for(j=0;j<2;j++)
   {
      for(i=0;j<16;i++)
      {
         xuat_32led_don_2word(zp,zt);
         delay_ms(30);
         zp= (zp<<1)+1;
         zt= (zt>>1)+0x8000;
      }
      for(i=0;i<16;i++)
      {
         xuat_32led_don_2word(zp,zt);
         delay_ms(30);
         zp= (zp<<1);
         zt= (zt>>1);
      }
   } 
}

void sang_tat_dan_trong_ra_32led_2lan()
{
   for(j=0;j<2;i++)
   {
      for(i=0;i<16;i++)
      {
         xuat_32led_don_2word(zp,zt);
         delay_ms(100);
         zp= (zp>>1)+0x8000; zt= (zt<<1)+1;
      }
      for(i=0;i<16;i++)
      {
         xuat_32led_don_2word(zp,zt);
         delay_ms(100);
         zp= (zp>>1);
         zt= (zt<<1);
      }
   }
}

void main()
{
   set_up_port_ic_chot();
   y=0x00000000;
   while(true)
   {
      sang_tat_32led_5lan();
      sang_tat_dan_ngoai_vao_32led_2lan();
      sang_tat_dan_trong_ra_32led_2lan();
   }
}
