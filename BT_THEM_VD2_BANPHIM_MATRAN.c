// Ban Phim, Ma tran
// Phim 0-7, dieu khien 8 led tuong ung. vd: bam 0 > led 0 sang > bam lan 2 > led 0 tat


//!#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_1_proteus.c>
#include <tv_pickit2_shift_key4x4_138.c>

unsigned int y, mp;     //mp luu tru ma phim
int1 t0, t1, t2, t3, t4, t5, t6, t7;

void xuat(int1 t)
{
   if (t==0) bit_clear(y,mp);
   else bit_set(y,mp);
   xuat_32led_don_4byte(0,0,0,y);
   delay_ms(200);
}

void main()
{
   mp=key_4x4_dw();
   switch(mp)
   {
      case 0:  t0=~t0;
               xuat(t0);
               break;
      case 1:  t1=~t1;
               xuat(t1);
               break;
      case 2:  t2=~t2;
               xuat(t2);
               break;  
      case 3:  t3=~t3;
               xuat(t3);
               break;
      case 4:  t4=~t4;
               xuat(t4);
               break;
      case 5:  t5=~t5;
               xuat(t5);
               break; 
      case 6:  t6=~t6;
               xuat(t6);
               break;
      case 7:  t7=~t7;
               xuat(t7);
               break;                
   }
}
