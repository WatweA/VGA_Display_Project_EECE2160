#ifndef VGA_DISPLAY_H
#define VGA_DISPLAY_H

// Physical base address of GPIO
	const unsigned gpio_address = 0x400d0000;

// Length of memory-mapped IO window
	const unsigned gpio_size = 0xff;
	const int red_color_offset = 0x100; // Offset for the box's red
	const int green_color_offset = 0x104; // Offset for box's green
	const int blue_color_offset = 0x108; // Offset for the box's blue
	const int bg_red_color_offset = 0x11c; // Offset for the background's red
	const int bg_green_color_offset = 0x120; // Offset for background's green
	const int bg_blue_color_offset = 0x124; // Offset for the background's blue
	const int h_min_offset = 0x10c; // Offset for x_min coordinate
	const int h_max_offset = 0x110; // Offset for x_max coordinate
	const int v_min_offset = 0x114; // Offset for v_min coordinate
	const int v_max_offset = 0x118; // Offset for v_max coordinate
/*	const int h_size_offset = 0x128; // Offset for box horizontal size
	const int v_size_offset = 0x12C; // Offset for box vetical size
*/

class VGADisplay
{
	// File descriptor for memory-mapped I/O
	int fd;

	// Mapped address
	char *pBase;

	// Write a value into the given memory offset in the memory-mapped I/O.
	void RegisterWrite(unsigned offset, unsigned value);

	// Read a value from the given memory offset in the memory-mapped I/O.
	int RegisterRead (unsigned offset);

	public:
	// Class constructor
	VGADisplay();

	// Destructor
	~VGADisplay();

	/*
	 * Writes RGB colors to the VGA Controller
	 * - Uses base address of I/O
	 * @param red Red color value
	 * @param green Green color value
	 * @param blue Blue color value
	 */
	void RGB_Write(int red, int green, int blue);

	/*
	 * Writes RGB colors to the background of the display
	 * - Uses base address of I/O
	 * @param red Red color value
	 * @param green Green color value
	 * @param blue Blue color value
	 */
	void Background_RGB_Write(int red, int green, int blue);

	/*
	 * Writes the values for the box's horizontal and
	 * vertical size
	 * - Uses base adresses of I/O
	 * @param h Box's horizontal size value
	 * @param v Box's vertical size value
	 */
//	void Size_Write(int h, int v);
};

#endif
