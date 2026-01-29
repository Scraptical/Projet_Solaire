from time import*
from machine import*
from pyb import ADC, Pin

uart = UART(1) # Instance de l'UART numéro 1
# Initialisation à 9600 bauds, trames de 8 bits,
#sans contrôle de parité avec un stop bit à 1
uart.init(115200, bits=8, parity=None, stop = 1)


ledV=Pin('D3',Pin.OUT_PP)
ledR=Pin('D2',Pin.OUT_PP)

while True:
    
        ledR.off()
        ledV.on()
        sleep_ms(500)
        ledV.off()
        sleep_ms(500)
        print("Batterie chargée")
        uart.write(b"\"D\";\"B\":14V;\"I\":5A;\"F\"")
        print(b"\"D\";\"B\":14V;\"I\":5A;\"F\"")
        sleep_ms(500)
        
    
    
    
    
