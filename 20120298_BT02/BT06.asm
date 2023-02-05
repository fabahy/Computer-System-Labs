# Bai 6: Nhap mot ky tu tu ban phim. Neu ky tu vua nhap thuoc [0-9], [a-z], [A-Z] thi xuat ra
# man hinh ky tu do va loai cua ky tu do (so, chu thuong, chu hoa).
.data
	tb0:.asciiz "Nhap vao mot ki tu: "
	tb1:.asciiz "\nKi tu vua nhap: "
	tb2:.asciiz " la so"
	tb3:.asciiz " la chu hoa"
	tb4:.asciiz " la chu thuong"
	tb5:.asciiz " khong phai la so, chu thuong hay chu hoa"
.text
	li $v0, 4
	la $a0, tb0	# Xuat thong bao 0
	syscall
	
	li $v0, 12	# Nhap vao 1 ki tu
	syscall
	
	move $s0, $v0
	
	li $v0, 4
	la $a0, tb1	# Xuat thong bao 1
	syscall
	
	
	bltu $s0, '0', upper
	bgtu $s0, '9', upper
	
	li $v0, 11
	move $a0, $s0
	syscall
	
	li $v0, 4
	la $a0, tb2
	syscall
	j Fin
	
upper:
	bltu $s0, 'A', lower
	bgtu $s0, 'Z', lower
	
	li $v0, 11
	move $a0, $s0
	syscall 
	
	li $v0, 4
	la $a0, tb3
	syscall
	j Fin
	
lower:
	bltu $s0, 'a', print
	bgtu $s0, 'z', print
	
	li $v0, 11
	move $a0, $s0
	syscall 
	
	li $v0, 4
	la $a0, tb4
	syscall
	j Fin
	
print:
	# xuat ki tu 
	li $v0, 11
	move $a0, $s0	    
	syscall
	
	#xuat thong bao 5
	li $v0, 4
	la $a0, tb5
	syscall
	
	j Fin
	
Fin:
	li $v0, 10	# Thoat chuong trinh
	syscall
