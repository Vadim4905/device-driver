KERNEL=/lib/modules/$(shell uname -r)/build
obj-m += mydriver.o

all:
	${MAKE} -C ${KERNEL} M=$(PWD) modules
clear:
	${MAKE} -C ${KERNEL} M=$(PWD) clean