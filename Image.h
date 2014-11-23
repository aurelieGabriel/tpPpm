

class Image
{

  //----------------------------------------------------------------------------
  //Attributs declarations
  //----------------------------------------------------------------------------

private:

  int height;
  int width;
  u_char * data;

//============================================================================
//                           Methodes declarations
//============================================================================

public:

  //--------------------------------------------------------------------------
  //Declaration of the constructors
  //--------------------------------------------------------------------------

  //the default constructor 
  Image(void);

  //the copy constructor
  Image(const Image & im);


  //--------------------------------------------------------------------------
  //Declaration of the getters and setters
  //--------------------------------------------------------------------------

  int GetWidth(void) const;
  int GetHeight(void) const;
  u_char* GetData(void) const;
  void SetIm(int w, int h, u_char * dat);
  void SetData();
  
  
  //--------------------------------------------------------------------------
  //Declaration of the destructor
  //--------------------------------------------------------------------------
  
  ~Image(void);
  
  //--------------------------------------------------------------------------
  //Other functions
  //--------------------------------------------------------------------------


  // Write the image contained in <data> (of size <width> * <height>)
  // into plain RGB ppm file <file>
  void ppm_write_to_file( const char * fileName);

  // Read the image contained in plain RGB ppm file <file>
  // into <data> and set <width> and <height> accordingly
  // Warning: data is malloc_ed, don't forget to free it
  void ppm_read_from_file( const char *  fileName);

  // Desaturate (transform to B&W) <image> (of size <width> * <height>)
  void ppm_desaturate();

  // Shrink image (of original size <width> * <height>) by factor <factor>
  // <width> and <height> are updated accordingly
  void ppm_shrink( int factor);

};
