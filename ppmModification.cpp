
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblio.h"


//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------
 
  image*im=new(image);
  im->data = NULL;
  ppm_read_from_file(im , "gargouille.ppm");
 


  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw

  image * imBw;
  imBw = new image;
  imBw->width=im->width;
  imBw->height=im->height;

  imBw->data = new u_char[3 * imBw->width * imBw->height];


  memcpy(imBw->data, im->data , 3 * im->width * im->height * sizeof(*(imBw->data)));

  // Desaturate image_bw
  ppm_desaturate(imBw);

  // Write the desaturated image into "gargouille_BW.ppm"

  ppm_write_to_file(imBw , "gargouille_BW.ppm");
 

  // Free the desaturated image
  delete(imBw->data);
  delete(imBw);
 


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small

  image * imSmall;
  imSmall = new image;
  imSmall->width=im->width;
  imSmall->height=im->height;
  imSmall->data  = new u_char[3 * imSmall->width * imSmall->height];

  memcpy(imSmall->data, im->data , 3 * im->width * im->height * sizeof(*(imSmall->data)));

  // Shrink image_small size 2-fold
  ppm_shrink(imSmall, 2);

  // Write the desaturated image into "gargouille_small.ppm"
 
  ppm_write_to_file(imSmall, "gargouille_small.ppm");
 

  // Free the not yet freed images
  delete(im->data);
  delete(im);
  delete(imSmall->data);
  delete(imSmall);

  return 0;
}




































