#ifndef SQLMAIN_HPP
#define SQLMAIN_HPP


#include <string>
#include <stdio.h>
#include <iostream>
#include <windows.h>

#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
// void run(int argc, char* argv[]);
void loadLibSQL();
void run();

void a();

#endif