#ifndef ERROR_CODE_H
#define ERROR_CODE_H


namespace occurrenceCounter {
  
  enum class OccRetval {
                        no_error = 0,
                        not_initialized,
                        file_is_not_open,
                        file_reading_error,
                        file_parsed,
                        word_parsed,
                        must_exit,
                        thread_error,
                        unknown_error
  };

}

#endif /* ERROR_CODE_H */
