	.name "Mine"
	.comment "My test robot"

hi: live %1
	ld %0, r3
	zjmp %:hi
