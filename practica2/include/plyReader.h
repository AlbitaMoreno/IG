#ifndef PLYREADER_H
#define PLYREADER_H

#include "file_ply_stl.h"
#include "o3dr.h"

class PlyReader : public O3DR{
public:
    PlyReader();
    PlyReader(char *file);
};


#endif // PLY_READER_H