
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Image.h"


//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------
 
  Image im ;
  im.ppm_read_from_file( "gargouille.ppm");
 

  //---------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  
  //Image imSmall = Image(& im);
  Image  imBw (im);


  // Desaturate image_bw
 imBw.ppm_desaturate();

  // Write the desaturated image into "gargouille_BW.ppm"

  imBw.ppm_write_to_file("gargouille_BW.ppm");
 

  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small

  Image imSmall(im);



  // Shrink image_small size 2-fold
  imSmall.ppm_shrink( 2);

  // Write the desaturated image into "gargouille_small.ppm"
 
  imSmall.ppm_write_to_file( "gargouille_small.ppm");

  return 0;
}


























































