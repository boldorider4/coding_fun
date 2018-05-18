typedef unsigned char quint8;

enum class custom_char : quint8 {
    null_value = 0b0,
    first_value = 0b1,
    second_value = 0b10,
    third_value = 0b11
};

int takesCustomCharInDisguise(quint8 customChar);

int main() {

  custom_char someChar = custom_char::third_value;

  return takesCustomCharInDisguise(static_cast<quint8>(someChar));
}

int takesCustomCharInDisguise(quint8 customChar) {

  custom_char realCustomChar = static_cast<custom_char>(customChar);

  if (realCustomChar == custom_char::null_value) {
    return 0;
  } else if (realCustomChar == custom_char::first_value) {
    return 1;
  } else if (realCustomChar == custom_char::second_value) {
    return 2;
  } else if (realCustomChar == custom_char::third_value) {
    return 3;
  }

  return -1;
}
