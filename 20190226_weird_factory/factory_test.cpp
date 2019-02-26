#include "factory.h"
#include "context.h"



/* This is a small program which opens a file in one of many possible formats and fills
   a list of nodes based on the file format detected.
   Here I enable Reader, ReaderFactory and Model class simply by declaring and binding
   them together by using macros MODEL_READER_HELPER, MAP_READER_TO_TYPES and
   INSTANTIATE_READER_FACTORY.

   Obviously one still needs to define the read function for this particular model class. 

   FooModelID is an ID that is used to detect in the file which type the list of nodes
   should have, and consequently which reader and reader factory should be used.

   supporting new formats becomes as easy as extending the enum class ModelIDs, declaring
   new Model, Reader and ReaderFactory classes for the specified format and, ultimately,
   writing a new read function. */

class FooModelReaderFactory;


struct FooModelNode : public BaseModelNode {
  int fooMember;
};


class FooModelReader : public BaseReader
{
  MODEL_READER_HELPER(FooModelReader)

public:
  std::list<BaseModelNode *> read();
};


MAP_READER_TO_TYPES(FooModelReader, ModelIDs::FooModelID)

INSTANTIATE_READER_FACTORY(FooModelReader);


std::list<BaseModelNode *> FooModelReader::read()
{
  /* instantiate new FooModelNode, fill it and return it */
  FooModelNode* pNode = new FooModelNode();

  /* read does nothing here, but it could read foo.txt somehow */
  char c = pFileReader->read();
  pNode->fooMember = static_cast<int>(c);
  c = pFileReader->read();
  pNode->fooMember |= static_cast<int>(c) << sizeof(char);
  c = pFileReader->read();
  pNode->fooMember |= static_cast<int>(c) << sizeof(char)*2;
  c = pFileReader->read();
  pNode->fooMember |= static_cast<int>(c) << sizeof(char)*3;
  
  return std::list<BaseModelNode *>({pNode});
}


int main() {
  /* instantiate a file reader */
  FileReader fr;

  /* detect file type (for instance from header) and determine
     proper model ID */
  ModelIDs properModelID = fr.getModelID("foo.txt");

  /* now that model reader is determined, getNodeReader will get the proper
     Reader type and the 'MAP_READER_TO_TYPES' mechanism will ensure that the
     factory already has a Reader type associated to this model ID*/
  std::shared_ptr<BaseReader> baseReader = fr.getNodeReader(properModelID);

  if (baseReader != nullptr) {
    /* read a list of nodes from file which will be of fooModelNode type */
    std::list<BaseModelNode *> nodeList = baseReader->read();
  }
    
  return 0;
}
