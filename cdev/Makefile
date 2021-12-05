obj-m   :=   hello.o
KERNELDIR   :=   /usr/src/linux-headers-5.5.0-kali2-amd64/
PWD   :=   $(shell pwd)
default:
	$(MAKE) $(CROSS_ARCH) -C  $(KERNELDIR)   M=$(PWD) modules

install:
	$(MAKE)  $(CROSS_ARCH) -C  $(KERNELDIR)   M=$(PWD)   modules_install
clean:
	@rm   -rf   *.o   *~   core   .depend   .*.cmd   *.ko   *.mod.c   .tmp_versions *.symvers *.d *.markers *.order *.mod

.PHONY:   modules   modules_install   clean  main
