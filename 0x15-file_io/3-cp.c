#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, one of the exit codes on failure
 */
int main(int argc, char *argv[]) {
  // Check and handle arguments
  if (handle_arguments(argc, argv) != 0) {
    return 97; // Exit with usage error code
  }

  // Open source file for reading
  int fd_from = open_file(argv[1], O_RDONLY);
  if (fd_from == -1) {
    error_and_exit("Error opening source file");
  }

  // Open destination file for writing (create and truncate)
  int fd_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXG | S_IRWXO);
  if (fd_to == -1) {
    close_file(fd_from); // Close first file before exiting
    error_and_exit("Error opening destination file");
  }

  // Copy data in chunks and handle errors
  if (copy_data(fd_from, fd_to) != 0) {
    close_files(fd_from, fd_to); // Close both files before exiting
    error_and_exit("Error copying data");
  }

  // Close file descriptors (already handled in copy_data if successful)
  close_files(fd_from, fd_to);

  return 0; // Exit with success code
}

// Implementation of helper functions:

int handle_arguments(int argc, char *argv[]) {
  // Check if there are exactly 3 arguments
  if (argc != 3) {
    dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
    return 1;
  }
  return 0;
}

int open_file(const char *filename, int flags) {
  // Open the file with error handling and return the file descriptor or -1
  int fd = open(filename, flags);
  if (fd == -1) {
    dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
  }
  return fd;
}

void error_and_exit(const char *message) {
  // Print the error message and exit with the specified code
  dprintf(STDERR_FILENO, "%s\n", message);
  exit(1);
}

int copy_data(int fd_from, int fd_to) {
  // Allocate a buffer for data
  char buffer[1024];

  // Read data in chunks, write to destination, and handle errors
  while (1) {
    int bytes_read = read(fd_from, buffer, 1024);
    if (bytes_read == -1) {
      dprintf(STDERR_FILENO, "Error: Can't read from file\n");
      return 1;
    } else if (bytes_read == 0) {
      break; // End of file reached
    }

    int bytes_written = write(fd_to, buffer, bytes_read);
    if (bytes_written != bytes_read) {
      dprintf(STDERR_FILENO, "Error: Can't write to file\n");
      return 1;
    }
  }

  return 0; // Success
}

void close_files(int fd_from, int fd_to) {
  // Close both files and handle errors
  if (close(fd_from) == -1) {
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
  }
  if (close(fd_to) == -1) {
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
  }
}

