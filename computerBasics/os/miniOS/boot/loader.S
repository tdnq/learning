%include "./include/boot.inc"
SECTION loader vstart=LOADER_BASE_ADDR
    mov byte[gs:0x00],'y'
    mov byte[gs:0x01],0xA4
    mov byte[gs:0x02],'e'
    mov byte[gs:0x03],0xA4
    jmp $