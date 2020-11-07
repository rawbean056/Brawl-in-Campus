Last updated: 16 December 2017 
####################################

To make it work, you need to include stb_image.h in your project. It is collected from (stb_image - v2.16 - public domain image loader - http://nothings.org/stb_image.h). The library is an advanced image loader library and works for different types of images (i.e. bmp, png). It even handles transparency and works for any resolution!

I added 2 new functions in iGraphics.h which are iLoadImage(filename) and iShowImage(x, y, width, height, id). Here's the functionalities:

1) int iLoadImage(filename): returns an integer id for the image specified in filename. The id will be used later for rendering (like file pointer). This function needs to be invoked in the main function.

2) void iShowImage(x, y, width, height, id): render the image of specific id obtained from previous function. Image will be rendered at (x,y) with width and height (like iRectangle()). So you can scale the image by tweaking width and height.
Note that, you have to specify iColor before calling iShowImage(), and that color will blend with image's pixel colors. I recommend to use (255, 255, 255).



The function in stb_image.h does not convert an image into texture. I wrote some codes inside iLoadImage() to perform this conversion and apply texture mapping in iShowImage(). It works for border cases. As a result, iLoadImage() and iShowImage() function perform the task of iShowBMP(), iShowBMP2() and iShowBMPAlternative().

iMain.cpp is an example where this functions are invoked to render png images. The images are in ./images.

To make it more optimized, I had to split some codes from iInitialize into iStart(). Here, iInitialize() will setup the requirements for rendering (i.e. window, axis etc.) and iStart() will start rendering. See main() for better understanding.

Let me know if there's any bug.


------------
Jubair

