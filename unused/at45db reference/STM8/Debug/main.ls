   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Parser V4.9.2 - 29 Jun 2010
   3                     ; Generator V4.3.5 - 02 Jul 2010
2878                     ; 52 void delay_ms(u16 ms)
2878                     ; 53 {
2880                     	switch	.text
2881  0000               _delay_ms:
2883  0000 89            	pushw	x
2884  0001 88            	push	a
2885       00000001      OFST:	set	1
2888  0002 201b          	jra	L5302
2889  0004               L3302:
2890                     ; 57 				for(i=0;i<250;i++)
2892  0004 0f01          	clr	(OFST+0,sp)
2893  0006               L1402:
2896  0006 0c01          	inc	(OFST+0,sp)
2899  0008 7b01          	ld	a,(OFST+0,sp)
2900  000a a1fa          	cp	a,#250
2901  000c 25f8          	jrult	L1402
2902                     ; 59 				for(i=0;i<75;i++)
2904  000e 0f01          	clr	(OFST+0,sp)
2905  0010               L7402:
2908  0010 0c01          	inc	(OFST+0,sp)
2911  0012 7b01          	ld	a,(OFST+0,sp)
2912  0014 a14b          	cp	a,#75
2913  0016 25f8          	jrult	L7402
2914                     ; 61 				ms--;
2916  0018 1e02          	ldw	x,(OFST+1,sp)
2917  001a 1d0001        	subw	x,#1
2918  001d 1f02          	ldw	(OFST+1,sp),x
2919  001f               L5302:
2920                     ; 55 			while(ms!=0)
2922  001f 1e02          	ldw	x,(OFST+1,sp)
2923  0021 26e1          	jrne	L3302
2924                     ; 63 }
2927  0023 5b03          	addw	sp,#3
2928  0025 81            	ret
2971                     ; 65 void delay_us(u16 us)
2971                     ; 66 {
2972                     	switch	.text
2973  0026               _delay_us:
2975  0026 89            	pushw	x
2976  0027 88            	push	a
2977       00000001      OFST:	set	1
2980  0028 201b          	jra	L1012
2981  002a               L7702:
2982                     ; 70 				for(i=0;i<25;i++)
2984  002a 0f01          	clr	(OFST+0,sp)
2985  002c               L5012:
2988  002c 0c01          	inc	(OFST+0,sp)
2991  002e 7b01          	ld	a,(OFST+0,sp)
2992  0030 a119          	cp	a,#25
2993  0032 25f8          	jrult	L5012
2994                     ; 72 				for(i=0;i<7;i++)
2996  0034 0f01          	clr	(OFST+0,sp)
2997  0036               L3112:
3000  0036 0c01          	inc	(OFST+0,sp)
3003  0038 7b01          	ld	a,(OFST+0,sp)
3004  003a a107          	cp	a,#7
3005  003c 25f8          	jrult	L3112
3006                     ; 74 				us--;
3008  003e 1e02          	ldw	x,(OFST+1,sp)
3009  0040 1d0001        	subw	x,#1
3010  0043 1f02          	ldw	(OFST+1,sp),x
3011  0045               L1012:
3012                     ; 68 			while(us!=0)
3014  0045 1e02          	ldw	x,(OFST+1,sp)
3015  0047 26e1          	jrne	L7702
3016                     ; 76 }
3019  0049 5b03          	addw	sp,#3
3020  004b 81            	ret
3062                     ; 17 void SPI_Init(void)
3062                     ; 18 {
3063                     	switch	.text
3064  004c               _SPI_Init:
3068                     ; 19 	SPI_CR1|=0x38;   //波特率
3070  004c c65200        	ld	a,_SPI_CR1
3071  004f aa38          	or	a,#56
3072  0051 c75200        	ld	_SPI_CR1,a
3073                     ; 24 	SPI_CR2|=0x03;   //配置NSS脚为1
3075  0054 c65201        	ld	a,_SPI_CR2
3076  0057 aa03          	or	a,#3
3077  0059 c75201        	ld	_SPI_CR2,a
3078                     ; 25 	SPI_CR1|=0x04;   //配置为主设备
3080  005c 72145200      	bset	_SPI_CR1,#2
3081                     ; 26 	SPI_CR1|=0x40;   //开启SPI
3083  0060 721c5200      	bset	_SPI_CR1,#6
3084                     ; 27 }
3087  0064 81            	ret
3123                     ; 29 void SPI_sendchar(u8 data)
3123                     ; 30 {	
3124                     	switch	.text
3125  0065               _SPI_sendchar:
3129                     ; 31 	SPI_DR=data;
3131  0065 c75204        	ld	_SPI_DR,a
3133  0068               L1612:
3134                     ; 32 	while(!(SPI_SR & 0x02));
3136  0068 c65203        	ld	a,_SPI_SR
3137  006b a502          	bcp	a,#2
3138  006d 27f9          	jreq	L1612
3139                     ; 33 }
3142  006f 81            	ret
3178                     ; 35 u8 SPI_rechar(void)
3178                     ; 36 {	
3179                     	switch	.text
3180  0070               _SPI_rechar:
3182  0070 88            	push	a
3183       00000001      OFST:	set	1
3186                     ; 38 	data=SPI_DR;
3188  0071 c65204        	ld	a,_SPI_DR
3189  0074 6b01          	ld	(OFST+0,sp),a
3191  0076               L7022:
3192                     ; 39 	while(!(SPI_SR & 0x01));
3194  0076 c65203        	ld	a,_SPI_SR
3195  0079 a501          	bcp	a,#1
3196  007b 27f9          	jreq	L7022
3197                     ; 40 	return data;
3199  007d 7b01          	ld	a,(OFST+0,sp)
3202  007f 5b01          	addw	sp,#1
3203  0081 81            	ret
3247                     ; 24 void AT45DBXX_Init(void)
3247                     ; 25 {
3248                     	switch	.text
3249  0082               _AT45DBXX_Init:
3253                     ; 26 	SPI_Init();
3255  0082 adc8          	call	_SPI_Init
3257                     ; 27 	CS_INIT;
3259  0084 7218500c      	bset	_PC_DDR,#4
3262  0088 7218500d      	bset	_PC_CR1,#4
3263                     ; 28 	CS_SET;
3266  008c 7218500a      	bset	_PC_ODR,#4
3267                     ; 29 }
3271  0090 81            	ret
3317                     ; 31 void write_buffer(u16 BufferOffset,u8 Data)
3317                     ; 32 {			
3318                     	switch	.text
3319  0091               _write_buffer:
3321  0091 89            	pushw	x
3322       00000000      OFST:	set	0
3325                     ; 33 	CS_CLK;
3327  0092 7219500a      	bres	_PC_ODR,#4
3328                     ; 34 	delay_us(10);
3331  0096 ae000a        	ldw	x,#10
3332  0099 ad8b          	call	_delay_us
3334                     ; 35 	SPI_sendchar(0x84);			
3336  009b a684          	ld	a,#132
3337  009d adc6          	call	_SPI_sendchar
3339                     ; 36 	SPI_sendchar(0xff);
3341  009f a6ff          	ld	a,#255
3342  00a1 adc2          	call	_SPI_sendchar
3344                     ; 37 	SPI_sendchar((u8)BufferOffset>>8);
3346  00a3 4f            	clr	a
3347  00a4 adbf          	call	_SPI_sendchar
3349                     ; 38 	SPI_sendchar((u8)BufferOffset);		
3351  00a6 7b02          	ld	a,(OFST+2,sp)
3352  00a8 adbb          	call	_SPI_sendchar
3354                     ; 39 	SPI_sendchar(Data);
3356  00aa 7b05          	ld	a,(OFST+5,sp)
3357  00ac adb7          	call	_SPI_sendchar
3359                     ; 40 	delay_us(10);
3361  00ae ae000a        	ldw	x,#10
3362  00b1 cd0026        	call	_delay_us
3364                     ; 41 	CS_SET;
3366  00b4 7218500a      	bset	_PC_ODR,#4
3367                     ; 42 }
3371  00b8 85            	popw	x
3372  00b9 81            	ret
3419                     ; 44 u8 read_buffer(u16 BufferOffset)
3419                     ; 45 {		
3420                     	switch	.text
3421  00ba               _read_buffer:
3423  00ba 89            	pushw	x
3424  00bb 88            	push	a
3425       00000001      OFST:	set	1
3428                     ; 47 	CS_CLK;
3430  00bc 7219500a      	bres	_PC_ODR,#4
3431                     ; 48 	delay_us(10);
3434  00c0 ae000a        	ldw	x,#10
3435  00c3 cd0026        	call	_delay_us
3437                     ; 49  	SPI_sendchar(0xd4);
3439  00c6 a6d4          	ld	a,#212
3440  00c8 ad9b          	call	_SPI_sendchar
3442                     ; 50 	SPI_sendchar(0xff);
3444  00ca a6ff          	ld	a,#255
3445  00cc ad97          	call	_SPI_sendchar
3447                     ; 51 	SPI_sendchar((u8)BufferOffset>>8);
3449  00ce 4f            	clr	a
3450  00cf ad94          	call	_SPI_sendchar
3452                     ; 52 	SPI_sendchar((u8)BufferOffset);
3454  00d1 7b03          	ld	a,(OFST+2,sp)
3455  00d3 ad90          	call	_SPI_sendchar
3457                     ; 53 	SPI_sendchar(0xff);
3459  00d5 a6ff          	ld	a,#255
3460  00d7 ad8c          	call	_SPI_sendchar
3462                     ; 54 	SPI_sendchar(0xff);
3464  00d9 a6ff          	ld	a,#255
3465  00db ad88          	call	_SPI_sendchar
3467                     ; 55 	temp=SPI_rechar();
3469  00dd ad91          	call	_SPI_rechar
3471  00df 6b01          	ld	(OFST+0,sp),a
3472                     ; 56 	delay_us(10);
3474  00e1 ae000a        	ldw	x,#10
3475  00e4 cd0026        	call	_delay_us
3477                     ; 57 	CS_SET;
3479  00e7 7218500a      	bset	_PC_ODR,#4
3480                     ; 58 	return temp;		
3483  00eb 7b01          	ld	a,(OFST+0,sp)
3486  00ed 5b03          	addw	sp,#3
3487  00ef 81            	ret
3546                     ; 21 void st7920LcdInit(void)
3546                     ; 22 {
3547                     	switch	.text
3548  00f0               _st7920LcdInit:
3550  00f0 88            	push	a
3551       00000001      OFST:	set	1
3554                     ; 24 	SPI_Init();
3556  00f1 cd004c        	call	_SPI_Init
3558                     ; 25 	delay_ms(100);
3560  00f4 ae0064        	ldw	x,#100
3561  00f7 cd0000        	call	_delay_ms
3563                     ; 26 	PE_DDR|=0x20;
3565  00fa 721a5016      	bset	_PE_DDR,#5
3566                     ; 27 	PE_CR1|=0x20;
3568  00fe 721a5017      	bset	_PE_CR1,#5
3569                     ; 28 	PE_CR2|=0x20;
3571  0102 721a5018      	bset	_PE_CR2,#5
3572                     ; 29 	sendCodeST7920(0x0c);//整体显示
3574  0106 a60c          	ld	a,#12
3575  0108 ad1c          	call	_sendCodeST7920
3577                     ; 30 	sendCodeST7920(0x01);//清屏
3579  010a a601          	ld	a,#1
3580  010c ad18          	call	_sendCodeST7920
3582                     ; 31 	sendCodeST7920(0x02);
3584  010e a602          	ld	a,#2
3585  0110 ad14          	call	_sendCodeST7920
3587                     ; 32 	for(i=0;i<64;i++)
3589  0112 0f01          	clr	(OFST+0,sp)
3590  0114               L1232:
3591                     ; 33 		lcd_buffer[i]=' ';
3593  0114 7b01          	ld	a,(OFST+0,sp)
3594  0116 5f            	clrw	x
3595  0117 97            	ld	xl,a
3596  0118 a620          	ld	a,#32
3597  011a e700          	ld	(_lcd_buffer,x),a
3598                     ; 32 	for(i=0;i<64;i++)
3600  011c 0c01          	inc	(OFST+0,sp)
3603  011e 7b01          	ld	a,(OFST+0,sp)
3604  0120 a140          	cp	a,#64
3605  0122 25f0          	jrult	L1232
3606                     ; 35 }
3609  0124 84            	pop	a
3610  0125 81            	ret
3647                     ; 37 void sendCodeST7920(u8 Lcd_cmd)
3647                     ; 38 {
3648                     	switch	.text
3649  0126               _sendCodeST7920:
3651  0126 88            	push	a
3652       00000000      OFST:	set	0
3655                     ; 39 	E_CLK
3657  0127 721b5014      	bres	_PE_ODR,#5
3658                     ; 40 	LCD_DELAY()
3661  012b 9d            nop
3666  012c 9d            nop
3671  012d 9d            nop
3676  012e 9d            nop
3681  012f 9d            nop
3683                     ; 41 	E_SET
3685  0130 721a5014      	bset	_PE_ODR,#5
3686                     ; 42 	SPI_sendchar(0xF8);
3688  0134 a6f8          	ld	a,#248
3689  0136 cd0065        	call	_SPI_sendchar
3691                     ; 43 	SPI_sendchar(Lcd_cmd & 0xF0);
3693  0139 7b01          	ld	a,(OFST+1,sp)
3694  013b a4f0          	and	a,#240
3695  013d cd0065        	call	_SPI_sendchar
3697                     ; 44 	SPI_sendchar(Lcd_cmd << 4);
3699  0140 7b01          	ld	a,(OFST+1,sp)
3700  0142 97            	ld	xl,a
3701  0143 a610          	ld	a,#16
3702  0145 42            	mul	x,a
3703  0146 9f            	ld	a,xl
3704  0147 cd0065        	call	_SPI_sendchar
3706                     ; 45 	LCD_DELAY()
3709  014a 9d            nop
3714  014b 9d            nop
3719  014c 9d            nop
3724  014d 9d            nop
3729  014e 9d            nop
3731                     ; 46 	E_CLK
3733  014f 721b5014      	bres	_PE_ODR,#5
3734                     ; 47 	LCD_DELAY()
3737  0153 9d            nop
3742  0154 9d            nop
3747  0155 9d            nop
3752  0156 9d            nop
3757  0157 9d            nop
3759                     ; 48 }
3762  0158 84            	pop	a
3763  0159 81            	ret
3800                     ; 50 void sendDataST7920(u8 Lcd_data)
3800                     ; 51 {
3801                     	switch	.text
3802  015a               _sendDataST7920:
3804  015a 88            	push	a
3805       00000000      OFST:	set	0
3808                     ; 52 	E_CLK
3810  015b 721b5014      	bres	_PE_ODR,#5
3811                     ; 53 	LCD_DELAY()
3814  015f 9d            nop
3819  0160 9d            nop
3824  0161 9d            nop
3829  0162 9d            nop
3834  0163 9d            nop
3836                     ; 54 	E_SET
3838  0164 721a5014      	bset	_PE_ODR,#5
3839                     ; 55 	SPI_sendchar(0xFA);
3841  0168 a6fa          	ld	a,#250
3842  016a cd0065        	call	_SPI_sendchar
3844                     ; 56 	SPI_sendchar(Lcd_data & 0xF0);
3846  016d 7b01          	ld	a,(OFST+1,sp)
3847  016f a4f0          	and	a,#240
3848  0171 cd0065        	call	_SPI_sendchar
3850                     ; 57 	SPI_sendchar(Lcd_data << 4);
3852  0174 7b01          	ld	a,(OFST+1,sp)
3853  0176 97            	ld	xl,a
3854  0177 a610          	ld	a,#16
3855  0179 42            	mul	x,a
3856  017a 9f            	ld	a,xl
3857  017b cd0065        	call	_SPI_sendchar
3859                     ; 58 	LCD_DELAY()
3862  017e 9d            nop
3867  017f 9d            nop
3872  0180 9d            nop
3877  0181 9d            nop
3882  0182 9d            nop
3884                     ; 59 	E_CLK
3886  0183 721b5014      	bres	_PE_ODR,#5
3887                     ; 60 	LCD_DELAY()
3890  0187 9d            nop
3895  0188 9d            nop
3900  0189 9d            nop
3905  018a 9d            nop
3910  018b 9d            nop
3912                     ; 61 }
3915  018c 84            	pop	a
3916  018d 81            	ret
3962                     ; 63 void refreshLCD(const u8 *lcd_stack)
3962                     ; 64 {
3963                     	switch	.text
3964  018e               _refreshLCD:
3966  018e 89            	pushw	x
3967  018f 88            	push	a
3968       00000001      OFST:	set	1
3971                     ; 66 	sendCodeST7920(0x02);	//地址归位
3973  0190 a602          	ld	a,#2
3974  0192 ad92          	call	_sendCodeST7920
3976                     ; 67 	for(addr=0;addr<16;addr++)
3978  0194 0f01          	clr	(OFST+0,sp)
3979  0196               L5042:
3980                     ; 69 		sendDataST7920(*(lcd_stack + addr));
3982  0196 7b02          	ld	a,(OFST+1,sp)
3983  0198 97            	ld	xl,a
3984  0199 7b03          	ld	a,(OFST+2,sp)
3985  019b 1b01          	add	a,(OFST+0,sp)
3986  019d 2401          	jrnc	L43
3987  019f 5c            	incw	x
3988  01a0               L43:
3989  01a0 02            	rlwa	x,a
3990  01a1 f6            	ld	a,(x)
3991  01a2 adb6          	call	_sendDataST7920
3993                     ; 67 	for(addr=0;addr<16;addr++)
3995  01a4 0c01          	inc	(OFST+0,sp)
3998  01a6 7b01          	ld	a,(OFST+0,sp)
3999  01a8 a110          	cp	a,#16
4000  01aa 25ea          	jrult	L5042
4001                     ; 71 	for(addr=32;addr<48;addr++)
4003  01ac a620          	ld	a,#32
4004  01ae 6b01          	ld	(OFST+0,sp),a
4005  01b0               L3142:
4006                     ; 73 		sendDataST7920(*(lcd_stack + addr));
4008  01b0 7b02          	ld	a,(OFST+1,sp)
4009  01b2 97            	ld	xl,a
4010  01b3 7b03          	ld	a,(OFST+2,sp)
4011  01b5 1b01          	add	a,(OFST+0,sp)
4012  01b7 2401          	jrnc	L63
4013  01b9 5c            	incw	x
4014  01ba               L63:
4015  01ba 02            	rlwa	x,a
4016  01bb f6            	ld	a,(x)
4017  01bc ad9c          	call	_sendDataST7920
4019                     ; 71 	for(addr=32;addr<48;addr++)
4021  01be 0c01          	inc	(OFST+0,sp)
4024  01c0 7b01          	ld	a,(OFST+0,sp)
4025  01c2 a130          	cp	a,#48
4026  01c4 25ea          	jrult	L3142
4027                     ; 75 	for(addr=16;addr<32;addr++)
4029  01c6 a610          	ld	a,#16
4030  01c8 6b01          	ld	(OFST+0,sp),a
4031  01ca               L1242:
4032                     ; 77 		sendDataST7920(*(lcd_stack + addr));
4034  01ca 7b02          	ld	a,(OFST+1,sp)
4035  01cc 97            	ld	xl,a
4036  01cd 7b03          	ld	a,(OFST+2,sp)
4037  01cf 1b01          	add	a,(OFST+0,sp)
4038  01d1 2401          	jrnc	L04
4039  01d3 5c            	incw	x
4040  01d4               L04:
4041  01d4 02            	rlwa	x,a
4042  01d5 f6            	ld	a,(x)
4043  01d6 ad82          	call	_sendDataST7920
4045                     ; 75 	for(addr=16;addr<32;addr++)
4047  01d8 0c01          	inc	(OFST+0,sp)
4050  01da 7b01          	ld	a,(OFST+0,sp)
4051  01dc a120          	cp	a,#32
4052  01de 25ea          	jrult	L1242
4053                     ; 80 	for(addr=48;addr<64;addr++)
4055  01e0 a630          	ld	a,#48
4056  01e2 6b01          	ld	(OFST+0,sp),a
4057  01e4               L7242:
4058                     ; 82 		sendDataST7920(*(lcd_stack + addr));
4060  01e4 7b02          	ld	a,(OFST+1,sp)
4061  01e6 97            	ld	xl,a
4062  01e7 7b03          	ld	a,(OFST+2,sp)
4063  01e9 1b01          	add	a,(OFST+0,sp)
4064  01eb 2401          	jrnc	L24
4065  01ed 5c            	incw	x
4066  01ee               L24:
4067  01ee 02            	rlwa	x,a
4068  01ef f6            	ld	a,(x)
4069  01f0 cd015a        	call	_sendDataST7920
4071                     ; 80 	for(addr=48;addr<64;addr++)
4073  01f3 0c01          	inc	(OFST+0,sp)
4076  01f5 7b01          	ld	a,(OFST+0,sp)
4077  01f7 a140          	cp	a,#64
4078  01f9 25e9          	jrult	L7242
4079                     ; 84 }
4082  01fb 5b03          	addw	sp,#3
4083  01fd 81            	ret
4136                     ; 86 void decToAscii(u8* str,u16 dec,u8 width)
4136                     ; 87 {
4137                     	switch	.text
4138  01fe               _decToAscii:
4140  01fe 89            	pushw	x
4141       00000000      OFST:	set	0
4144  01ff ac9e029e      	jpf	L1052
4145  0203               L7742:
4146                     ; 90 		switch(width)
4148  0203 7b07          	ld	a,(OFST+7,sp)
4150                     ; 121 			default: *str = '0';
4151  0205 4a            	dec	a
4152  0206 2603cc028e    	jreq	L5442
4153  020b 4a            	dec	a
4154  020c 2764          	jreq	L3442
4155  020e 4a            	dec	a
4156  020f 2745          	jreq	L1442
4157  0211 4a            	dec	a
4158  0212 2726          	jreq	L7342
4159  0214 4a            	dec	a
4160  0215 2707          	jreq	L5342
4161  0217               L7442:
4164  0217 1e01          	ldw	x,(OFST+1,sp)
4165  0219 a630          	ld	a,#48
4166  021b f7            	ld	(x),a
4167  021c 2077          	jra	L7052
4168  021e               L5342:
4169                     ; 94 				*str = (dec / 10000 + '0');
4171  021e 1e05          	ldw	x,(OFST+5,sp)
4172  0220 90ae2710      	ldw	y,#10000
4173  0224 65            	divw	x,y
4174  0225 1c0030        	addw	x,#48
4175  0228 1601          	ldw	y,(OFST+1,sp)
4176  022a 01            	rrwa	x,a
4177  022b 90f7          	ld	(y),a
4178  022d 02            	rlwa	x,a
4179                     ; 95 				dec %= 10000;
4181  022e 1e05          	ldw	x,(OFST+5,sp)
4182  0230 90ae2710      	ldw	y,#10000
4183  0234 65            	divw	x,y
4184  0235 51            	exgw	x,y
4185  0236 1f05          	ldw	(OFST+5,sp),x
4186                     ; 96 				break;
4188  0238 205b          	jra	L7052
4189  023a               L7342:
4190                     ; 100 				*str = (dec / 1000 + '0');
4192  023a 1e05          	ldw	x,(OFST+5,sp)
4193  023c 90ae03e8      	ldw	y,#1000
4194  0240 65            	divw	x,y
4195  0241 1c0030        	addw	x,#48
4196  0244 1601          	ldw	y,(OFST+1,sp)
4197  0246 01            	rrwa	x,a
4198  0247 90f7          	ld	(y),a
4199  0249 02            	rlwa	x,a
4200                     ; 101 				dec %= 1000;
4202  024a 1e05          	ldw	x,(OFST+5,sp)
4203  024c 90ae03e8      	ldw	y,#1000
4204  0250 65            	divw	x,y
4205  0251 51            	exgw	x,y
4206  0252 1f05          	ldw	(OFST+5,sp),x
4207                     ; 102 				break;
4209  0254 203f          	jra	L7052
4210  0256               L1442:
4211                     ; 106 				*str = (dec/100+'0');
4213  0256 1e05          	ldw	x,(OFST+5,sp)
4214  0258 90ae0064      	ldw	y,#100
4215  025c 65            	divw	x,y
4216  025d 1c0030        	addw	x,#48
4217  0260 1601          	ldw	y,(OFST+1,sp)
4218  0262 01            	rrwa	x,a
4219  0263 90f7          	ld	(y),a
4220  0265 02            	rlwa	x,a
4221                     ; 107 				dec %= 100;
4223  0266 1e05          	ldw	x,(OFST+5,sp)
4224  0268 90ae0064      	ldw	y,#100
4225  026c 65            	divw	x,y
4226  026d 51            	exgw	x,y
4227  026e 1f05          	ldw	(OFST+5,sp),x
4228                     ; 108 				break;
4230  0270 2023          	jra	L7052
4231  0272               L3442:
4232                     ; 112 				*str = (dec/10+'0');
4234  0272 1e05          	ldw	x,(OFST+5,sp)
4235  0274 90ae000a      	ldw	y,#10
4236  0278 65            	divw	x,y
4237  0279 1c0030        	addw	x,#48
4238  027c 1601          	ldw	y,(OFST+1,sp)
4239  027e 01            	rrwa	x,a
4240  027f 90f7          	ld	(y),a
4241  0281 02            	rlwa	x,a
4242                     ; 113 				dec %= 10;
4244  0282 1e05          	ldw	x,(OFST+5,sp)
4245  0284 90ae000a      	ldw	y,#10
4246  0288 65            	divw	x,y
4247  0289 51            	exgw	x,y
4248  028a 1f05          	ldw	(OFST+5,sp),x
4249                     ; 114 				break;
4251  028c 2007          	jra	L7052
4252  028e               L5442:
4253                     ; 118 				*str = (dec+'0');
4255  028e 7b06          	ld	a,(OFST+6,sp)
4256  0290 ab30          	add	a,#48
4257  0292 1e01          	ldw	x,(OFST+1,sp)
4258  0294 f7            	ld	(x),a
4259                     ; 119 				break;
4261  0295               L7052:
4262                     ; 123 		width--;
4264  0295 0a07          	dec	(OFST+7,sp)
4265                     ; 124 		str++;
4267  0297 1e01          	ldw	x,(OFST+1,sp)
4268  0299 1c0001        	addw	x,#1
4269  029c 1f01          	ldw	(OFST+1,sp),x
4270  029e               L1052:
4271                     ; 88 	while(width)
4273  029e 0d07          	tnz	(OFST+7,sp)
4274  02a0 2703          	jreq	L05
4275  02a2 cc0203        	jp	L7742
4276  02a5               L05:
4277                     ; 126 }
4280  02a5 85            	popw	x
4281  02a6 81            	ret
4343                     ; 128 void hexToAscii(u8* str,u16 hex,u8 width)
4343                     ; 129 {
4344                     	switch	.text
4345  02a7               _hexToAscii:
4347  02a7 89            	pushw	x
4348  02a8 89            	pushw	x
4349       00000002      OFST:	set	2
4352  02a9 ac630363      	jpf	L7552
4353  02ad               L5552:
4354                     ; 133 		switch(width)
4356  02ad 7b09          	ld	a,(OFST+7,sp)
4358                     ; 163 			default: *str = '0';
4359  02af 4a            	dec	a
4360  02b0 2603          	jrne	L65
4361  02b2 cc0337        	jp	L7152
4362  02b5               L65:
4363  02b5 4a            	dec	a
4364  02b6 2758          	jreq	L5152
4365  02b8 4a            	dec	a
4366  02b9 2730          	jreq	L3152
4367  02bb 4a            	dec	a
4368  02bc 2709          	jreq	L1152
4369  02be               L1252:
4372  02be 1e03          	ldw	x,(OFST+1,sp)
4373  02c0 a630          	ld	a,#48
4374  02c2 f7            	ld	(x),a
4375  02c3 ac5a035a      	jpf	L5652
4376  02c7               L1152:
4377                     ; 137 				tmp = (hex >> 12);
4379  02c7 1e07          	ldw	x,(OFST+5,sp)
4380  02c9 01            	rrwa	x,a
4381  02ca 4f            	clr	a
4382  02cb 41            	exg	a,xl
4383  02cc 4e            	swap	a
4384  02cd a40f          	and	a,#15
4385  02cf 02            	rlwa	x,a
4386  02d0 1f01          	ldw	(OFST-1,sp),x
4387                     ; 138 				if(tmp > 9) *str = tmp + ('A' - 10);
4389  02d2 1e01          	ldw	x,(OFST-1,sp)
4390  02d4 a3000a        	cpw	x,#10
4391  02d7 2509          	jrult	L7652
4394  02d9 7b02          	ld	a,(OFST+0,sp)
4395  02db ab37          	add	a,#55
4396  02dd 1e03          	ldw	x,(OFST+1,sp)
4397  02df f7            	ld	(x),a
4399  02e0 2078          	jra	L5652
4400  02e2               L7652:
4401                     ; 139 				else *str = tmp + '0';
4403  02e2 7b02          	ld	a,(OFST+0,sp)
4404  02e4 ab30          	add	a,#48
4405  02e6 1e03          	ldw	x,(OFST+1,sp)
4406  02e8 f7            	ld	(x),a
4407  02e9 206f          	jra	L5652
4408  02eb               L3152:
4409                     ; 144 				tmp = (hex >> 8) & 0x000F;
4411  02eb 1e07          	ldw	x,(OFST+5,sp)
4412  02ed 4f            	clr	a
4413  02ee 01            	rrwa	x,a
4414  02ef 01            	rrwa	x,a
4415  02f0 a40f          	and	a,#15
4416  02f2 5f            	clrw	x
4417  02f3 02            	rlwa	x,a
4418  02f4 1f01          	ldw	(OFST-1,sp),x
4419  02f6 01            	rrwa	x,a
4420                     ; 145 				if(tmp > 9) *str = tmp + ('A' - 10);
4422  02f7 1e01          	ldw	x,(OFST-1,sp)
4423  02f9 a3000a        	cpw	x,#10
4424  02fc 2509          	jrult	L3752
4427  02fe 7b02          	ld	a,(OFST+0,sp)
4428  0300 ab37          	add	a,#55
4429  0302 1e03          	ldw	x,(OFST+1,sp)
4430  0304 f7            	ld	(x),a
4432  0305 2053          	jra	L5652
4433  0307               L3752:
4434                     ; 146 				else *str = tmp + '0';
4436  0307 7b02          	ld	a,(OFST+0,sp)
4437  0309 ab30          	add	a,#48
4438  030b 1e03          	ldw	x,(OFST+1,sp)
4439  030d f7            	ld	(x),a
4440  030e 204a          	jra	L5652
4441  0310               L5152:
4442                     ; 151 				tmp = (hex >> 4) & 0x000F;
4444  0310 1e07          	ldw	x,(OFST+5,sp)
4445  0312 54            	srlw	x
4446  0313 54            	srlw	x
4447  0314 54            	srlw	x
4448  0315 54            	srlw	x
4449  0316 01            	rrwa	x,a
4450  0317 a40f          	and	a,#15
4451  0319 5f            	clrw	x
4452  031a 5f            	clrw	x
4453  031b 97            	ld	xl,a
4454  031c 1f01          	ldw	(OFST-1,sp),x
4455                     ; 152 				if(tmp > 9) *str = tmp + ('A' - 10);
4457  031e 1e01          	ldw	x,(OFST-1,sp)
4458  0320 a3000a        	cpw	x,#10
4459  0323 2509          	jrult	L7752
4462  0325 7b02          	ld	a,(OFST+0,sp)
4463  0327 ab37          	add	a,#55
4464  0329 1e03          	ldw	x,(OFST+1,sp)
4465  032b f7            	ld	(x),a
4467  032c 202c          	jra	L5652
4468  032e               L7752:
4469                     ; 153 				else *str = tmp + '0';
4471  032e 7b02          	ld	a,(OFST+0,sp)
4472  0330 ab30          	add	a,#48
4473  0332 1e03          	ldw	x,(OFST+1,sp)
4474  0334 f7            	ld	(x),a
4475  0335 2023          	jra	L5652
4476  0337               L7152:
4477                     ; 158 				tmp = hex & 0x000F;
4479  0337 7b07          	ld	a,(OFST+5,sp)
4480  0339 97            	ld	xl,a
4481  033a 7b08          	ld	a,(OFST+6,sp)
4482  033c a40f          	and	a,#15
4483  033e 5f            	clrw	x
4484  033f 02            	rlwa	x,a
4485  0340 1f01          	ldw	(OFST-1,sp),x
4486  0342 01            	rrwa	x,a
4487                     ; 159 				if(tmp > 9) *str = tmp + ('A' - 10);
4489  0343 1e01          	ldw	x,(OFST-1,sp)
4490  0345 a3000a        	cpw	x,#10
4491  0348 2509          	jrult	L3062
4494  034a 7b02          	ld	a,(OFST+0,sp)
4495  034c ab37          	add	a,#55
4496  034e 1e03          	ldw	x,(OFST+1,sp)
4497  0350 f7            	ld	(x),a
4499  0351 2007          	jra	L5652
4500  0353               L3062:
4501                     ; 160 				else *str = tmp + '0';
4503  0353 7b02          	ld	a,(OFST+0,sp)
4504  0355 ab30          	add	a,#48
4505  0357 1e03          	ldw	x,(OFST+1,sp)
4506  0359 f7            	ld	(x),a
4507  035a               L5652:
4508                     ; 165 		width--;
4510  035a 0a09          	dec	(OFST+7,sp)
4511                     ; 166 		str++;
4513  035c 1e03          	ldw	x,(OFST+1,sp)
4514  035e 1c0001        	addw	x,#1
4515  0361 1f03          	ldw	(OFST+1,sp),x
4516  0363               L7552:
4517                     ; 131 	while(width)
4519  0363 0d09          	tnz	(OFST+7,sp)
4520  0365 2703          	jreq	L06
4521  0367 cc02ad        	jp	L5552
4522  036a               L06:
4523                     ; 168 }
4526  036a 5b04          	addw	sp,#4
4527  036c 81            	ret
4620                     ; 170 void showLine(const u8 x,const u8 y,u8* lcd_stack,char * str,...)
4620                     ; 171 {
4621                     	switch	.text
4622  036d               _showLine:
4624  036d 89            	pushw	x
4625  036e 5204          	subw	sp,#4
4626       00000004      OFST:	set	4
4629                     ; 172 	u8 coordinate = 16 * y + x;
4631  0370 9f            	ld	a,xl
4632  0371 97            	ld	xl,a
4633  0372 a610          	ld	a,#16
4634  0374 42            	mul	x,a
4635  0375 9f            	ld	a,xl
4636  0376 1b05          	add	a,(OFST+1,sp)
4637  0378 6b04          	ld	(OFST+0,sp),a
4638                     ; 175 	va_start(marker,str); // Initialize variable arguments.  
4640  037a 96            	ldw	x,sp
4641  037b 1c000d        	addw	x,#OFST+9
4642  037e 1f02          	ldw	(OFST-2,sp),x
4643                     ; 176 	for(i=0;i<64;i++)
4645  0380 0f01          	clr	(OFST-3,sp)
4646  0382               L5562:
4649  0382 0c01          	inc	(OFST-3,sp)
4652  0384 7b01          	ld	a,(OFST-3,sp)
4653  0386 a140          	cp	a,#64
4654  0388 25f8          	jrult	L5562
4656  038a ac980498      	jpf	L5662
4657  038e               L3662:
4658                     ; 182 		if(coordinate > 64) break;	//防止堆栈溢出
4660  038e 7b04          	ld	a,(OFST+0,sp)
4661  0390 a141          	cp	a,#65
4662  0392 2503          	jrult	L1762
4664  0394               L7662:
4665                     ; 217 	va_end( marker ); // Reset variable arguments. 
4667                     ; 218 } 
4670  0394 5b06          	addw	sp,#6
4671  0396 81            	ret
4672  0397               L1762:
4673                     ; 184 		if(*str == '\\')
4675  0397 1e0b          	ldw	x,(OFST+7,sp)
4676  0399 f6            	ld	a,(x)
4677  039a a15c          	cp	a,#92
4678  039c 261b          	jrne	L3762
4679                     ; 186 			str++;
4681  039e 1e0b          	ldw	x,(OFST+7,sp)
4682  03a0 1c0001        	addw	x,#1
4683  03a3 1f0b          	ldw	(OFST+7,sp),x
4684                     ; 187 			lcd_stack[coordinate] = *str;
4686  03a5 7b09          	ld	a,(OFST+5,sp)
4687  03a7 97            	ld	xl,a
4688  03a8 7b0a          	ld	a,(OFST+6,sp)
4689  03aa 1b04          	add	a,(OFST+0,sp)
4690  03ac 2401          	jrnc	L46
4691  03ae 5c            	incw	x
4692  03af               L46:
4693  03af 02            	rlwa	x,a
4694  03b0 160b          	ldw	y,(OFST+7,sp)
4695  03b2 90f6          	ld	a,(y)
4696  03b4 f7            	ld	(x),a
4698  03b5 ac8f048f      	jpf	L5762
4699  03b9               L3762:
4700                     ; 189 		else if(*str == '%')
4702  03b9 1e0b          	ldw	x,(OFST+7,sp)
4703  03bb f6            	ld	a,(x)
4704  03bc a125          	cp	a,#37
4705  03be 2703          	jreq	L67
4706  03c0 cc047f        	jp	L7762
4707  03c3               L67:
4708                     ; 191 			str++;
4710  03c3 1e0b          	ldw	x,(OFST+7,sp)
4711  03c5 1c0001        	addw	x,#1
4712  03c8 1f0b          	ldw	(OFST+7,sp),x
4713                     ; 192 			if (*str == 'd' || *str == 'D')
4715  03ca 1e0b          	ldw	x,(OFST+7,sp)
4716  03cc f6            	ld	a,(x)
4717  03cd a164          	cp	a,#100
4718  03cf 2707          	jreq	L3072
4720  03d1 1e0b          	ldw	x,(OFST+7,sp)
4721  03d3 f6            	ld	a,(x)
4722  03d4 a144          	cp	a,#68
4723  03d6 2637          	jrne	L1072
4724  03d8               L3072:
4725                     ; 194 				str++;
4727  03d8 1e0b          	ldw	x,(OFST+7,sp)
4728  03da 1c0001        	addw	x,#1
4729  03dd 1f0b          	ldw	(OFST+7,sp),x
4730                     ; 195 				decToAscii(&lcd_stack[coordinate],va_arg(marker,u16),(*str-'0'));
4732  03df 1e0b          	ldw	x,(OFST+7,sp)
4733  03e1 f6            	ld	a,(x)
4734  03e2 a030          	sub	a,#48
4735  03e4 88            	push	a
4736  03e5 1e03          	ldw	x,(OFST-1,sp)
4737  03e7 1c0002        	addw	x,#2
4738  03ea 1f03          	ldw	(OFST-1,sp),x
4739  03ec 1e03          	ldw	x,(OFST-1,sp)
4740  03ee 5a            	decw	x
4741  03ef 5a            	decw	x
4742  03f0 fe            	ldw	x,(x)
4743  03f1 89            	pushw	x
4744  03f2 7b0c          	ld	a,(OFST+8,sp)
4745  03f4 97            	ld	xl,a
4746  03f5 7b0d          	ld	a,(OFST+9,sp)
4747  03f7 1b07          	add	a,(OFST+3,sp)
4748  03f9 2401          	jrnc	L66
4749  03fb 5c            	incw	x
4750  03fc               L66:
4751  03fc 02            	rlwa	x,a
4752  03fd cd01fe        	call	_decToAscii
4754  0400 5b03          	addw	sp,#3
4755                     ; 196 				coordinate += (*str-'0'-1);
4757  0402 1e0b          	ldw	x,(OFST+7,sp)
4758  0404 f6            	ld	a,(x)
4759  0405 a031          	sub	a,#49
4760  0407 1b04          	add	a,(OFST+0,sp)
4761  0409 6b04          	ld	(OFST+0,sp),a
4763  040b ac8f048f      	jpf	L5762
4764  040f               L1072:
4765                     ; 198 			else if(*str == 'c' || *str == 'C')
4767  040f 1e0b          	ldw	x,(OFST+7,sp)
4768  0411 f6            	ld	a,(x)
4769  0412 a163          	cp	a,#99
4770  0414 2707          	jreq	L1172
4772  0416 1e0b          	ldw	x,(OFST+7,sp)
4773  0418 f6            	ld	a,(x)
4774  0419 a143          	cp	a,#67
4775  041b 261f          	jrne	L7072
4776  041d               L1172:
4777                     ; 200 				lcd_stack[coordinate] = va_arg(marker,u16);
4779  041d 7b09          	ld	a,(OFST+5,sp)
4780  041f 97            	ld	xl,a
4781  0420 7b0a          	ld	a,(OFST+6,sp)
4782  0422 1b04          	add	a,(OFST+0,sp)
4783  0424 2401          	jrnc	L07
4784  0426 5c            	incw	x
4785  0427               L07:
4786  0427 02            	rlwa	x,a
4787  0428 1602          	ldw	y,(OFST-2,sp)
4788  042a 72a90002      	addw	y,#2
4789  042e 1702          	ldw	(OFST-2,sp),y
4790  0430 1602          	ldw	y,(OFST-2,sp)
4791  0432 905a          	decw	y
4792  0434 905a          	decw	y
4793  0436 90e601        	ld	a,(1,y)
4794  0439 f7            	ld	(x),a
4796  043a 2053          	jra	L5762
4797  043c               L7072:
4798                     ; 202 			else if(*str == 'x' || *str == 'X')
4800  043c 1e0b          	ldw	x,(OFST+7,sp)
4801  043e f6            	ld	a,(x)
4802  043f a178          	cp	a,#120
4803  0441 2707          	jreq	L7172
4805  0443 1e0b          	ldw	x,(OFST+7,sp)
4806  0445 f6            	ld	a,(x)
4807  0446 a158          	cp	a,#88
4808  0448 2645          	jrne	L5762
4809  044a               L7172:
4810                     ; 204 				str++;
4812  044a 1e0b          	ldw	x,(OFST+7,sp)
4813  044c 1c0001        	addw	x,#1
4814  044f 1f0b          	ldw	(OFST+7,sp),x
4815                     ; 205 				hexToAscii(&lcd_stack[coordinate],va_arg(marker,u16),(*str - '0'));
4817  0451 1e0b          	ldw	x,(OFST+7,sp)
4818  0453 f6            	ld	a,(x)
4819  0454 a030          	sub	a,#48
4820  0456 88            	push	a
4821  0457 1e03          	ldw	x,(OFST-1,sp)
4822  0459 1c0002        	addw	x,#2
4823  045c 1f03          	ldw	(OFST-1,sp),x
4824  045e 1e03          	ldw	x,(OFST-1,sp)
4825  0460 5a            	decw	x
4826  0461 5a            	decw	x
4827  0462 fe            	ldw	x,(x)
4828  0463 89            	pushw	x
4829  0464 7b0c          	ld	a,(OFST+8,sp)
4830  0466 97            	ld	xl,a
4831  0467 7b0d          	ld	a,(OFST+9,sp)
4832  0469 1b07          	add	a,(OFST+3,sp)
4833  046b 2401          	jrnc	L27
4834  046d 5c            	incw	x
4835  046e               L27:
4836  046e 02            	rlwa	x,a
4837  046f cd02a7        	call	_hexToAscii
4839  0472 5b03          	addw	sp,#3
4840                     ; 206 				coordinate += (*str - '0' - 1);
4842  0474 1e0b          	ldw	x,(OFST+7,sp)
4843  0476 f6            	ld	a,(x)
4844  0477 a031          	sub	a,#49
4845  0479 1b04          	add	a,(OFST+0,sp)
4846  047b 6b04          	ld	(OFST+0,sp),a
4847  047d 2010          	jra	L5762
4848  047f               L7762:
4849                     ; 212 			lcd_stack[coordinate] = *str;
4851  047f 7b09          	ld	a,(OFST+5,sp)
4852  0481 97            	ld	xl,a
4853  0482 7b0a          	ld	a,(OFST+6,sp)
4854  0484 1b04          	add	a,(OFST+0,sp)
4855  0486 2401          	jrnc	L47
4856  0488 5c            	incw	x
4857  0489               L47:
4858  0489 02            	rlwa	x,a
4859  048a 160b          	ldw	y,(OFST+7,sp)
4860  048c 90f6          	ld	a,(y)
4861  048e f7            	ld	(x),a
4862  048f               L5762:
4863                     ; 214 		str++;
4865  048f 1e0b          	ldw	x,(OFST+7,sp)
4866  0491 1c0001        	addw	x,#1
4867  0494 1f0b          	ldw	(OFST+7,sp),x
4868                     ; 215 		coordinate++;
4870  0496 0c04          	inc	(OFST+0,sp)
4871  0498               L5662:
4872                     ; 180 	while(*str != '\0')
4874  0498 1e0b          	ldw	x,(OFST+7,sp)
4875  049a 7d            	tnz	(x)
4876  049b 2703          	jreq	L001
4877  049d cc038e        	jp	L3662
4878  04a0               L001:
4879  04a0 ac940394      	jpf	L7662
4978                     ; 21 main()
4978                     ; 22 {
4979                     	switch	.text
4980  04a4               _main:
4982  04a4 521f          	subw	sp,#31
4983       0000001f      OFST:	set	31
4986                     ; 23 	u8 num=0;
4988                     ; 25 	AT45DBXX_Init();/*
4990  04a6 cd0082        	call	_AT45DBXX_Init
4992                     ; 30 	for(num=0;num<30;num++) 
4994  04a9 0f1f          	clr	(OFST+0,sp)
4995  04ab               L7672:
4996                     ; 32 		write_buffer((u16)num,num);
4998  04ab 7b1f          	ld	a,(OFST+0,sp)
4999  04ad 88            	push	a
5000  04ae 7b20          	ld	a,(OFST+1,sp)
5001  04b0 5f            	clrw	x
5002  04b1 97            	ld	xl,a
5003  04b2 cd0091        	call	_write_buffer
5005  04b5 84            	pop	a
5006                     ; 33 		delay_ms(1);
5008  04b6 ae0001        	ldw	x,#1
5009  04b9 cd0000        	call	_delay_ms
5011                     ; 30 	for(num=0;num<30;num++) 
5013  04bc 0c1f          	inc	(OFST+0,sp)
5016  04be 7b1f          	ld	a,(OFST+0,sp)
5017  04c0 a11e          	cp	a,#30
5018  04c2 25e7          	jrult	L7672
5019                     ; 35 	for(num=0;num<30;num++)
5021  04c4 0f1f          	clr	(OFST+0,sp)
5022  04c6               L5772:
5023                     ; 37 		tmp[num]=read_buffer((u16)num);
5025  04c6 96            	ldw	x,sp
5026  04c7 1c0001        	addw	x,#OFST-30
5027  04ca 9f            	ld	a,xl
5028  04cb 5e            	swapw	x
5029  04cc 1b1f          	add	a,(OFST+0,sp)
5030  04ce 2401          	jrnc	L401
5031  04d0 5c            	incw	x
5032  04d1               L401:
5033  04d1 02            	rlwa	x,a
5034  04d2 89            	pushw	x
5035  04d3 7b21          	ld	a,(OFST+2,sp)
5036  04d5 5f            	clrw	x
5037  04d6 97            	ld	xl,a
5038  04d7 cd00ba        	call	_read_buffer
5040  04da 85            	popw	x
5041  04db f7            	ld	(x),a
5042                     ; 38 		delay_ms(1);
5044  04dc ae0001        	ldw	x,#1
5045  04df cd0000        	call	_delay_ms
5047                     ; 35 	for(num=0;num<30;num++)
5049  04e2 0c1f          	inc	(OFST+0,sp)
5052  04e4 7b1f          	ld	a,(OFST+0,sp)
5053  04e6 a11e          	cp	a,#30
5054  04e8 25dc          	jrult	L5772
5055                     ; 40 	sendCodeST7920(0x80);
5057  04ea a680          	ld	a,#128
5058  04ec cd0126        	call	_sendCodeST7920
5060                     ; 41 	st7920LcdInit();
5062  04ef cd00f0        	call	_st7920LcdInit
5064                     ; 42 	showLine(0,0,lcd_buffer,"AT45DBXX Example");
5066  04f2 ae0027        	ldw	x,#L3003
5067  04f5 89            	pushw	x
5068  04f6 ae0000        	ldw	x,#_lcd_buffer
5069  04f9 89            	pushw	x
5070  04fa 5f            	clrw	x
5071  04fb cd036d        	call	_showLine
5073  04fe 5b04          	addw	sp,#4
5074                     ; 43 	showLine(0,1,lcd_buffer,"Program: OK!");
5076  0500 ae001a        	ldw	x,#L5003
5077  0503 89            	pushw	x
5078  0504 ae0000        	ldw	x,#_lcd_buffer
5079  0507 89            	pushw	x
5080  0508 ae0001        	ldw	x,#1
5081  050b cd036d        	call	_showLine
5083  050e 5b04          	addw	sp,#4
5084                     ; 44 	showLine(0,2,lcd_buffer,"Verify: OK!");
5086  0510 ae000e        	ldw	x,#L7003
5087  0513 89            	pushw	x
5088  0514 ae0000        	ldw	x,#_lcd_buffer
5089  0517 89            	pushw	x
5090  0518 ae0002        	ldw	x,#2
5091  051b cd036d        	call	_showLine
5093  051e 5b04          	addw	sp,#4
5094                     ; 45 	showLine(0,3,lcd_buffer,"Output:");
5096  0520 ae0006        	ldw	x,#L1103
5097  0523 89            	pushw	x
5098  0524 ae0000        	ldw	x,#_lcd_buffer
5099  0527 89            	pushw	x
5100  0528 ae0003        	ldw	x,#3
5101  052b cd036d        	call	_showLine
5103  052e 5b04          	addw	sp,#4
5104                     ; 48 	for(num=0;num<30;num++)
5106  0530 0f1f          	clr	(OFST+0,sp)
5107  0532               L3103:
5108                     ; 50 		showLine(8,3,lcd_buffer,"0x%x2",(u16)tmp[num]);
5110  0532 96            	ldw	x,sp
5111  0533 1c0001        	addw	x,#OFST-30
5112  0536 9f            	ld	a,xl
5113  0537 5e            	swapw	x
5114  0538 1b1f          	add	a,(OFST+0,sp)
5115  053a 2401          	jrnc	L601
5116  053c 5c            	incw	x
5117  053d               L601:
5118  053d 02            	rlwa	x,a
5119  053e f6            	ld	a,(x)
5120  053f 5f            	clrw	x
5121  0540 97            	ld	xl,a
5122  0541 89            	pushw	x
5123  0542 ae0000        	ldw	x,#L1203
5124  0545 89            	pushw	x
5125  0546 ae0000        	ldw	x,#_lcd_buffer
5126  0549 89            	pushw	x
5127  054a ae0803        	ldw	x,#2051
5128  054d cd036d        	call	_showLine
5130  0550 5b06          	addw	sp,#6
5131                     ; 51 		refreshLCD(lcd_buffer);
5133  0552 ae0000        	ldw	x,#_lcd_buffer
5134  0555 cd018e        	call	_refreshLCD
5136                     ; 52 		delay_ms(1000);
5138  0558 ae03e8        	ldw	x,#1000
5139  055b cd0000        	call	_delay_ms
5141                     ; 48 	for(num=0;num<30;num++)
5143  055e 0c1f          	inc	(OFST+0,sp)
5146  0560 7b1f          	ld	a,(OFST+0,sp)
5147  0562 a11e          	cp	a,#30
5148  0564 25cc          	jrult	L3103
5149  0566               L3203:
5150                     ; 55 	while (1);
5152  0566 20fe          	jra	L3203
5165                     	xdef	_main
5166                     	switch	.ubsct
5167  0000               _lcd_buffer:
5168  0000 000000000000  	ds.b	64
5169                     	xdef	_lcd_buffer
5170                     	xdef	_showLine
5171                     	xdef	_hexToAscii
5172                     	xdef	_decToAscii
5173                     	xdef	_refreshLCD
5174                     	xdef	_st7920LcdInit
5175                     	xdef	_sendDataST7920
5176                     	xdef	_sendCodeST7920
5177                     	xdef	_read_buffer
5178                     	xdef	_write_buffer
5179                     	xdef	_AT45DBXX_Init
5180                     	xdef	_SPI_rechar
5181                     	xdef	_SPI_sendchar
5182                     	xdef	_SPI_Init
5183                     	xdef	_delay_us
5184                     	xdef	_delay_ms
5185                     .const:	section	.text
5186  0000               L1203:
5187  0000 307825783200  	dc.b	"0x%x2",0
5188  0006               L1103:
5189  0006 4f7574707574  	dc.b	"Output:",0
5190  000e               L7003:
5191  000e 566572696679  	dc.b	"Verify: OK!",0
5192  001a               L5003:
5193  001a 50726f677261  	dc.b	"Program: OK!",0
5194  0027               L3003:
5195  0027 415434354442  	dc.b	"AT45DBXX Example",0
5215                     	end
