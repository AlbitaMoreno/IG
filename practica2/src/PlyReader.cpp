#include "PlyReader.h"

using namespace std;

PlyReader::PlyReader(char *file)
{
    _file_ply archivo;
    archivo.open(file);
    archivo.read(Vertices, Triangles);
}
