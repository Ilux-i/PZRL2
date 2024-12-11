#ifndef METHODS_h
#define METHODS_h

// void Read_file(char *file);

// void Write_file(char *message);

void Replace(char *file, const char *old_text, const char *new_text);

void Delete(char *file, const char *del_text);

void Insert(char *file, char flag, const char *insert_text);

#endif
