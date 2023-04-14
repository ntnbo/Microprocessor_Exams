#include <tv_pickit2_shift_1.c> 
#include <tv_pickit2_shift_lcd.c> 
 
void main() 
{      
 set_up_port_ic_chot(); 
    setup_lcd();      
    lcd_command(lcd_addr_line1);  
    lcd_data("khoa dien");    
    lcd_command(lcd_addr_line2);                     
    lcd_data("bm dientu");    
    delay_ms(1000);                                
    while(true)  
    { 
 lcd_command(lcd_shift_left); // lcd_shift_left > bi loi, hien thi du hang 3,4
        delay_ms(1000); 
    } 
} 
