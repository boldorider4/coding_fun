#ifndef OBSERVER_H
#define OBSERVER_H


class Observer {
 public:
  Observer() = default;
  virtual ~Observer() = default;
  virtual void onNotification(int token);
};

#endif /* OBSERVER_H */
