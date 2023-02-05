# Bai 9: Nhap vao mot chuoi, xuat ra chuoi nguoc
.data
	str:.space 256
	tb1:.asciiz "Nhap vao mot chuoi: "
	tb2:.asciiz "Chuoi nguoc la: "
.text
	# Xuat thong bao 1
	li $v0, 4
	la $a0, tb1
	syscall
          
        # Nhap vao 1 chuoi
  	li $v0, 8         
  	la $a0, str   # Luu chuoi hien tai
  	move $s0, $a0
  	li $a1, 256   # Cap phat do dai chuoi
  	syscall
  	
  	#Xuat thong bao 2
  	li $v0, 4
	la $a0, tb2
	syscall
     	
     	# i = 0
  	li   $t1, 0        

push:    
	# dua tung ki tu vao stack         
  	lb  $t0, str($t1)  # gan ki tu s[i] vao t0
  	beqz $t0, end      # t0 = 0 thi ket thuc chuoi
	
	# khoi tao stack
  	subu  $sp, $sp, 4  
  	# dua t0 vao stack
  	sw   $t0, ($sp)     

  	addu  $t1, $t1 1     # i = i + 1
  	j push         	     # push stack
	
end:       
	# Bo qua ki tu xuong dong /n cua chuoi
	lw   $t0, ($sp)     
  	addu  $sp, $sp, 4          
  	li    $t1, 0         # i = 0
pop:
  	lw   $t0, ($sp)     # lay ra ki tu s[i] khoi stack
  	addu  $sp, $sp, 4
  	beqz $t0, done      # t0 = 0 thi ket thuc chuoi
  	
	sb    $t0, str($t1)
	addu  $t1, $t1, 1    # i = i + 1
  	j pop		     # pop stack
done:   	              
	# In chuoi vua dao nguoc
  	li    $v0, 4    
  	move $a0, $s0     
  	la    $a1, str       
 	syscall
 	
 	# thoat
  	li    $v0, 10        
  	syscall

