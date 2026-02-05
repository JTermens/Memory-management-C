#include "exercice.h"

void update_file(int filedata[200], int new_filetype, int new_num_lines) {

    // Index 1 is the number of lines
    filedata[1] = new_num_lines;

    // Index 2 is the filetype
    filedata[2] = new_filetype;

    // Index 199 mut be 0
    filedata[199] = 0;
}
