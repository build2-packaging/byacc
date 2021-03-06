#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdio.h>
#include <fcntl.h>
#include <io.h>

FILE *mytmpfile ()
{
  char d[MAX_PATH + 1], p[MAX_PATH + 1];
  if (GetTempPathA (sizeof (d), d) == 0 ||
      GetTempFileNameA (d, "tmp", 0, p) == 0)
    return NULL;

  HANDLE h = CreateFileA (p,
                          GENERIC_READ | GENERIC_WRITE,
                          0,
                          NULL,
                          CREATE_ALWAYS,
                          FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE,
                          NULL);
  if (h == INVALID_HANDLE_VALUE)
    return NULL;

  int fd = _open_osfhandle ((intptr_t) h, _O_RDWR);
  if (fd == -1)
    return NULL;

  FILE *f = _fdopen (fd, "wb+");
  if (f == NULL)
    _close (fd);

  return f;
}
