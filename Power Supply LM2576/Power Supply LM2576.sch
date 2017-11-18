EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:dc-dc
LIBS:myLib
LIBS:Power Supply LM2576-cache
EELAYER 25 0
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
L LM2576T-ADJ U2
U 1 1 59FFBEDC
P 5050 3750
F 0 "U2" H 4650 4100 50  0000 L CNN
F 1 "LM2576T-ADJ" H 4650 4000 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-5_Vertical_StaggeredType1" H 5350 3500 50  0001 C CIN
F 3 "" H 5050 3750 50  0001 C CNN
	1    5050 3750
	1    0    0    -1  
$EndComp
$Comp
L CP C1
U 1 1 59FFC02B
P 3750 3850
F 0 "C1" H 3775 3950 50  0000 L CNN
F 1 "100u" H 3775 3750 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P2.50mm" H 3788 3700 50  0001 C CNN
F 3 "" H 3750 3850 50  0001 C CNN
	1    3750 3850
	1    0    0    -1  
$EndComp
$Comp
L CP C2
U 1 1 59FFC058
P 6550 4050
F 0 "C2" H 6575 4150 50  0000 L CNN
F 1 "1000u" H 6575 3950 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P2.50mm" H 6588 3900 50  0001 C CNN
F 3 "" H 6550 4050 50  0001 C CNN
	1    6550 4050
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR01
U 1 1 59FFC0A0
P 5050 4200
F 0 "#PWR01" H 5050 3950 50  0001 C CNN
F 1 "GNDA" H 5050 4050 50  0000 C CNN
F 2 "" H 5050 4200 50  0001 C CNN
F 3 "" H 5050 4200 50  0001 C CNN
	1    5050 4200
	1    0    0    -1  
$EndComp
$Comp
L L_Core_Ferrite L1
U 1 1 59FFC0EF
P 5900 3850
F 0 "L1" V 5850 3850 50  0000 C CNN
F 1 "100u" V 6010 3850 50  0000 C CNN
F 2 "Inductors_THT:L_Toroid_Vertical_L26.7mm_W14.0mm_P10.16mm_Pulse_D" H 5900 3850 50  0001 C CNN
F 3 "" H 5900 3850 50  0001 C CNN
	1    5900 3850
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 59FFC12D
P 6250 4050
F 0 "R6" V 6330 4050 50  0000 C CNN
F 1 "?" V 6250 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6180 4050 50  0001 C CNN
F 3 "" H 6250 4050 50  0001 C CNN
	1    6250 4050
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 59FFC170
P 6250 4450
F 0 "R7" V 6330 4450 50  0000 C CNN
F 1 "1k" V 6250 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6180 4450 50  0001 C CNN
F 3 "" H 6250 4450 50  0001 C CNN
	1    6250 4450
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR02
U 1 1 59FFC329
P 6550 4200
F 0 "#PWR02" H 6550 3950 50  0001 C CNN
F 1 "GNDA" H 6550 4050 50  0000 C CNN
F 2 "" H 6550 4200 50  0001 C CNN
F 3 "" H 6550 4200 50  0001 C CNN
	1    6550 4200
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR03
U 1 1 59FFC346
P 6250 4600
F 0 "#PWR03" H 6250 4350 50  0001 C CNN
F 1 "GNDA" H 6250 4450 50  0000 C CNN
F 2 "" H 6250 4600 50  0001 C CNN
F 3 "" H 6250 4600 50  0001 C CNN
	1    6250 4600
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR04
U 1 1 59FFC406
P 3750 4200
F 0 "#PWR04" H 3750 3950 50  0001 C CNN
F 1 "GNDA" H 3750 4050 50  0000 C CNN
F 2 "" H 3750 4200 50  0001 C CNN
F 3 "" H 3750 4200 50  0001 C CNN
	1    3750 4200
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J1
U 1 1 59FFC4D5
P 2800 3750
F 0 "J1" H 2800 3850 50  0000 C CNN
F 1 "Power IN" H 2800 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 2800 3750 50  0001 C CNN
F 3 "" H 2800 3750 50  0001 C CNN
	1    2800 3750
	-1   0    0    1   
$EndComp
$Comp
L GNDA #PWR05
U 1 1 59FFC542
P 3050 3800
F 0 "#PWR05" H 3050 3550 50  0001 C CNN
F 1 "GNDA" H 3050 3650 50  0000 C CNN
F 2 "" H 3050 3800 50  0001 C CNN
F 3 "" H 3050 3800 50  0001 C CNN
	1    3050 3800
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J3
U 1 1 59FFC5CF
P 8250 3950
F 0 "J3" H 8250 4050 50  0000 C CNN
F 1 "Power OUT" H 8250 3750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 8250 3950 50  0001 C CNN
F 3 "" H 8250 3950 50  0001 C CNN
	1    8250 3950
	1    0    0    1   
$EndComp
$Comp
L GNDA #PWR06
U 1 1 59FFC652
P 8000 4000
F 0 "#PWR06" H 8000 3750 50  0001 C CNN
F 1 "GNDA" H 8000 3850 50  0000 C CNN
F 2 "" H 8000 4000 50  0001 C CNN
F 3 "" H 8000 4000 50  0001 C CNN
	1    8000 4000
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky_Small D1
U 1 1 59FFC76C
P 5650 4050
F 0 "D1" H 5600 4130 50  0000 L CNN
F 1 "SSC54" H 5370 3970 50  0000 L CNN
F 2 "Diodes_SMD:D_SMC" V 5650 4050 50  0001 C CNN
F 3 "" V 5650 4050 50  0001 C CNN
	1    5650 4050
	0    1    1    0   
$EndComp
$Comp
L GNDA #PWR07
U 1 1 59FFC8D5
P 5650 4200
F 0 "#PWR07" H 5650 3950 50  0001 C CNN
F 1 "GNDA" H 5650 4050 50  0000 C CNN
F 2 "" H 5650 4200 50  0001 C CNN
F 3 "" H 5650 4200 50  0001 C CNN
	1    5650 4200
	1    0    0    -1  
$EndComp
Text Notes 6750 4600 0    60   ~ 0
R1 = (Vout/1.23 - 1.0)*R2\nR1 = 5k17
Text Notes 5700 3600 0    60   ~ 0
L1=100u Iout>2\nL1=150u 1.3 < Iout < 2\nL1=220u 0.8 < Iout < 1.3
Text Notes 4650 3200 0    60   ~ 0
Iout(max) = 3A
$Comp
L R R5
U 1 1 5A011A1E
P 4350 3850
F 0 "R5" V 4430 3850 50  0000 C CNN
F 1 "100k" V 4350 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4280 3850 50  0001 C CNN
F 3 "" H 4350 3850 50  0001 C CNN
	1    4350 3850
	1    0    0    -1  
$EndComp
$Comp
L BSS138 Q1
U 1 1 5A0253B8
P 4250 4500
F 0 "Q1" H 4450 4575 50  0000 L CNN
F 1 "IRLML0030" H 4450 4500 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4450 4425 50  0001 L CIN
F 3 "" H 4250 4500 50  0001 L CNN
	1    4250 4500
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR08
U 1 1 5A0254E4
P 4350 4700
F 0 "#PWR08" H 4350 4450 50  0001 C CNN
F 1 "GNDA" H 4350 4550 50  0000 C CNN
F 2 "" H 4350 4700 50  0001 C CNN
F 3 "" H 4350 4700 50  0001 C CNN
	1    4350 4700
	1    0    0    -1  
$EndComp
$Comp
L CP C3
U 1 1 5A0259E6
P 6850 4050
F 0 "C3" H 6875 4150 50  0000 L CNN
F 1 "100u(t)" H 6875 3950 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-D_EIA-7343-31_Reflow" H 6888 3900 50  0001 C CNN
F 3 "" H 6850 4050 50  0001 C CNN
	1    6850 4050
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR09
U 1 1 5A025A22
P 6850 4200
F 0 "#PWR09" H 6850 3950 50  0001 C CNN
F 1 "GNDA" H 6850 4050 50  0000 C CNN
F 2 "" H 6850 4200 50  0001 C CNN
F 3 "" H 6850 4200 50  0001 C CNN
	1    6850 4200
	1    0    0    -1  
$EndComp
$Comp
L L_Core_Ferrite L2
U 1 1 5A025DE9
P 7200 3850
F 0 "L2" V 7150 3850 50  0000 C CNN
F 1 "20u" V 7310 3850 50  0000 C CNN
F 2 "Inductors_THT:L_Toroid_Vertical_L16.8mm_W9.2mm_P7.10mm_Vishay_TJ3" H 7200 3850 50  0001 C CNN
F 3 "" H 7200 3850 50  0001 C CNN
	1    7200 3850
	0    -1   -1   0   
$EndComp
$Comp
L CP C4
U 1 1 5A025E5B
P 7450 4050
F 0 "C4" H 7475 4150 50  0000 L CNN
F 1 "100u" H 7475 3950 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D6.3mm_P2.50mm" H 7488 3900 50  0001 C CNN
F 3 "" H 7450 4050 50  0001 C CNN
	1    7450 4050
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR010
U 1 1 5A025EC7
P 7450 4200
F 0 "#PWR010" H 7450 3950 50  0001 C CNN
F 1 "GNDA" H 7450 4050 50  0000 C CNN
F 2 "" H 7450 4200 50  0001 C CNN
F 3 "" H 7450 4200 50  0001 C CNN
	1    7450 4200
	1    0    0    -1  
$EndComp
$Comp
L INA169 U1
U 1 1 5A026B49
P 3950 2600
F 0 "U1" H 3800 2800 40  0000 C CNN
F 1 "INA169" H 3850 2400 40  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 3950 2600 60  0001 C CNN
F 3 "" H 3950 2600 60  0000 C CNN
	1    3950 2600
	1    0    0    -1  
$EndComp
$Comp
L MCP3428 U3
U 1 1 5A026CC9
P 6150 1600
F 0 "U3" H 6000 2050 50  0000 R CNN
F 1 "MCP3428" H 6250 2050 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 6150 1600 50  0001 C CNN
F 3 "" H 6150 1600 50  0001 C CNN
	1    6150 1600
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A03AFF2
P 3400 3650
F 0 "R3" V 3480 3650 50  0000 C CNN
F 1 "0R1" V 3400 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_2512" V 3330 3650 50  0001 C CNN
F 3 "" H 3400 3650 50  0001 C CNN
	1    3400 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 3850 5750 3850
Wire Wire Line
	6250 3850 6250 3900
Wire Wire Line
	6550 3850 6550 3900
Connection ~ 6550 3850
Wire Wire Line
	6250 4200 6250 4300
Wire Wire Line
	6250 4250 6100 4250
Wire Wire Line
	6100 4250 6100 3650
Wire Wire Line
	6100 3650 5550 3650
Connection ~ 6250 4250
Wire Wire Line
	3750 3650 3750 3700
Wire Wire Line
	3550 3650 4550 3650
Wire Wire Line
	3750 4200 3750 4000
Wire Wire Line
	5050 4200 5050 4050
Connection ~ 3750 3650
Wire Wire Line
	3000 3750 3050 3750
Wire Wire Line
	3050 3750 3050 3800
Wire Wire Line
	8000 4000 8000 3950
Wire Wire Line
	8000 3950 8050 3950
Wire Wire Line
	5650 3950 5650 3850
Connection ~ 5650 3850
Wire Wire Line
	5650 4200 5650 4150
Connection ~ 6250 3850
Wire Wire Line
	4350 3650 4350 3700
Connection ~ 4350 3650
Wire Wire Line
	4350 4000 4350 4300
Wire Wire Line
	4350 4050 4500 4050
Wire Wire Line
	4500 4050 4500 3850
Wire Wire Line
	4500 3850 4550 3850
Connection ~ 4350 4050
Wire Wire Line
	6850 3850 6850 3900
Connection ~ 6850 3850
Wire Wire Line
	6050 3850 7050 3850
Wire Wire Line
	7450 3850 7450 3900
Connection ~ 7450 3850
Wire Wire Line
	3000 3650 3250 3650
Wire Wire Line
	2950 2550 3650 2550
Wire Wire Line
	3200 2300 3200 3650
Connection ~ 3200 3650
Wire Wire Line
	3600 3650 3600 2650
Wire Wire Line
	3600 2650 3650 2650
Connection ~ 3600 3650
$Comp
L GNDA #PWR011
U 1 1 5A03B368
P 4000 2950
F 0 "#PWR011" H 4000 2700 50  0001 C CNN
F 1 "GNDA" H 4000 2800 50  0000 C CNN
F 2 "" H 4000 2950 50  0001 C CNN
F 3 "" H 4000 2950 50  0001 C CNN
	1    4000 2950
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5A03B3EE
P 4350 2800
F 0 "R4" V 4430 2800 50  0000 C CNN
F 1 "10k" V 4350 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4280 2800 50  0001 C CNN
F 3 "" H 4350 2800 50  0001 C CNN
	1    4350 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2600 4500 2600
Wire Wire Line
	4350 2600 4350 2650
$Comp
L GNDA #PWR012
U 1 1 5A03B53A
P 4350 2950
F 0 "#PWR012" H 4350 2700 50  0001 C CNN
F 1 "GNDA" H 4350 2800 50  0000 C CNN
F 2 "" H 4350 2950 50  0001 C CNN
F 3 "" H 4350 2950 50  0001 C CNN
	1    4350 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2950 4000 2850
Wire Wire Line
	4000 2350 4000 2300
Wire Wire Line
	4000 2300 3200 2300
Connection ~ 3200 2550
$Comp
L INA169 U4
U 1 1 5A03B8E0
P 8300 2600
F 0 "U4" H 8150 2800 40  0000 C CNN
F 1 "INA169" H 8200 2400 40  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 8300 2600 60  0001 C CNN
F 3 "" H 8300 2600 60  0000 C CNN
	1    8300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2550 8000 2550
Wire Wire Line
	7550 3850 7550 2300
Wire Wire Line
	7900 3850 8050 3850
Wire Wire Line
	7950 3850 7950 2650
Wire Wire Line
	7950 2650 8000 2650
$Comp
L GNDA #PWR013
U 1 1 5A03B8EA
P 8350 2950
F 0 "#PWR013" H 8350 2700 50  0001 C CNN
F 1 "GNDA" H 8350 2800 50  0000 C CNN
F 2 "" H 8350 2950 50  0001 C CNN
F 3 "" H 8350 2950 50  0001 C CNN
	1    8350 2950
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 5A03B8F0
P 8700 2800
F 0 "R15" V 8780 2800 50  0000 C CNN
F 1 "10k" V 8700 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8630 2800 50  0001 C CNN
F 3 "" H 8700 2800 50  0001 C CNN
	1    8700 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 2600 8850 2600
Wire Wire Line
	8700 2600 8700 2650
$Comp
L GNDA #PWR014
U 1 1 5A03B8F8
P 8700 2950
F 0 "#PWR014" H 8700 2700 50  0001 C CNN
F 1 "GNDA" H 8700 2800 50  0000 C CNN
F 2 "" H 8700 2950 50  0001 C CNN
F 3 "" H 8700 2950 50  0001 C CNN
	1    8700 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 2950 8350 2850
Wire Wire Line
	8350 2350 8350 2300
Wire Wire Line
	8350 2300 7550 2300
Connection ~ 7550 2550
$Comp
L R R14
U 1 1 5A03B9E2
P 7750 3850
F 0 "R14" V 7830 3850 50  0000 C CNN
F 1 "0R1" V 7750 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_2512" V 7680 3850 50  0001 C CNN
F 3 "" H 7750 3850 50  0001 C CNN
	1    7750 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 3850 7600 3850
Connection ~ 7950 3850
Connection ~ 7550 3850
$Comp
L CP C5
U 1 1 5A03C076
P 7500 1500
F 0 "C5" H 7525 1600 50  0000 L CNN
F 1 "10u" H 7525 1400 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D6.3mm_P2.50mm" H 7538 1350 50  0001 C CNN
F 3 "" H 7500 1500 50  0001 C CNN
	1    7500 1500
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5A03C0C2
P 7800 1500
F 0 "C6" H 7825 1600 50  0000 L CNN
F 1 "100n" H 7825 1400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7838 1350 50  0001 C CNN
F 3 "" H 7800 1500 50  0001 C CNN
	1    7800 1500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR015
U 1 1 5A03C42C
P 7500 1350
F 0 "#PWR015" H 7500 1200 50  0001 C CNN
F 1 "+5V" H 7500 1490 50  0000 C CNN
F 2 "" H 7500 1350 50  0001 C CNN
F 3 "" H 7500 1350 50  0001 C CNN
	1    7500 1350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 5A03C4F6
P 7800 1350
F 0 "#PWR016" H 7800 1200 50  0001 C CNN
F 1 "+5V" H 7800 1490 50  0000 C CNN
F 2 "" H 7800 1350 50  0001 C CNN
F 3 "" H 7800 1350 50  0001 C CNN
	1    7800 1350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR017
U 1 1 5A03C65A
P 6150 1100
F 0 "#PWR017" H 6150 950 50  0001 C CNN
F 1 "+5V" H 6150 1240 50  0000 C CNN
F 2 "" H 6150 1100 50  0001 C CNN
F 3 "" H 6150 1100 50  0001 C CNN
	1    6150 1100
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR018
U 1 1 5A03CBEF
P 7800 1650
F 0 "#PWR018" H 7800 1400 50  0001 C CNN
F 1 "GNDA" H 7800 1500 50  0000 C CNN
F 2 "" H 7800 1650 50  0001 C CNN
F 3 "" H 7800 1650 50  0001 C CNN
	1    7800 1650
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR019
U 1 1 5A03CC3F
P 7500 1650
F 0 "#PWR019" H 7500 1400 50  0001 C CNN
F 1 "GNDA" H 7500 1500 50  0000 C CNN
F 2 "" H 7500 1650 50  0001 C CNN
F 3 "" H 7500 1650 50  0001 C CNN
	1    7500 1650
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR020
U 1 1 5A03CC8F
P 6150 2200
F 0 "#PWR020" H 6150 1950 50  0001 C CNN
F 1 "GNDA" H 6150 2050 50  0000 C CNN
F 2 "" H 6150 2200 50  0001 C CNN
F 3 "" H 6150 2200 50  0001 C CNN
	1    6150 2200
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR021
U 1 1 5A03CD97
P 5750 1400
F 0 "#PWR021" H 5750 1150 50  0001 C CNN
F 1 "GNDA" H 5750 1250 50  0000 C CNN
F 2 "" H 5750 1400 50  0001 C CNN
F 3 "" H 5750 1400 50  0001 C CNN
	1    5750 1400
	0    1    1    0   
$EndComp
$Comp
L GNDA #PWR022
U 1 1 5A03CE34
P 5750 1600
F 0 "#PWR022" H 5750 1350 50  0001 C CNN
F 1 "GNDA" H 5750 1450 50  0000 C CNN
F 2 "" H 5750 1600 50  0001 C CNN
F 3 "" H 5750 1600 50  0001 C CNN
	1    5750 1600
	0    1    1    0   
$EndComp
$Comp
L GNDA #PWR023
U 1 1 5A03CE84
P 5750 1800
F 0 "#PWR023" H 5750 1550 50  0001 C CNN
F 1 "GNDA" H 5750 1650 50  0000 C CNN
F 2 "" H 5750 1800 50  0001 C CNN
F 3 "" H 5750 1800 50  0001 C CNN
	1    5750 1800
	0    1    1    0   
$EndComp
$Comp
L GNDA #PWR024
U 1 1 5A03CED4
P 5750 2000
F 0 "#PWR024" H 5750 1750 50  0001 C CNN
F 1 "GNDA" H 5750 1850 50  0000 C CNN
F 2 "" H 5750 2000 50  0001 C CNN
F 3 "" H 5750 2000 50  0001 C CNN
	1    5750 2000
	0    1    1    0   
$EndComp
Text GLabel 4500 2600 2    60   Input ~ 0
IN_Current
Connection ~ 4350 2600
Text GLabel 8850 2600 2    60   Input ~ 0
OUT_Current
Connection ~ 8700 2600
Text GLabel 5450 1500 0    60   Input ~ 0
IN_Current
Text GLabel 5450 1900 0    60   Input ~ 0
OUT_Current
Wire Wire Line
	5450 1900 5750 1900
Wire Wire Line
	5450 1500 5750 1500
Text GLabel 3950 4500 0    60   Input ~ 0
PowerEnable
Wire Wire Line
	3950 4500 4050 4500
$Comp
L R R1
U 1 1 5A03E251
P 2950 2750
F 0 "R1" V 3030 2750 50  0000 C CNN
F 1 "10k" V 2950 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2880 2750 50  0001 C CNN
F 3 "" H 2950 2750 50  0001 C CNN
	1    2950 2750
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A03E2BD
P 2950 3150
F 0 "R2" V 3030 3150 50  0000 C CNN
F 1 "10k" V 2950 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2880 3150 50  0001 C CNN
F 3 "" H 2950 3150 50  0001 C CNN
	1    2950 3150
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR025
U 1 1 5A03E32E
P 2950 3300
F 0 "#PWR025" H 2950 3050 50  0001 C CNN
F 1 "GNDA" H 2950 3150 50  0000 C CNN
F 2 "" H 2950 3300 50  0001 C CNN
F 3 "" H 2950 3300 50  0001 C CNN
	1    2950 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 2900 2950 3000
Wire Wire Line
	2950 2600 2950 2550
Text GLabel 2800 2950 0    60   Input ~ 0
IN_Voltage
Wire Wire Line
	2800 2950 2950 2950
Connection ~ 2950 2950
$Comp
L R R12
U 1 1 5A03E842
P 7350 2750
F 0 "R12" V 7430 2750 50  0000 C CNN
F 1 "10k" V 7350 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7280 2750 50  0001 C CNN
F 3 "" H 7350 2750 50  0001 C CNN
	1    7350 2750
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5A03E848
P 7350 3150
F 0 "R13" V 7430 3150 50  0000 C CNN
F 1 "10k" V 7350 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7280 3150 50  0001 C CNN
F 3 "" H 7350 3150 50  0001 C CNN
	1    7350 3150
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR026
U 1 1 5A03E84E
P 7350 3300
F 0 "#PWR026" H 7350 3050 50  0001 C CNN
F 1 "GNDA" H 7350 3150 50  0000 C CNN
F 2 "" H 7350 3300 50  0001 C CNN
F 3 "" H 7350 3300 50  0001 C CNN
	1    7350 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2900 7350 3000
Text GLabel 7200 2950 0    60   Input ~ 0
OUT_Voltage
Wire Wire Line
	7200 2950 7350 2950
Connection ~ 7350 2950
Wire Wire Line
	7350 2600 7350 2550
Text GLabel 5450 1700 0    60   Input ~ 0
OUT_Voltage
Text GLabel 5450 1300 0    60   Input ~ 0
IN_Voltage
Wire Wire Line
	5450 1300 5750 1300
Wire Wire Line
	5450 1700 5750 1700
Text GLabel 6700 1400 2    60   Input ~ 0
SCL
Text GLabel 6700 1500 2    60   Input ~ 0
SDA
Wire Wire Line
	6550 1400 6700 1400
Wire Wire Line
	6550 1500 6700 1500
$Comp
L R R8
U 1 1 5A03F241
P 7050 1500
F 0 "R8" V 7130 1500 50  0000 C CNN
F 1 "0" V 7050 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6980 1500 50  0001 C CNN
F 3 "" H 7050 1500 50  0001 C CNN
	1    7050 1500
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5A03F247
P 7050 2000
F 0 "R9" V 7130 2000 50  0000 C CNN
F 1 "0" V 7050 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6980 2000 50  0001 C CNN
F 3 "" H 7050 2000 50  0001 C CNN
	1    7050 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 1650 7050 1850
Wire Wire Line
	6550 1700 7050 1700
Connection ~ 7050 1700
$Comp
L GNDA #PWR027
U 1 1 5A03F4A2
P 7050 2150
F 0 "#PWR027" H 7050 1900 50  0001 C CNN
F 1 "GNDA" H 7050 2000 50  0000 C CNN
F 2 "" H 7050 2150 50  0001 C CNN
F 3 "" H 7050 2150 50  0001 C CNN
	1    7050 2150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR028
U 1 1 5A03F504
P 7050 1350
F 0 "#PWR028" H 7050 1200 50  0001 C CNN
F 1 "+5V" H 7050 1490 50  0000 C CNN
F 2 "" H 7050 1350 50  0001 C CNN
F 3 "" H 7050 1350 50  0001 C CNN
	1    7050 1350
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5A03F5CF
P 7250 1500
F 0 "R10" V 7330 1500 50  0000 C CNN
F 1 "0" V 7250 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7180 1500 50  0001 C CNN
F 3 "" H 7250 1500 50  0001 C CNN
	1    7250 1500
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5A03F5D5
P 7250 2000
F 0 "R11" V 7330 2000 50  0000 C CNN
F 1 "0" V 7250 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7180 2000 50  0001 C CNN
F 3 "" H 7250 2000 50  0001 C CNN
	1    7250 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1650 7250 1850
Wire Wire Line
	6550 1800 7250 1800
Connection ~ 7250 1800
$Comp
L GNDA #PWR029
U 1 1 5A03F5DF
P 7250 2150
F 0 "#PWR029" H 7250 1900 50  0001 C CNN
F 1 "GNDA" H 7250 2000 50  0000 C CNN
F 2 "" H 7250 2150 50  0001 C CNN
F 3 "" H 7250 2150 50  0001 C CNN
	1    7250 2150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR030
U 1 1 5A03F5E5
P 7250 1350
F 0 "#PWR030" H 7250 1200 50  0001 C CNN
F 1 "+5V" H 7250 1490 50  0000 C CNN
F 2 "" H 7250 1350 50  0001 C CNN
F 3 "" H 7250 1350 50  0001 C CNN
	1    7250 1350
	1    0    0    -1  
$EndComp
$Comp
L Conn_02x03_Odd_Even J2
U 1 1 5A03F80D
P 3750 1550
F 0 "J2" H 3800 1750 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 3800 1350 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x03_Pitch2.54mm" H 3750 1550 50  0001 C CNN
F 3 "" H 3750 1550 50  0001 C CNN
	1    3750 1550
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR031
U 1 1 5A03FA4A
P 3550 1450
F 0 "#PWR031" H 3550 1200 50  0001 C CNN
F 1 "GNDA" H 3550 1300 50  0000 C CNN
F 2 "" H 3550 1450 50  0001 C CNN
F 3 "" H 3550 1450 50  0001 C CNN
	1    3550 1450
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR032
U 1 1 5A03FAB5
P 4050 1650
F 0 "#PWR032" H 4050 1500 50  0001 C CNN
F 1 "+5V" H 4050 1790 50  0000 C CNN
F 2 "" H 4050 1650 50  0001 C CNN
F 3 "" H 4050 1650 50  0001 C CNN
	1    4050 1650
	0    1    1    0   
$EndComp
$Comp
L GNDA #PWR033
U 1 1 5A03FDB0
P 4050 1450
F 0 "#PWR033" H 4050 1200 50  0001 C CNN
F 1 "GNDA" H 4050 1300 50  0000 C CNN
F 2 "" H 4050 1450 50  0001 C CNN
F 3 "" H 4050 1450 50  0001 C CNN
	1    4050 1450
	0    -1   -1   0   
$EndComp
Text GLabel 3350 1550 0    60   Input ~ 0
SCL
Text GLabel 4250 1550 2    60   Input ~ 0
SDA
Text GLabel 3350 1650 0    60   Input ~ 0
PowerEnable
Wire Wire Line
	3350 1550 3550 1550
Wire Wire Line
	3350 1650 3550 1650
Wire Wire Line
	4050 1550 4250 1550
Text Notes 5850 850  0    60   ~ 0
Uref=2024mV
$EndSCHEMATC
