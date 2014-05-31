#include <stdio.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#define BCM2708_PERI_BASE	0x20000000
#define GPIO_BASE		(BCM2708_PERI_BASE + 0x200000)

#define BLOCK_SIZE		(4*1024)

#define INP_GPIO(g) *(gpio.addr + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio.addr + ((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g, a) *(gpio.addr + (((g)/10))) |= (((a)<=3?(a) + 4:(a)==4?3:2)<<(((g)%10)*3))

#define GPIO_SET *(gpio.addr + 7) // sets bits which are 1, ignores bits which are 0
#define GPIO_CLR *(gpio.addr + 10) // clears bits which are 1, ignores bits which are 0

#define GPIO_READ(g) *(gpio.addr + 13) &= (1<<(g))

//IO access
struct bcm2835_peripheral {
	unsigned long addr_p;
	int mem_fd;
	void *map;
	volatile unsigned int *addr;
};

//struct bcm2835_peripheral gpio = {GPIO_BASE};

extern struct bcm2835_peripheral gpio;

// Function prototypes
int map_peripheral(struct bcm2835_peripheral *p);
void unmap_peripheral(struct bcm2835_peripheral *p);
