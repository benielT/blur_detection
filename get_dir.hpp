#ifndef _GET_DIR_
#define _GET_DIR_

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getdir (string, vector<string> &);

#endif
