/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:10:51 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/28 20:58:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include  "header.h"

// Function to read the contents of a file into a dynamically allocated buffer
char *read_file(char *filename) {
    int fd;
    ssize_t bytes_read;
    char *buffer;
    size_t buffer_size = 1024;
    size_t total_size = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(STDERR_FILENO, "Failed to open file\n", 20);
        return NULL;
    }

    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        write(STDERR_FILENO, "Failed to allocate memory\n", 26);
        close(fd);
        return NULL;
    }

    while ((bytes_read = read(fd, buffer + total_size, buffer_size - total_size)) > 0) {
        total_size += bytes_read;
        if (total_size == buffer_size) {
            buffer_size *= 2;
            char *new_buffer = (char *)malloc(buffer_size);
            if (!new_buffer) {
                write(STDERR_FILENO, "Failed to reallocate memory\n", 28);
                free(buffer);
                close(fd);
                return NULL;
            }
            buffer = new_buffer;
        }
    }

    if (bytes_read < 0) {
        write(STDERR_FILENO, "Failed to read file\n", 20);
        free(buffer);
        close(fd);
        return NULL;
    }

    buffer[total_size] = '\0';
    close(fd);

    return buffer;
}

char *find_value_by_key(char *contents, char *key) {
    size_t key_len = 0;
    while (key[key_len] != '\0') {
        key_len++;
    }

    size_t line_end = 0;
    while (contents[line_end] != '\0') {
                // Find the start of a line
        size_t line_start = line_end;// Mark the beginning of the current line
                
                //Here we take the final position of each line        
        while (contents[line_end] != '\0' && contents[line_end] != '\n') {
            line_end++;
        }
        // Now, line_end is at the position of '\n' or '\0'
        
        // Find the separator ':'        
        size_t seperator = line_start;// Start from the beginning of the current line
        while (seperator < line_end && contents[seperator] != ':') {
            seperator++;
        }

        if (seperator < line_end) {
            // Check if the key matches
            size_t match = 1;
            size_t k = 0;
            while (k < key_len) 
            {
                if (key[k] !=  contents[line_start + k]) {
                    match = 0;
                    break;
                }
                k++;
            }
            if (match && (line_start + key_len) == seperator) {
                // Key matches, extract the value
                size_t value_start = seperator + 1;
                size_t value_len = line_end - value_start;

                char *value = (char *)malloc(value_len + 1);
                if (!value) {
                    write(1, "Failed to allocate memory\n", 26);
                    return NULL;
                }

                k = 0;
                while (k < value_len) 
                {
                    value[k] = contents[value_start + k];
                     k++;
                }
                value[value_len] = '\0';

                return value;
            }
        }

        // Move to the next line(skip the newline character if present)
        if (contents[line_end] == '\n') {
            line_end++;
        }
    }

    return NULL;
}

