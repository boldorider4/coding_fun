#ifndef ERROR_CODE_H
#define ERROR_CODE_H

enum class OccRetval {
  no_error = 0,
  file_is_not_open,
  file_reading_error,
  must_exit,
  unknown_error
};

#endif /* ERROR_CODE_H */
