/* C Code for Blinking LED 
 https://youtu.be/j-qs-gJhxfs
 https://akuzechie.blogspot.com/
*/

//the following instructions will be located externally to this ino file
extern "C"                             
{
void start();                //define the function prototypes here. 
void led(byte); 
}

void setup() {              // put your setup code here, to run once
start();
pinMode(13, OUTPUT);
}

void loop() {               // put your main code here, to run repeatedly in a loop
led(1);                     // Led ON
delay(100);                 // 100 ms
led(0);                     // Led OFF
delay(100);                 // 100 ms
return 0;
}
