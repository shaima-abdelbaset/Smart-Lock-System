#include <mega16.h>
#include <alcd.h>
#include <delay.h>

//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/eeprom.h>
//#include <mega16.h>
char keypad();
void speakerPipPip();
unsigned char ReadFromEEPROM(unsigned int address);
void WriteInEEPROM(unsigned int address, unsigned char data);
char reedenterdpass ();
char storednnum;                                 
int  number;                                
char first_digit,second_digit,last_digit;   
char enterd = 0;                                 
char Prof;                                 
char Ahmed;                                    
char Amr;                                  
char Adel;
char omar;                                  
unsigned int adminPasscode = 203;             
void main(void) 
{
    DDRC = 0b00000111;
    PORTC = 0b11111000;
   // lcd_init(16); 
   DDRD.2 = 0;                     //INT0
    PORTD.2 = 1;
    DDRD.3 = 0;                     // INT1
    PORTD.3 = 1;
    DDRD.5 = 1;                     // SPEAKER
    PORTB.4 = 0;
    //DDRD.1 = 1;                      
    //External Interupt
    MCUCR |= (1 << 1);               
    MCUCR |= (1 << 0);               
    SREG.7 = 1;                      
    GICR |= (1 << 6);                
    //External Interupt 1
    MCUCR |= (1 << 2);               
    MCUCR |= (1 << 3);               
    SREG.7 = 1;                      
    GICR |= (1 << 7);                
    lcd_init(16);                 
    WriteInEEPROM(111,203%256);  
    WriteInEEPROM(126,123%256);
    WriteInEEPROM(128,315%256);
    WriteInEEPROM(130,223%256);
    WriteInEEPROM(132,279%256); 
    Prof = ReadFromEEPROM(111);        
    Ahmed = ReadFromEEPROM(126);
    Amr =  ReadFromEEPROM(128);
    omar = ReadFromEEPROM(130);
    Adel  = ReadFromEEPROM(132);
    

    while (1) {
      lcd_puts("Please Press * ");
        while(keypad() != '*');
        lcd_clear();
        delay_ms(300); 
        lcd_printf("please Enter ID");  
        enterd=1;
         while (enterd == 1)
  {
    reedenterdpass();
         switch (number)
               {
                case 111:
                   {
                    lcd_clear();
                    lcd_printf("Hi ,Pro ");
                    lcd_printfxy(0,1,"Enter your Old password");
                    reedenterdpass ();
                    storednnum = number%256;
                    if (storednnum == ReadFromEEPROM(111)) 
                        {
                        lcd_clear();
                        lcd_printf("You may Enter.");
                            delay_ms(1000);
                            delay_ms(1000);
                            enterd = 0;

                            }
                        else
                            {
                            lcd_clear();
                            lcd_printf(" Wrong Password ");
                            speakerPipPip();
                            delay_ms(1000);
                            enterd = 0;

                            }
                        }
               break;  
               case 126:
                   {
                    lcd_clear();
                    lcd_printf("Hi ,Ahmed");
                    lcd_printfxy(0,1,"Enter your Old password");
                    reedenterdpass ();
                    storednnum = number;   
                     delay_ms(2000);
                    if (storednnum == ReadFromEEPROM(126)) 
                        {
                        lcd_clear();
                        lcd_printf("Enter new password");
                        reedenterdpass ();
                        reedenterdpass ();
                        storednnum = number%256;
                        lcd_clear();
                       if (storednnum == ReadFromEEPROM(126)) 
                        {
                        lcd_clear();
                        lcd_printf("You may Enter.");
                            delay_ms(1000);
                            delay_ms(1000);
                            enterd = 0;

                            }
                        else
                            {
                            lcd_clear();
                            lcd_printf(" Wrong Password ");
                            speakerPipPip();
                            delay_ms(1000);
                            enterd = 0;

                            }
                        }}
               break;    
                case 128:
                   {
                    lcd_clear();
                    lcd_printf("Hi, Amr");
                    lcd_printfxy(0,1,"Enter your Old password");
                    reedenterdpass ();
                    storednnum = number; 
                    delay_ms(2000);
                   if (storednnum == ReadFromEEPROM(128)) 
                        {
                        lcd_clear();
                        lcd_printf("You may Enter.");
                            delay_ms(1000);
                            delay_ms(1000);
                            enterd = 0;

                            }
                        else
                            {
                            lcd_clear();
                            lcd_printf(" Wrong Password ");
                            speakerPipPip();
                            delay_ms(1000);
                            enterd = 0;

                            }
                        }
               break;
               case 130:
               {
                 lcd_clear();
                    lcd_printf("Hi, Adel");
                    lcd_printfxy(0,1,"Enter your Old PC");
                    reedenterdpass ();
                    storednnum = number;
                     delay_ms(2000);
                   if (storednnum == ReadFromEEPROM(130)) 
                        {
                        lcd_clear();
                        lcd_printf("You may Enter.");
                            delay_ms(1000);
                            delay_ms(1000);
                            enterd = 0;

                            }
                        else
                            {
                            lcd_clear();
                            lcd_printf(" Wrong Password ");
                            speakerPipPip();
                            delay_ms(1000);
                            enterd = 0;

                            }
                        }
               break;
                case 132:
               {
                 lcd_clear();
                    lcd_printf("Hi, Omar");
                    lcd_printfxy(0,1,"Enter your Old PC");
                    reedenterdpass ();
                    storednnum = number;
                      delay_ms(2000);
                   if (storednnum == ReadFromEEPROM(128)) 
                        {
                        lcd_clear();
                        lcd_printf("You may Enter.");
                            delay_ms(1000);
                            delay_ms(1000);
                            enterd = 0;

                            }
                        else
                            {
                            lcd_clear();
                            lcd_printf(" Wrong Password ");
                            speakerPipPip();
                            delay_ms(1000);
                            enterd = 0;

                            }
                        }
               break;
               }
        
                } } 
  }
char reedenterdpass ()
{
    first_digit = keypad();
    lcd_clear();
    lcd_printf("You Entered: %d", first_digit);
    delay_ms(300);
    lcd_clear();
    lcd_printf("You Entered: *");
    second_digit = keypad();
    lcd_clear();
    lcd_printf("You Entered: *%d" ,second_digit);
    delay_ms(300);
    lcd_clear();
    lcd_printf("You Entered: **");
    last_digit = keypad();
    lcd_clear();
    lcd_printf("You Entered: **%d",last_digit);
    delay_ms(300);
    lcd_clear();
    lcd_printf("You Entered: *");
    number = first_digit * 100 + second_digit * 10 + last_digit;
    return number, first_digit, second_digit, last_digit;
}
 unsigned char ReadFromEEPROM(unsigned int address)
{
    while(EECR.1 == 1);    //Wait till EEPROM is ready
    EEAR = address;        //Prepare the address you want to read from

    EECR.0 = 1;            //Execute read command

    return EEDR;

}

void WriteInEEPROM(unsigned int address, unsigned char data)
{
    while(EECR.1 == 1);    //Wait till EEPROM is ready
    EEAR = address;        //Prepare the address you want to read from
    EEDR = data;           //Prepare the data you want to write in the address above
    EECR.2 = 1;            //Master write enable
    EECR.1 = 1;            //Write Enable
}
  void speakerPipPip() {
    int i;
    for ( i = 0; i < 2; ++i) { // Pips twice
        PORTB.4 = 1; // Assuming PORTD.5 controls the speaker
        delay_ms(100); // Speaker ON for 100 milliseconds (adjust as needed)
        PORTB.4 = 0; // Speaker OFF
        delay_ms(100); // Wait before the next pip
    }
    delay_ms(500); // Extra delay between pips
}

 void Admin_changes(void) {
 unsigned char Adminpasscode, student_ID,student_password ;
 delay_ms(250);
    lcd_printf("enter your passcode");
    delay_ms(1000);
    lcd_clear();
    Adminpasscode =  reedenterdpass(); 
    if (Adminpasscode == adminPasscode)
        {
        lcd_printf("Welcame");
        delay_ms(300);
        lcd_clear();
        lcd_printf("Enter student_ID");
        delay_ms(5000);
        student_ID =  reedenterdpass();
        delay_ms(300);
        lcd_printf("Enter The New Password: ");
        student_password =  reedenterdpass();
        WriteInEEPROM(student_ID , student_password%256);
        lcd_printf("changed Done");
        delay_ms(300);
        lcd_clear();
        }

    else
        {
        lcd_printf("Wrong Admin Password,please enter correct one ");
        delay_ms(1000);
        lcd_clear();
        }

}
void user_Change_Password(void)
{
  unsigned char newpassword;
  lcd_clear();
  enterd = 1;
  lcd_printf("ENTER YOUR ID");
  delay_ms(1000);
  lcd_clear();
  while (enterd == 1)
  {
    reedenterdpass();
         switch (number)
               {
               case 126:
                   {
                    lcd_clear();
                    lcd_printf("Hi ,Ahmed");
                    lcd_printfxy(0,1,"Enter your Old password");
                    reedenterdpass ();
                    storednnum = number;
                    if (storednnum == ReadFromEEPROM(126)) 
                        {
                        lcd_clear();
                        lcd_printf("Enter new password");
                        reedenterdpass ();
                        newpassword = number % 256;
                        lcd_clear();
                        lcd_printf("Re-enter new password");
                        reedenterdpass ();
                        storednnum = number%256;
                        lcd_clear();
                        if (newpassword == storednnum)
                            {
                             WriteInEEPROM(126, storednnum);
                             lcd_printf("Password changed");
                             delay_ms(500);
                             lcd_clear();
                             enterd = 0;
                            }
                        else
                            {
                             lcd_printf("Not matched");
                             lcd_clear();
                             speakerPipPip();
                             delay_ms(500);
                             lcd_clear();
                              enterd= 0;
                             }
                        }       
                    else
                        {
                         lcd_clear();
                         lcd_printf("Wrong Password!");
                         speakerPipPip();
                         delay_ms(500);
                         enterd = 0;
                        }
                    }
               break;    
                case 128:
                   {
                    lcd_clear();
                    lcd_printf("Hi, Amr");
                    lcd_printfxy(0,1,"Enter your Old password");
                    reedenterdpass ();
                    storednnum = number;
                    if (storednnum == ReadFromEEPROM(128)) 
                        {
                        lcd_clear();
                        lcd_printf("Enter new PC !");
                        reedenterdpass ();
                        newpassword = number % 256;
                        lcd_clear();
                        lcd_printf("Re-enter new password");
                        reedenterdpass ();
                        storednnum = number%256;
                        lcd_clear();
                        if (newpassword == storednnum)
                            {
                             WriteInEEPROM(128, storednnum);
                             lcd_printf("password changed");
                             delay_ms(500);
                             lcd_clear();
                             enterd = 0;
                            }
                        else
                            {
                             lcd_printf("Not matched");
                             lcd_clear();
                             speakerPipPip();
                             delay_ms(500);
                             lcd_clear();
                             enterd = 0;
                             }
                        }
                    else
                        {
                         lcd_clear();
                         lcd_printf("Wrong Password!");  
                         speakerPipPip();
                         delay_ms(500);
                         enterd = 0;
                        }
                    }
               break;
               case 130:
               {
                 lcd_clear();
                    lcd_printf("Hi, Adel");
                    lcd_printfxy(0,1,"Enter your Old PC");
                    reedenterdpass ();
                    storednnum = number;
                    if (storednnum == ReadFromEEPROM(130)) 
                        {
                        lcd_clear();
                        lcd_printf("Enter new PC !");
                        reedenterdpass ();
                        newpassword = number % 256;
                        lcd_clear();
                        lcd_printf("Re-enter new password");
                        reedenterdpass ();
                        storednnum = number%256;
                        lcd_clear();
                        if (newpassword == storednnum)       
                            {
                             WriteInEEPROM(130, storednnum);
                             lcd_printf("password changed");
                             delay_ms(1000);
                             lcd_clear();
                             enterd = 0;
                            }
                        else
                            {
                             lcd_printf("Not matched");
                             lcd_clear(); 
                             speakerPipPip();
                             delay_ms(1000);
                             lcd_clear();
                             enterd = 0;
                             }
                        }
                    else
                        {
                         lcd_clear();
                         lcd_printf("Wrong Password!"); 
                         speakerPipPip();
                         delay_ms(1000);
                         enterd = 0;
                        }
                    }

               break; 
                case 132:
               {
                 lcd_clear();
                    lcd_printf("Hi, Omar");
                    lcd_printfxy(0,1,"Enter your Old PC");
                    reedenterdpass ();
                    storednnum = number;
                    if (storednnum == ReadFromEEPROM(130)) 
                        {
                        lcd_clear();
                        lcd_printf("Enter new PC !");
                        reedenterdpass ();
                        newpassword = number % 256;
                        lcd_clear();
                        lcd_printf("Re-enter new password");
                        reedenterdpass ();
                        storednnum = number%256;
                        lcd_clear();
                        if (newpassword == storednnum)
                            {
                             WriteInEEPROM(130, storednnum);
                             lcd_printf("password changed");
                             delay_ms(1000);
                             lcd_clear();
                             enterd = 0;
                            }
                        else
                            {
                             lcd_printf("Not matched");
                             lcd_clear();  
                             speakerPipPip();
                             delay_ms(1000);
                             lcd_clear();
                             enterd = 0;
                             }
                        }
                    else
                        {
                         lcd_clear();
                         lcd_printf("Wrong Password!"); 
                            speakerPipPip();
                         delay_ms(1000);
                         enterd = 0;
                        }
                    }

               break;
               }
               }
  }
char keypad()   
{
    while(1)
        {
        PORTC.0 = 0;
        PORTC.1 = 1;
        PORTC.2 = 1;
        
        switch(PINB)
            {
            case 0b11110110:
                while (PINC.3 == 0);
                return 1;
                break;

            case 0b11101110:
                while (PINC.4 == 0);
                return 4;
                break;

            case 0b11011110:
                while (PINC.5 == 0);
                return 7;
                break;

            case 0b10111110:
                while (PINC.6 == 0);
                return '*';
                break;

            }
        PORTC.0 = 1;
        PORTC.1 = 0;
        PORTC.2 = 1;
        
        switch(PINC)
            {
            case 0b11110101:
                while (PINC.3 == 0);
                return 2;
                break;

            case 0b11101101:
                while (PINC.4 == 0);
                return 5;
                break;

            case 0b11011101:
                while (PINC.5 == 0);
                return 8;
                break;

            case 0b10111101:
                while (PINC.6 == 0);
                return 0;
                break;

            }
        PORTC.0 = 1;
        PORTC.1 = 1;
        PORTC.2 = 0;
    
        switch(PINC)
            {
            case 0b11110011:
                while (PINC.3 == 0);
                return 3;
                break;

            case 0b11101011:
                while (PINC.4 == 0);
                return 6;
                break;

            case 0b11011011:
                while (PINC.5 == 0);
                return 9;
                break;

            case 0b10111011:
                while (PINC.6 == 0);
                return 11;
                break;

            }

        }
}