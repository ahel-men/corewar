.name           "champion executable"#commentaire
.comment        "men neyytk
 bag
 hi
 terb
 e7n
 i ?    ";dfdf#wa33333

entree:
	sti%:tirb,r1,%1
	zjmp%:tir
	ld	%0,r5
	ld	%0,r5
	live	%42

tir:    add	r3,r4,r3
         sti	r1,%:tirb,%1
	ld	%2304,r10
               	ld	%1,r5
	ld	%0,r11

	ld	%4,r3
tirf:	live	%42
	fork	%:tirf
	live	%742
	sub	r3,r5,r3
	zjmp	%:tirop
	ld	%0,r11
					fork	%:tirf
	live	%42
	sti r10,%-510,%0
	sti r10,%-404,%0
	sti	r10,%-303,%0
				sti	r10,%-202,%0
	ld	%0,r11
	zjmp	%:tirf

tirop:	ld	%368,r2
ld	%0,r3
	ld	%4,r4

tirb:	live	%1
	sti	r10,%-510,r2
			sti	r10,%-510,r3
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2, r4,  r2
	zjmp	%:tirop
			ld	%0,r11
	zjmp	%:entree
	zjmp	%:tir
