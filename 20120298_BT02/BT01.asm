# Bai 1: Nhap vao mot chuoi, xuat lai chuoi do ra man hinh
.data
	str:.space 256
	tb01:.asciiz "Nhap mot chuoi: "
	tb02:.asciiz "Chuoi da nhap: "
.text
    la $a0, tb01    # In thong bao 1
    li $v0, 4       
    syscall

    li $v0, 8       # Doc vao 1 chuoi
    la $a0, str   # Luu do dai cua chuoi
    li $a1, 256    # Cap phat do dai cho chuoi
    move $t0, $a0   # Luu chuoi xuong thanh ghi t0
    syscall
    
    la $a0, tb02    # In thong bao 2 
    li $v0, 4
    syscall
 
    la $a0, str
    move $a0, $t0   # Luu dia chi cua chuoi vua nhap
    li $v0, 4       # In chuoi vua nhap
    syscall

    li $v0, 10      # Thoat chuong trinh
    syscall
	
