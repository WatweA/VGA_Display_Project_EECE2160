#include "VGADisplay.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>

/**
 * Constructor Initialize general-purpose I/O
 * - Opens access to physical memory /dev/mem
 * - Maps memory at offset 'gpio_address' into virtual address space
 *
 * @param None Default constructor does not need arguments.
 * @return None Default constructor does not return anything.
 */
VGADisplay::VGADisplay()
{
	// Open memory mapped I/O
	fd = open("/dev/mem", O_RDWR);

	// Map physical memory
	pBase = (char *) mmap(NULL, gpio_size, PROT_READ | PROT_WRITE,
	MAP_SHARED, fd, gpio_address);

	// Check success
	if (pBase == (void *) -1)
	{
		std::cerr << "Error mapping memory - fogot sudo?\n";
		exit(1);
	}

	// Initial display colors
	RGB_Write(15, 15, 15);
	sleep(3); // Delay for 3 seconds
}

/**
 * Destructor to close general-purpose I/O.
 * - Uses virtual address where I/O was mapped.
 * - Uses file descriptor previously returned by 'open'.
 *
 * @param None Destructor does not need arguments.
 * @return None Destructor does not return anything.
 */
VGADisplay::~VGADisplay()
{
	munmap(pBase, 0xff); // Unmap physical memory
	close(fd); // Close memory mapped I/O
}

/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *
 * - Uses base address returned by 'mmap'.
 * @parem offset Offset where device is mapped.
 * @param value Value to be written.
 */
void VGADisplay::RegisterWrite(unsigned offset, unsigned value)
{
	* (volatile unsigned *) (pBase + offset) = value;
}

/**
 * Read a 4-byte value from the specified general-purpose I/O location.
 *
 * - Uses base address returned by 'mmap'.
 * @param offset Offset where device is mapped.
 * @return Value read.
 */
int VGADisplay::RegisterRead (unsigned offset)
{
	return * (volatile unsigned *) (pBase + offset);
}

/**
 * Writes RGB colors to the VGA Controller
 *
 * - Uses base address of I/O
 * @param red Red color value
 * @param green Green color value
 * @param blue Blue color value
 */
void VGADisplay::RGB_Write(int red, int green, int blue)
{
	// Set the box colors
	RegisterWrite(red_color_offset, red);
	RegisterWrite(green_color_offset, green);
	RegisterWrite(blue_color_offset, blue);
}

/**
 * Writes RGB colors to the background on the display
 *
 * - Uses base address of I/O
 * @param red Red color value
 * @param green Green color value
 * @param blue Blue color value
 */
void VGADisplay::Background_RGB_Write(int red, int green, int blue)
{
	// Set the background colors
	RegisterWrite(bg_red_color_offset, red);
	RegisterWrite(bg_green_color_offset, green);
	RegisterWrite(bg_blue_color_offset, blue);
}

/**
 * Writes the values for the box's horizontal and
 * vertical size
 * - Uses base adresses of I/O
 * @param h Box's horizontal size value
 * @param v Box's vertical size value
 */ /*
void VGADisplay::Size_Write(int h, int v)
{
	// Set the box range
	RegisterWrite(h_size_offset, h);
	RegisterWrite(v_size_offset, v);
}
*/

