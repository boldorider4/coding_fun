In this exercise, we want to build upon Exercise 3 and replace the manual cache updating mechanism
with an automated one.

More specifically, we want the user to be able to specify one file using the `f` option and have
this file be monitored for changes by our interactive occurrence counter for as long as the program
is running.

If the program detects a change in a file, then the internal cache should be updated and any 
subsequent searches should also reflect these changes.

For this, we'll be using make's mechanism for detecting changes: we'll compare the modification date
of the file with respect to the last modification date we know about. This must be done periodically,
as such, I suggest you create a separate thread for this and poll the file for changes every second,
or whichever period you feel is appropriate.
Remember you can have multiple files being monitored/watched.

The solution should use an object-oriented design and for this, we'll use what is called an 
Observer Design Pattern. The observer pattern is one of the most common ones in object-oriented
languages and they serve as an effective replacement for callbacks.

In an observer design, you usually have one or multiple producers with one or multiple observers.
The observers get notified by these producers, for example, every time they detect a change in a
file.

Here's a quick example of this design pattern in C++11 code:

class Observer {
public:
  virtual ~Observer() = default;
  virtual void onNumberGenerated(int number);
};

class Producer {
public:
  Producer() = default;
  ~Producer() = default;
  
  void addObserver(const Observer& observer);
  void removeObserver(const Observer& observer);
  
  void Start();
  void Stop();
  
private:
  std::set<Observer*>   _observers;
  std::thread           _thread;
  
  // Helpers
  void notifyObservers(int number);
};

The producer instatiates a thread that generates a new number every second and this number is
notified to the registered observers.

Please note that from the point that you have more than one thread per process, it's very easy
to run into concurrency problems, so make sure you analyze your code and protect critical 
sections appropriately.

Good luck!

Best regards,
