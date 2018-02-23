Hi Jack,

I received your e-mail regarding exercise 4. I'm a bit full this week but I'll try to make time to take a look at it. 
With this e-mail, I'll share the 5th and final exercise in the series "Mentoring Jack". Hope you like it.

=====

In this exercise, we'll be studying and applying another common design pattern in object-oriented
programming called the MVC pattern or Model-View-Controller pattern. When applied, this pattern 
allows us to abstract data from business logic and the combination of both from the view or output.

Such a pattern is commonly used in web development, game development and general software 
architectures where the same data must be available in multiple formats.

Consider this simple use-case:

A customer has a relational database with a few tables holding important data. Such data must be 
available to its clients in both Microsoft Excel Format (XLS) and in CSV. With this in mind, a 
developer can apply MVC the following way:

M (Model)
Design a collection of plain-data objects representing rows the in the relational database.
Example: if a table holds cars, then create a Car class where each field represents one column in
the table. Such fields (or columns) could be: brand, model, gas type, horse power, etc.
Additionally, design a few static functions that allow you to retrieve such data or perhaps a separate 
class, i.e., CarRepository with such functionality.

V (View)
Design an interface describing how one can serialize a Car instance to an output stream/file.
Example:

class CarWriter {
public:
  virtual ~CarWriter() = default;
  virtual void write(const Car& instance, ofstream& output) = 0;
};

After that, create two implementations, one for XLS serialization and another for CSV.
Examples: XlsCarWriter, CsvCarWriter.

C (Controller), the business logic and content negotiation layer
Given a request for an output representation (XLS or CSV), retrieve data from the database using
the Model abstraction. After that, instantiate the proper view and have it output the the car or
collection of cars in the appropriate format.

Example:

class CarController {
public:
  ...
  
  void onCarRequest(
      const std::string &format, 
      const std::string &brand,
      const std::string &file) {
      
    // Retrieve cars from model abstraction
    // "model" here can be an instance of Car or CarRepository
    vector<Car> cars = model.getCarsForBrand(brand);
    
    // Retrieve appropriate car writer (content negotiation)
    CarWriter writer = getCarWriterForFormat(format); // xls or csv
    
    // Open output file here
    
    for (const auto &car : cars) {
      writer.write(car, /* the output file stream */);
    }
    
    // Close output file here
  }
  
  ...
};

An architecture like this is easily extensible, since if you need more output formats, all you
need to do is create more writers. If you need to add extra entities, then extend the model 
abstraction, create new controllers and writers.

You'll notice in the above example that the content negotiation is done with a function called
`getCarWriterForFormat`. A common implementation for this would be:

CarWriter getCarWriterForFormat(const std::string& format) {
  if (format == "csv") return CsvCarWriter();
  if (format == "xls") return XlsCarWriter();
  throw "invalid format";
}

Although, if this function resides inside the Controller, then every time you need to add an 
additional output format, you will need to modify the controller. 
Can't we do better than that?

Of course we can, Factory Pattern to the rescue.

The factory pattern allows us to decouple the format from the appropriate writer which means that
we no longer will need to modify the controller for new formats. This pattern comes in many flavors
but one of the easiest ways to implement it is to use a static variation: the factory method 
pattern.

For this, we create a class/namespace with the only purpose of holding static functions capable
of creating objects.

Example (in plain C++):

namespace Factory {

  CarWriter getCarWriterForFormat(...);
  
  // ...
  SomeOtherWriter getWriterForSomeOtherEntity(...);
  
}

In the controller class, the line:
CarWriter writer = getCarWriterForFormat(format); // xls or csv
Changes to:
CarWriter writer = Factory::getCarWriterForFormat(format); // xls or csv

In this way, you successfully decoupled the controller from the writer implementation which means
that you can easily do incremental development in the future.

Now that you understand both MVC and the Factory patterns, it's time to apply your new skills by
building a simple application.

Occurrence Counter Remote Version
=================================

Reusing code from the previous exercises, we now want to build an occurrence counter that allows
any user on the same network to query for occurrences in files stored in a remote server. For this, 
we'd usually need to dive in to some socket programming, but fortunately, we can do it without sockets 
if we just follow the UNIX philosophy.

There's a neat utility called netcat, usually abbreviated to nc that allows us to roll our own
servers and clients.

For creating a server that listens for connections on port 1234, type:
$ nc -l -p 1234

For creating a client that sends commands to this server, type:
$ nc <ip-address> 1234

For the purposes of this exercise, <ip-address>=localhost
Try it out and you'll see that anything you type on the client, will show up in the server. We can take
advantage of this and redirect one process' input/output streams to netcat allowing us to receive 
requests and send replies.

Using any functionality you deem necessary, write an interactive occurrence counter and redirect it
to netcat. This new interactive occurrence counter should be written using the MVC style and using
the Factory Pattern, where applicable.

The idea is to be able to get the output results in two formats: JSON and XML, as such, a request for
a word search should also include this extra information.

Examples: 
$ s -o JSON myWord
$ s -o XML mySecondWord

Some implementation details are left out and you're encouraged to use your best judgement here.
Feel free to modify the available commands or add new ones.

Good luck!

If you have any questions, don't hesitate to ask, since this exercise is quite big but it touches a lot of
study material. Additionally, being able to use netcat to create this remote server is quite ingenious, I hope
you realize the applications of such an architecture (and also its disadvantages).

Best regards,
