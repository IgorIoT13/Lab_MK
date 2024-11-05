#ifndef SRC_LABS_FLAGSYS_FLAGSYS_H_
#define SRC_LABS_FLAGSYS_FLAGSYS_H_

#define SFLAG_1(FLAG) 	FLAG |= (1 << 0)
#define SFLAG_2(FLAG) 	FLAG |= (1 << 1)
#define SFLAG_3(FLAG) 	FLAG |= (1 << 2)
#define SFLAG_4(FLAG) 	FLAG |= (1 << 3)
#define SFLAG_5(FLAG) 	FLAG |= (1 << 4)
#define SFLAG_6(FLAG) 	FLAG |= (1 << 5)
#define SFLAG_7(FLAG) 	FLAG |= (1 << 6)
#define SFLAG_8(FLAG) 	FLAG |= (1 << 7)

#define DFLAG_1(FLAG) 	FLAG &= ~(1 << 0)
#define DFLAG_2(FLAG) 	FLAG &= ~(1 << 1)
#define DFLAG_3(FLAG) 	FLAG &= ~(1 << 2)
#define DFLAG_4(FLAG) 	FLAG &= ~(1 << 3)
#define DFLAG_5(FLAG) 	FLAG &= ~(1 << 4)
#define DFLAG_6(FLAG) 	FLAG &= ~(1 << 5)
#define DFLAG_7(FLAG) 	FLAG &= ~(1 << 6)
#define DFLAG_8(FLAG) 	FLAG &= ~(1 << 7)

#define CFLAG1(FLAG)	(FLAG & (1 << 0))
#define CFLAG2(FLAG)	(FLAG & (1 << 1))
#define CFLAG3(FLAG)	(FLAG & (1 << 2))
#define CFLAG4(FLAG)	(FLAG & (1 << 3))
#define CFLAG5(FLAG)	(FLAG & (1 << 4))
#define CFLAG6(FLAG)	(FLAG & (1 << 5))
#define CFLAG7(FLAG)	(FLAG & (1 << 6))
#define CFLAG8(FLAG)	(FLAG & (1 << 7))


#endif
