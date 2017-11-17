#ifndef ERROR_CODE_H
#define ERROR_CODE_H

enum class occRetval : int {
  no_error = 0,
  file_is_not_open = 1,
  file_reading_error = 2,
  must_exit,
  unknown_error = 3
};

#endif /* ERROR_CODE_H */
