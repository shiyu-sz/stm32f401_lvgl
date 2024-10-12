
### 接线  
串口：  
PA9 -> RX  
PA10 -> TX  

LCD:  
PA4 -> LCD_LED  
PB0 -> LCD_RS  
PB1 -> LCD_RST  
PB2 -> LCD_CS  
PA5 -> SCK  
PA6 -> MISO  
PA7 -> MOSI  

TP:  
PA2 -> CTP_INT  
PA3 -> CTP_RST  
PB6 -> CTP_SCL  
PB7 -> CTP_SDA  

### crash  
./Third_Party/CmBacktrace/tools/addr2line/win64/addr2line.exe -e ./MDK-ARM/stm32f401_lvgl/stm32f401_lvgl.axf -afpiC 080050e6 08002dfa  