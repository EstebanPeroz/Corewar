	.name "Mine2"
	.comment "My test robot"

hi: live %2
	ld %0, r3
	zjmp %:hi
