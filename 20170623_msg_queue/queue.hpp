#include <string>
#include <iostream>
#include <cassert>

class Caller {
public:
  Caller() {std::cout << "Caller" << std::endl; }
};

std::ostream& operator<<(std::ostream& os, Caller cal)
{
  os << "Caller" << "\n";
  return os;
}

class Exp {
public:
  Exp() {std::cout << "Exp" << std::endl; }
};

class Entity1 : public Caller {
public:
  Entity1() {std::cout << "Entity1" << std::endl; }
};

class Entity2 : public Caller, Exp {
public:
  Entity2() {std::cout << "Entity2" << std::endl; }
};

typedef struct {
  std::string msg;
} Message;

class MsgHandler {
public:
  MsgHandler();
  void addMessage(Caller cal, Message msg);
  void updateMsgQueue();
  static void init() {head=0; tail=0;}

private:
  static const int MAX_QUEUE_SIZE = 64;
  static Message queue[MAX_QUEUE_SIZE];

  static int head;
  static int tail;
};

MsgHandler::MsgHandler()
{
}

void MsgHandler::addMessage(Caller cal, Message msg)
{
  //  assert((tail + 1) % MAX_QUEUE_SIZE != head);
  //  (tail+1) % MAX_QUEUE_SIZE;
}

void MsgHandler::updateMsgQueue()
{
  //  if (tail == head) return;
  //  (head+1) % MAX_QUEUE_SIZE;
}
