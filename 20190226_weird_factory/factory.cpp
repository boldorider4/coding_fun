#include "factory.h"
#include "context.h"
#include <fstream>


BaseReaderFactory::BaseReaderFactory(std::initializer_list<ModelIDs> ids)
{
    Context& pContext = Context::getInstance();
    for (ModelIDs id : ids) {
        pContext.registerReaderFactory(id, this);
    }
}


void BaseReader::setFileReader(FileReader *pFileReader) {
  pFileReader = pFileReader;
}


ModelIDs FileReader::getModelID(const char* pFileDoc) {
  /* read from file and determin modelID. For this demo, it's hardcoded */
  std::ifstream fd;
  fd.open(pFileDoc);

  /* read from file and determin modelID. For this demo, it's hardcoded to fooModelID*/  
  
  fd.close();
  return ModelIDs::FooModelID;
}


std::shared_ptr<BaseReader> FileReader::getNodeReader(ModelIDs id) {
    auto find = readerMap.find(id);
    
    if (find == readerMap.end()) {

      BaseReaderFactory *pNodeFactory = Context::getInstance().getNodeReaderFactory(id);

      if (pNodeFactory == nullptr) {
	return nullptr;
      }

      readerMap[id] = pNodeFactory->createModelReader(this);
    }

    return readerMap[id];
}
