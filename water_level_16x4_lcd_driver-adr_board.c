#include <16f877a.h>
#use delay(clock=20000000)
#fuses nowdt,nobrownout,HS,nolvp

#define RS        pin_e1    // rs     >> e1
#define EN        pin_e2    // Enable >> e2;

void lcd_data(char data)
{
  output_high(RS);
 
  output_a(( data>>4) & 0x2f); //output_d( data>>4);// & 0xf0);
  output_high(EN);
  delay_ms(2);
  output_low(EN);
 
  output_a((data)& 0x2f); 
  output_high(EN);
  delay_ms(2);
  output_low(EN);
}

void lcd_cmd(char cmd)
{
  
  output_low(RS);    
  
  output_a((cmd>>4)& 0x0f);
  output_high(EN);
  delay_ms(2);
  output_low(EN);

  output_a((cmd)& 0x0f); 
  output_high(EN);
  delay_ms(2);
  output_low(EN);

}

void lcd_init()
{
  lcd_cmd(0x33);
  lcd_cmd(0x32);
  lcd_cmd(0x28);
  lcd_cmd(0x0c);
  lcd_cmd(0x06);
  lcd_cmd(0x80);
  delay_ms(10);
}

void main()
{
   lcd_init(); 
   lcd_cmd(0x01);
   delay_ms(100); 
   set_tris_a(0x00);
   set_tris_c(0x00);

   output_a(0x00);
   output_c(0x00);
 while(true)
 {  
  lcd_cmd(0x01);
  delay_ms(100);
  lcd_data("love u all 123");
  delay_ms(1000);
 }
}

