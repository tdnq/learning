;主引导程序
;----------
SECTION MBR vstart=0x7c00
    mov ax,cs
    mov ds,ax
    mov es,ax
    mov ss,ax
    mov fs,ax
    mov sp,0x7c00
;清屏利用0x06号功能,上卷全部行,则可清屏
;INT 0x10 功能号:0x06; 功能描述:上卷窗口
;输入:
;AH 功能号 =0x06
;AL = 上卷的行数
;BH = 上卷行属性
;(CL,CH)=窗口左上角的(X,Y)位置
;(DL,DH)=窗口右下角的(X,Y)位置
; 无返回值
    mov ax,0x600
    mov bx,0x700
    mov cx,0
    mov dx,0x184f
    int 0x10

    mov ah,3
    mov bh,0
    int 0x10

    mov ax,message
    mov bp,ax

    mov cx,5
    mov ax,0x1301

    mov bx,0x2

    int 0x10

    jmp $
    message db "1 MBR"
    times 510-($-$$) db 0
    db 0x55,0xaa