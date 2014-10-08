#pragma once
typedef struct {
    const long data_length;
    void* data;
} FileData;

FileData get_file_data(const char* path);
void release_file_data(const FileData* file_data);
