#ifndef __K_IMAGEDECODER_HPP__
#define __K_IMAGEDECODER_HPP__

#include <vector>


class K_ImageDecoder
{
public:
	static int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height, const unsigned char* in_png, size_t in_size, bool convert_to_rgba32 = true);


private:
	K_ImageDecoder();
	~K_ImageDecoder();

};


#endif // __K_IMAGEDECODER_HPP__
