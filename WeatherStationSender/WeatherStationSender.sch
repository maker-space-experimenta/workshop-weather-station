EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A?
U 1 1 5E3F5EAB
P 5600 3700
F 0 "A?" H 5600 2611 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 5600 2520 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 5600 3700 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 5600 3700 50  0001 C CNN
	1    5600 3700
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AZ1117-3.3 U?
U 1 1 5E3F68B8
P 7350 4350
F 0 "U?" H 7350 4592 50  0000 C CNN
F 1 "AZ1117-3.3" H 7350 4501 50  0000 C CNN
F 2 "" H 7350 4600 50  0001 C CIN
F 3 "https://www.diodes.com/assets/Datasheets/AZ1117.pdf" H 7350 4350 50  0001 C CNN
	1    7350 4350
	1    0    0    -1  
$EndComp
$Comp
L RF:NRF24L01_Breakout U?
U 1 1 5E3F6FDC
P 7450 3050
F 0 "U?" H 7830 3096 50  0000 L CNN
F 1 "NRF24L01_Breakout" H 7830 3005 50  0000 L CNN
F 2 "RF_Module:nRF24L01_Breakout" H 7600 3650 50  0001 L CIN
F 3 "http://www.nordicsemi.com/eng/content/download/2730/34105/file/nRF24L01_Product_Specification_v2_0.pdf" H 7450 2950 50  0001 C CNN
	1    7450 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E3F95DE
P 3200 3350
F 0 "#PWR?" H 3200 3200 50  0001 C CNN
F 1 "+5V" H 3215 3523 50  0000 C CNN
F 2 "" H 3200 3350 50  0001 C CNN
F 3 "" H 3200 3350 50  0001 C CNN
	1    3200 3350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Female J?
U 1 1 5E3F8423
P 3300 3150
F 0 "J?" V 3238 2962 50  0000 R CNN
F 1 "Conn_01x03_Female" V 3147 2962 50  0000 R CNN
F 2 "" H 3300 3150 50  0001 C CNN
F 3 "~" H 3300 3150 50  0001 C CNN
	1    3300 3150
	0    -1   -1   0   
$EndComp
Text GLabel 3300 3350 3    50   Input ~ 0
DHT_DATA
$Comp
L power:GND #PWR?
U 1 1 5E3F9F2A
P 3400 3350
F 0 "#PWR?" H 3400 3100 50  0001 C CNN
F 1 "GND" H 3405 3177 50  0000 C CNN
F 2 "" H 3400 3350 50  0001 C CNN
F 3 "" H 3400 3350 50  0001 C CNN
	1    3400 3350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E3FBBA3
P 5800 2700
F 0 "#PWR?" H 5800 2550 50  0001 C CNN
F 1 "+5V" H 5815 2873 50  0000 C CNN
F 2 "" H 5800 2700 50  0001 C CNN
F 3 "" H 5800 2700 50  0001 C CNN
	1    5800 2700
	1    0    0    -1  
$EndComp
Text HLabel 5100 3300 0    50   Input ~ 0
DHT_DATA
Text HLabel 6950 2750 0    50   Input ~ 0
NRF_MOSI
Text HLabel 6950 2850 0    50   Input ~ 0
NRF_MISO
Text HLabel 6950 2950 0    50   Input ~ 0
NRF_SCK
Text HLabel 6950 3050 0    50   Input ~ 0
NRF_CSN
Text HLabel 6950 3250 0    50   Input ~ 0
NRF_ENABLE
$Comp
L power:+3.3V #PWR?
U 1 1 5E3FC56E
P 7450 2450
F 0 "#PWR?" H 7450 2300 50  0001 C CNN
F 1 "+3.3V" H 7465 2623 50  0000 C CNN
F 2 "" H 7450 2450 50  0001 C CNN
F 3 "" H 7450 2450 50  0001 C CNN
	1    7450 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E3FCECA
P 7450 3650
F 0 "#PWR?" H 7450 3400 50  0001 C CNN
F 1 "GND" H 7455 3477 50  0000 C CNN
F 2 "" H 7450 3650 50  0001 C CNN
F 3 "" H 7450 3650 50  0001 C CNN
	1    7450 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E3FD05F
P 7350 4650
F 0 "#PWR?" H 7350 4400 50  0001 C CNN
F 1 "GND" H 7355 4477 50  0000 C CNN
F 2 "" H 7350 4650 50  0001 C CNN
F 3 "" H 7350 4650 50  0001 C CNN
	1    7350 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5E3FD273
P 7650 4350
F 0 "#PWR?" H 7650 4200 50  0001 C CNN
F 1 "+3.3V" V 7665 4478 50  0000 L CNN
F 2 "" H 7650 4350 50  0001 C CNN
F 3 "" H 7650 4350 50  0001 C CNN
	1    7650 4350
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E3FD46B
P 7050 4350
F 0 "#PWR?" H 7050 4200 50  0001 C CNN
F 1 "+5V" V 7065 4478 50  0000 L CNN
F 2 "" H 7050 4350 50  0001 C CNN
F 3 "" H 7050 4350 50  0001 C CNN
	1    7050 4350
	0    -1   -1   0   
$EndComp
Text HLabel 5100 4400 0    50   Input ~ 0
NRF_SCK
Text HLabel 5100 4300 0    50   Input ~ 0
NRF_MISO
Text HLabel 5100 4200 0    50   Input ~ 0
NRF_MOSI
Text HLabel 5100 4100 0    50   Input ~ 0
NRF_CSN
Text HLabel 5100 4000 0    50   Input ~ 0
NRF_ENABLE
$EndSCHEMATC
