#include "plyReader.h"

using namespace std;

PlyReader::PlyReader(char *file){
    _file_ply archiv;
    archiv.open(file);
    archiv.read(vertices, triangulos);
}
